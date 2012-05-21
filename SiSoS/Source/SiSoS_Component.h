/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  29 Apr 2012 12:06:24pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SISOSCOMPONENT_SISOSCOMPONENT_49E745E2__
#define __JUCER_HEADER_SISOSCOMPONENT_SISOSCOMPONENT_49E745E2__

//[Headers]

#include "../JuceLibraryCode/JuceHeader.h";
#include "SynthAudioSource.h";
#include "ADSRController.h";
class SynthAudioSource;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    Diese Klasse ist eine mit dem Jucer erstellte GUI-Komponente.
	Zusätzliche Logik wurde an den dafür vorgesehenen Stellen eingebaut, damit
	diese nicht vom Jucer überschrieben wird.
	Die Klasse stellt zusätzlich die Schnittstelle zum Model dar.

	@author Jana Bärenbold,
			Tobias Brog
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
    //[UserMethods]
		
		/* Momentan keine User-Methoden */
		
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   *************************************************************

	AudioDeviceManager& deviceManager; 					// Dient dazu, Zugriff auf die ausgewählten Geräte zu haben.
    MidiKeyboardState keyboardState; 					// Zur Überwachung des Keyboardstatus und zur Anzeige desselben auf dem Screen
    AudioSourcePlayer audioSourcePlayer; 				// Spielt die ihm übergebene AudioSource ab.
    ScopedPointer<SynthAudioSource> synthAudioSource;	// Scoped Pointer auf die AudioSource, verfällt mit dem Beenden.
	double volume; 										// TODO: Remove
	ADSRController* controller; 						// Der Controller für die Realtimeveränderung der ADSR-Parameter
	String text; 										// Der aus dem File ausgelesene Text.
	
    //[/UserVariables]   ************************************************************

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
    AudioDeviceSelectorComponent* selector;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    SiSoS_Component (const SiSoS_Component&);
    const SiSoS_Component& operator= (const SiSoS_Component&);
};


#endif   // __JUCER_HEADER_SISOSCOMPONENT_SISOSCOMPONENT_49E745E2__
