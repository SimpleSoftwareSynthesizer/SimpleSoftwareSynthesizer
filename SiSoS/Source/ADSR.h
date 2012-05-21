#pragma once
#include "ADSRController.h";

/*
	Modelliert die ADSR-Kurve. Der Code einer STK-Frameworkklasse
	wurde hierzu an SiSoS angepasst. TODO: Link

	@author Tobias Brog,
			Jana B�renbold
*/

class ADSR
{
public:
	ADSR(ADSRController* controller_);
	~ADSR(void);
	
	/*
		Dient zur Verwaltung der Zust�nder der ADSR-Kurve
	*/
	enum {
		ATTACK,
		DECAY,
		SUSTAIN,
		RELEASE,
		IDLE // Nach Release, vor ATTACK
	};

	/*
		Wird bei jedem sample erneut aufgerufen und gibt den aktuellen
		Levelwert zur�ck. Inline f�r Performancegewinn.
	*/
	inline double ADSR::tick( void )
	{
	  double rate; // Platzhalter f�r den Wert der Zu- oder Abnahme
	  switch ( state_ ) {

	  case ATTACK:
		if (attackRate_ == 1) {
			value = 1.0;
		} else {
			value += 0.01/attackRate_;
		}
		
		if ( value >= target ) {
			value = target;
			sustainLevel_ = target * (controller->getSustainRate()/127); //Neues Ziel: Das Sustainlevel.
			state_ = DECAY;
		}
		break;
	  
	  case DECAY:
		rate = 0.01/(controller->getDecayRate());

		if ( value > sustainLevel_ ) {
		  value -= rate;
		  if ( value <= sustainLevel_ ) {
			value = sustainLevel_;
			state_ = SUSTAIN;
		  }
		}
		else {
		  value += rate; // attack target < sustain level
		  if ( value >= sustainLevel_ ) {
			value = sustainLevel_;
			state_ = SUSTAIN;
		  }
		}
		break;
		
	  case SUSTAIN:
		  sustainLevel_ = target * (controller->getSustainRate()/127); // �berpr�fe das Sustainlevel (Realtimever�nderungen)
		  value = sustainLevel_;
		  break;

	  case RELEASE:
		  rate = controller->getReleaseRate();
		if (rate < 127 && rate > 0) {
		  value -= 0.08/rate;
		}
		if ( value <= 0.0 || rate == 0) {
		  value = 0.0;
		  state_ = IDLE;
		}
	  }

	  return value;
	}

	/*
		Wird aufgerufen, wenn eine Taste gedr�ckt wurde.
	*/
	void keyOn(double target);

	/*
		Wird beim Loslassen einer Taste aufgerufen.
	*/
	void keyOff();

	/*
		Gibt den aktuellen Status der Kurve zur�ck.
	*/
	int getState();

private:
	ADSRController* controller; // Der Controller bei welchem die Werte durch Aufrufe des GUI ver�ndert werden.
	int state_;
	double sustainLevel_;
	double attackRate_;
	double value;
	double target;

};

