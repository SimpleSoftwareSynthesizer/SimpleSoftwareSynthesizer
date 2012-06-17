#include "SyneWaveVoice.h"
#include "SyneWaveSound.h"


SyneWaveVoice::SyneWaveVoice(ADSRController* controller_)
        : angleDelta (0.0),
          tailOff (0.0),
		  adsr(controller_)
    {
    }

    bool SyneWaveVoice::canPlaySound (SynthesiserSound* sound)
    {
        return dynamic_cast <SyneWaveSound*> (sound) != 0; // True wenn der Cast klappt.
    }

    void SyneWaveVoice::startNote (const int midiNoteNumber, const float velocity,
                    SynthesiserSound* /*sound*/, const int /*currentPitchWheelPosition*/)
    {
		adsr.keyOn(velocity * 0.15); // Target der Kurve ist velocity*0.15
		currentAngle = 0.0; // Startwinkel ist 0
        level = 0.0;
		
		/*
		
			Aufgrund der gedr�ckten MIDI-Note werden hier die Zyklen pro Sekunde ausgerechnet.
            Danach wird ausgerechnet, wie viele Zyklen pro Symple f�r die gegenw�rtige Samplerate notwendig sind.
		
		*/
		
        double cyclesPerSecond = MidiMessage::getMidiNoteInHertz (midiNoteNumber);
        double cyclesPerSample = cyclesPerSecond / getSampleRate();

        
        angleDelta = cyclesPerSample * 2.0 * double_Pi;
    }

    void SyneWaveVoice::stopNote (const bool allowTailOff)
    {
		adsr.keyOff();
		if (adsr.getState() == 4) { // Wenn IDLE --> Setze Voice zur�ck
		clearCurrentNote();
        angleDelta = 0.0;
		}
    }

    void SyneWaveVoice::pitchWheelMoved (const int /*newValue*/)
    {
        // wird f�r SiSoS nicht ben�tigt
    }
	
    void SyneWaveVoice::controllerMoved (const int /*controllerNumber*/, const int /*newValue*/)
    {
        // Wird nicht ben�tigt
    }

    void SyneWaveVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
    {
		level = adsr.tick(); // N�chster tick der ADSR-Kurve

        if (angleDelta != 0.0)
        {
                while (--numSamples >= 0)
                {
					// Auszugebendes Sample berechnen.
                    const float currentSample = (float) (sin (currentAngle) * level );

                    for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                        *outputBuffer.getSampleData (i, startSample) += currentSample;

                    currentAngle += angleDelta;
                    ++startSample;

                    if (adsr.getState() == 4) // State == IDLE --> Voice zur�cksetzen.
                    {
                        clearCurrentNote();

                        angleDelta = 0.0;
                        break;
                    }
                }
            
        }
    }



SyneWaveVoice::~SyneWaveVoice(void)
{
}

