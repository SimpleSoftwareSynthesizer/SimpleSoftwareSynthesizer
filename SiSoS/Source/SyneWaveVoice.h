
#include "../JuceLibraryCode/JuceHeader.h";
#include "ADSR.h";
#include "ADSRController.h";

/*
	Klasse welche SyneWaveSounds spielen kann. Wird von
	SynthesiserVoice abgeleitet.
	
	@author Jana Bärenbold,
			Tobias Brog
*/
class SyneWaveVoice :
	public SynthesiserVoice
{
public:
	SyneWaveVoice(ADSRController* controller_);
	~SyneWaveVoice(void);

	/*
		Aufgerufen, wenn eine Taste gedrückt wurde.
	*/
	void startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*momentane Pitchwheelposition*/);

	/*
		Gibt True zurück, wenn ein übergebener Sound von der Voice gespielt werden kann.
	*/
	bool canPlaySound (SynthesiserSound* sound);

	/*
		Aufgerufen, wenn eine Taste losgelassen wird.
		TODO: Entferne allowTailOff
	*/
	void stopNote (const bool allowTailOff);

	/*
		Aufgerufen, wenn das Pitchwheel betätigt wird. Für SiSoS momentan irrelevant.
	*/
	void pitchWheelMoved (const int /*neuerWert*/);

	/*
		Aufgerufen, wenn ein Controller bewegt wurde. Momentan nicht verwendet.
	*/
	void controllerMoved (const int /*controllerNummer*/, const int /*neuerWert*/);

	/*
		Wird aufgerufen, wenn der Synthesiser seine Voices spielt. Hier findet der Kern der Klangerzeugung statt
	*/
	void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);

private:
    double currentAngle, // Gegenwärtiger Winkel
		   angleDelta, // Winkelverschiebung
		   level, // Lautstärke
		   tailOff; // REMOVE
	ADSR adsr; /* Das Modell der ADSR-Kurve. Jede Voice benötigt ihre eigene unabhängige Kurve. */
};

