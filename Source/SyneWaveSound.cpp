#include "SyneWaveSound.h"


SyneWaveSound::SyneWaveSound()
{
}

bool SyneWaveSound::appliesToNote (const int /*midiNoteNumber*/)           { return true; }
bool SyneWaveSound::appliesToChannel (const int /*midiChannel*/)           { return true; }

SyneWaveSound::~SyneWaveSound()
{
}
