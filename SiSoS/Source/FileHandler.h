#pragma once
#include  "../JuceLibraryCode/JuceHeader.h"

class FileHandler
{
public:
	FileHandler(void);
	~FileHandler(void);

private:
	File file;
	StringArray data;
};

