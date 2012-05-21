#include "SyneWaveSound.h"


SyneWaveSound::SyneWaveSound()
{
}

bool SyneWaveSound::appliesToNote (const int /*midiNoteNumber*/)           { return true; } // Ist für alle Noten gültig.
bool SyneWaveSound::appliesToChannel (const int /*midiChannel*/)           { return true; } // Reagiert auf alle MIDI-Kanäle.

SyneWaveSound::~SyneWaveSound()
{
}
