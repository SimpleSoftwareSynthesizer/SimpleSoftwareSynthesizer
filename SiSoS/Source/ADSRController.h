#pragma once
/*
 Diese Klasse vermittelt zwischen der tatsächlichen ADSR-Klasse und dem GUI.
 
*/

class ADSRController
{
public:
	ADSRController(void);
	~ADSRController(void);

	void setAttackRate(double rate);

	void setAttackTarget(double target);

	void setDecayRate(double rate);

	void setSustainRate(double rate);

	void setReleaseRate(double rate);

	double getAttackRate();

	double getDecayRate();

	double getSustainRate();

	double getReleaseRate();

	double getTarget();

private:
	double attack,
			decay,
			sustain,
			release,
			target; // In diesem Fall immer 1.0
};

