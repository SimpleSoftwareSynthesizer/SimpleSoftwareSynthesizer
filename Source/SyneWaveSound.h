
#include  "../JuceLibraryCode/JuceHeader.h";

class SyneWaveSound :
	public SynthesiserSound
{
public:
	SyneWaveSound();
	~SyneWaveSound();

	bool appliesToNote (const int /*midiNoteNumber*/);          
	bool appliesToChannel (const int /*midiChannel*/);           
};

