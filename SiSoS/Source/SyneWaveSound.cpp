#include "SyneWaveSound.h"


SyneWaveSound::SyneWaveSound()
{
}

bool SyneWaveSound::appliesToNote (const int /*midiNoteNumber*/)           { return true; } // Ist f�r alle Noten g�ltig.
bool SyneWaveSound::appliesToChannel (const int /*midiChannel*/)           { return true; } // Reagiert auf alle MIDI-Kan�le.

SyneWaveSound::~SyneWaveSound()
{
}
