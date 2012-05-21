#include "SyneWaveVoice.h"
#include "SyneWaveSound.h"


SyneWaveVoice::SyneWaveVoice(double* volume_)
        : angleDelta (0.0),
          tailOff (0.0),
		  volume (volume_)
    {
    }

    bool SyneWaveVoice::canPlaySound (SynthesiserSound* sound)
    {
        return dynamic_cast <SyneWaveSound*> (sound) != 0;
    }

    void SyneWaveVoice::startNote (const int midiNoteNumber, const float velocity,
                    SynthesiserSound* /*sound*/, const int /*currentPitchWheelPosition*/)
    {
		currentAngle = 0.0;
        level = velocity * 0.15 * (*volume/100);
        tailOff = 0.0;
	
        double cyclesPerSecond = MidiMessage::getMidiNoteInHertz (midiNoteNumber);
        double cyclesPerSample = cyclesPerSecond / getSampleRate();

        angleDelta = cyclesPerSample * 2.0 * double_Pi;
    }

    void SyneWaveVoice::stopNote (const bool allowTailOff)
    {
		
        if (allowTailOff)
        {
            // start a tail-off by setting this flag. The render callback will pick up on
            // this and do a fade out, calling clearCurrentNote() when it's finished.

            if (tailOff == 0.0) // we only need to begin a tail-off if it's not already doing so - the
                                // stopNote method could be called more than once.
                tailOff = 1.0;
        }
        else
        {
            // we're being told to stop playing immediately, so reset everything..

            clearCurrentNote();
            angleDelta = 0.0;
        }
    }

    void SyneWaveVoice::pitchWheelMoved (const int /*newValue*/)
    {
        // wird für SiSoS nicht benötigt
    }
	
    void SyneWaveVoice::controllerMoved (const int /*controllerNumber*/, const int /*newValue*/)
    {
        // eventuell Controller hier einbinden
    }

    void SyneWaveVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
    {
        if (angleDelta != 0.0)
        {
            if (tailOff > 0)
            {
                while (--numSamples >= 0)
                {
                    const float currentSample = (float) (sin (currentAngle) * level * tailOff);

                    for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                        *outputBuffer.getSampleData (i, startSample) += currentSample;

                    currentAngle += angleDelta;
                    ++startSample;

                    tailOff *= 0.99;

                    if (tailOff <= 0.005)
                    {
                        clearCurrentNote();

                        angleDelta = 0.0;
                        break;
                    }
                }
            }
            else
            {
                while (--numSamples >= 0)
                {
                    const float currentSample = (float) (sin (currentAngle) * level);

                    for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                        *outputBuffer.getSampleData (i, startSample) += currentSample;

                    currentAngle += angleDelta;
                    ++startSample;
                }
            }
        }
    }



SyneWaveVoice::~SyneWaveVoice(void)
{
}

