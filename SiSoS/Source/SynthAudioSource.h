#pragma once
#include  "../JuceLibraryCode/JuceHeader.h";
#include "ADSRController.h";
/*
	Diese Klasse streamt das erzeugte Audiomaterial auf den Output

	@author Jana B�renbold,
			Tobias Brog
*/

class SynthAudioSource :
	public AudioSource
{
public:
	SynthAudioSource (MidiKeyboardState& keyboardState_, ADSRController* controller_);
	~SynthAudioSource(void);

	/* Der Synthesiser wird direkt vom JUCE-Framework �bernommen.*/
	Synthesiser synth;

	/* Sammelt real-time MIDI-Nachrichten */
    MidiMessageCollector midiCollector;

    /* Der Keyboardstatus des MIDIKeyboard-Komponenten */
    MidiKeyboardState& keyboardState;

	/* Weist den Sinussound zu */
	void setUsingSineWaveSound();

	void prepareToPlay (int /*samplesPerBlockExpected*/, double sampleRate);

	void releaseResources();

	/* F�llt den n�chsten Block Daten in den angegebenen Buffer */
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);

private:
	ADSRController* controller; // Pointer auf den ADSRController.
};

