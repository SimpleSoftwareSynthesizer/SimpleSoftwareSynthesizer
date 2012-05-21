#include "SynthAudioSource.h"
#include "SyneWaveVoice.h"
#include "SyneWaveSound.h"

SynthAudioSource::SynthAudioSource(MidiKeyboardState& keyboardState_, ADSRController* controller_)
        : keyboardState (keyboardState_),
		  controller(controller_)
    {

        // Der Synthesizer erhält 32 Voices --> Polyphonie
        for (int i = 32; --i >= 0;)
        {
			synth.addVoice(new SyneWaveVoice(controller));          
        }
		
        // Hier erhält der Synthesizer seinen Sinussound
        setUsingSineWaveSound();
    }

     void SynthAudioSource::setUsingSineWaveSound()
    {
        synth.clearSounds(); // Bereits existierende Sounds löschen.
        synth.addSound (new SyneWaveSound());
    }



SynthAudioSource::~SynthAudioSource(void)
{
}

void SynthAudioSource::prepareToPlay (int /*samplesPerBlockExpected*/, double sampleRate)
    {
        midiCollector.reset (sampleRate);

        synth.setCurrentPlaybackSampleRate (sampleRate);
    }

    void SynthAudioSource::releaseResources()
    {
    }

    void SynthAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
    {
        // Buffer zuerst löschen
        bufferToFill.clearActiveBufferRegion();

        // Den MIDI-Buffer mit den eingehenden Nachrichten füllen.
        MidiBuffer incomingMidi;
        midiCollector.removeNextBlockOfMessages (incomingMidi, bufferToFill.numSamples);

		
		//	Die oben abgefüllten Nachrichten werden dem keyboardState-Objekt übergeben. So
		//	werden auf dem Bildschirm die auf dem Keyboard gedrückten Noten angezeigt.
        keyboardState.processNextMidiBuffer (incomingMidi, 0, bufferToFill.numSamples, true);

        // Der Synthesiser verarbeitet den Input und generiert den Output.
        synth.renderNextBlock (*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
    }

