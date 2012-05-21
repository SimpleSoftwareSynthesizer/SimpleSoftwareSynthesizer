/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  25 Apr 2012 9:09:50pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SISOSCOMPONENT_SISOSCOMPONENT_AA2775B0__
#define __JUCER_HEADER_SISOSCOMPONENT_SISOSCOMPONENT_AA2775B0__

//[Headers]     -- You can add your own extra header files here --
// NOTE: Das ist eigentlich alles, was es braucht, um die mit Jucer erstellten
// Files zum Laufen zu bringen.
#include "../JuceLibraryCode/JuceHeader.h";
#include "SynthAudioSource.h";
class SynthAudioSource;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    Diese Klasse ist eine mit dem Jucer erstellte GUI-Komponente.
	Sie stellt zusätzlich die Schnittstelle zum Model dar.
                                                                    //[/Comments]
*/
class SiSoS_Component  : public Component,
                         public SliderListener,
                         public ButtonListener
{
public:
    //==============================================================================
    SiSoS_Component (AudioDeviceManager& deviceManager_);
    ~SiSoS_Component();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	
	AudioDeviceManager& deviceManager;
    MidiKeyboardState keyboardState;
    AudioSourcePlayer audioSourcePlayer;
    ScopedPointer<SynthAudioSource> synthAudioSource;
	double volume; // Volume der Audioausgabe, welches über Zeiger referenziert wird.
    //[/UserVariables]

    //==============================================================================
    Slider* slider;
    Label* label;
    Slider* slider2;
    Slider* slider3;
    Slider* slider4;
    Label* label2;
    Label* label3;
    Label* label4;
    TextButton* textButton;
    TextButton* textButton2;
    Label* label5;
    Slider* slider5;
    Label* label6;
    MidiKeyboardComponent* component;
	AudioDeviceSelectorComponent* deviceSelector;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    SiSoS_Component (const SiSoS_Component&);
    const SiSoS_Component& operator= (const SiSoS_Component&);
};


#endif   // __JUCER_HEADER_SISOSCOMPONENT_SISOSCOMPONENT_AA2775B0__
