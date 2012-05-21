#pragma once
#include  "../JuceLibraryCode/JuceHeader.h";

/*
	Diese Klasse streamt das erzeugte Audiomaterial auf den Ausgang.


*/

class SynthAudioSource :
	public AudioSource
{
public:
	SynthAudioSource (MidiKeyboardState& keyboardState_, double* volume);
	~SynthAudioSource(void);

	/* Der Synthesiser */
	Synthesiser synth;

	/* Sammelt real-time MIDI-Nachrichten */
    MidiMessageCollector midiCollector;

    /* Der Keyboardstatus des MIDIKeyboard-Komponenten */
    MidiKeyboardState& keyboardState;


	void setUsingSineWaveSound();

	void prepareToPlay (int /*samplesPerBlockExpected*/, double sampleRate);

	void releaseResources();

	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);

private:
	double* volume;
};

