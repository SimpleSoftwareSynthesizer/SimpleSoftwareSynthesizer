
#include  "../JuceLibraryCode/JuceHeader.h";

class SyneWaveVoice :
	public SynthesiserVoice
{
public:
	SyneWaveVoice(double* volume);
	~SyneWaveVoice(void);

	void startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*momentane Pitchwheelposition*/);

	bool canPlaySound (SynthesiserSound* sound);

	void stopNote (const bool allowTailOff);

	void pitchWheelMoved (const int /*neuerWert*/);

	void controllerMoved (const int /*controllerNummer*/, const int /*neuerWert*/);

	void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);

private:
    double currentAngle, angleDelta, level, tailOff;
	double* volume;
};

