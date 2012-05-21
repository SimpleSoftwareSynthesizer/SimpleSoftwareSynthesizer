
#include  "../JuceLibraryCode/JuceHeader.h";
/*
	Soundklasse, von SynthesiserSound abgeleitet, die selber nicht allzu viel Logik beinhaltet.
	Wird benötigt, damit die Voices einen Sound zur Verfügung haben.
	
	@author Jana Bärenbold,
			Tobias Brog
*/
class SyneWaveSound :
	public SynthesiserSound
{
public:
	SyneWaveSound();
	~SyneWaveSound();

	/*
		Gibt True zurück, wenn der Sound für eine Note wiedergegeben werden kann.
	*/
	bool appliesToNote (const int /*midiNoteNumber*/); 
	
	/*
		Gibt True zurück, wenn der Sound für einen MIDI-Kanal bestimmt ist.
	*/
	bool appliesToChannel (const int /*midiChannel*/);           
};

