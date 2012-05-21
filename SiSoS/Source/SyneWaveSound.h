
#include  "../JuceLibraryCode/JuceHeader.h";
/*
	Soundklasse, von SynthesiserSound abgeleitet, die selber nicht allzu viel Logik beinhaltet.
	Wird ben�tigt, damit die Voices einen Sound zur Verf�gung haben.
	
	@author Jana B�renbold,
			Tobias Brog
*/
class SyneWaveSound :
	public SynthesiserSound
{
public:
	SyneWaveSound();
	~SyneWaveSound();

	/*
		Gibt True zur�ck, wenn der Sound f�r eine Note wiedergegeben werden kann.
	*/
	bool appliesToNote (const int /*midiNoteNumber*/); 
	
	/*
		Gibt True zur�ck, wenn der Sound f�r einen MIDI-Kanal bestimmt ist.
	*/
	bool appliesToChannel (const int /*midiChannel*/);           
};

