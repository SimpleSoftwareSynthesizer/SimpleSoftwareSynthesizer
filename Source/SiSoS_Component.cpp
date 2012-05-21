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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "SiSoS_Component.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SiSoS_Component::SiSoS_Component (AudioDeviceManager& deviceManager_)
    : deviceManager (deviceManager_),
	  slider (0),
      label (0),
      slider2 (0),
      slider3 (0),
      slider4 (0),
      label2 (0),
      label3 (0),
      label4 (0),
      textButton (0),
      textButton2 (0),
      label5 (0),
      slider5 (0),
      label6 (0),
      component (0)
{
    addAndMakeVisible (slider = new Slider (L"Attack_Slider"));
    slider->setTooltip (L"Attack");
    slider->setRange (0, 127, 1);
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider->setColour (Slider::backgroundColourId, Colour (0x8a0f0f));
    slider->setColour (Slider::trackColourId, Colour (0x7f3fd9ff));
    slider->setColour (Slider::rotarySliderFillColourId, Colour (0xff004040));
    slider->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    slider->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    slider->addListener (this);

    addAndMakeVisible (label = new Label (L"Attack_Label",
                                          L"Attack"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slider2 = new Slider (L"Decay_Slider"));
    slider2->setTooltip (L"Attack");
    slider2->setRange (0, 127, 1);
    slider2->setSliderStyle (Slider::RotaryVerticalDrag);
    slider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider2->setColour (Slider::backgroundColourId, Colour (0x8a0f0f));
    slider2->setColour (Slider::trackColourId, Colour (0x7f3fd9ff));
    slider2->setColour (Slider::rotarySliderFillColourId, Colour (0xff004040));
    slider2->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    slider2->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    slider2->addListener (this);

    addAndMakeVisible (slider3 = new Slider (L"Sustain_Slider"));
    slider3->setTooltip (L"Attack");
    slider3->setRange (0, 127, 1);
    slider3->setSliderStyle (Slider::RotaryVerticalDrag);
    slider3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider3->setColour (Slider::backgroundColourId, Colour (0x8a0f0f));
    slider3->setColour (Slider::trackColourId, Colour (0x7f3fd9ff));
    slider3->setColour (Slider::rotarySliderFillColourId, Colour (0xff004040));
    slider3->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    slider3->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    slider3->addListener (this);

    addAndMakeVisible (slider4 = new Slider (L"Release_Slider"));
    slider4->setTooltip (L"Attack");
    slider4->setRange (0, 127, 1);
    slider4->setSliderStyle (Slider::RotaryVerticalDrag);
    slider4->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider4->setColour (Slider::backgroundColourId, Colour (0x8a0f0f));
    slider4->setColour (Slider::trackColourId, Colour (0x7f3fd9ff));
    slider4->setColour (Slider::rotarySliderFillColourId, Colour (0xff004040));
    slider4->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    slider4->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    slider4->addListener (this);

    addAndMakeVisible (label2 = new Label (L"Decay_Label",
                                           L"Decay"));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label3 = new Label (L"Sustain_Label",
                                           L"Sustain"));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label4 = new Label (L"Release_Label",
                                           L"Release"));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (textButton = new TextButton (L"Load_Button"));
    textButton->setTooltip (L"Load file");
    textButton->setButtonText (L"Load");
    textButton->setConnectedEdges (Button::ConnectedOnRight);
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colours::white);

    addAndMakeVisible (textButton2 = new TextButton (L"Save_Button"));
    textButton2->setTooltip (L"Save file");
    textButton2->setButtonText (L"Save");
    textButton2->setConnectedEdges (Button::ConnectedOnLeft);
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colours::white);

    addAndMakeVisible (label5 = new Label (L"Config_Label",
                                           L"MyConfig"));
    label5->setFont (Font (L"Aharoni", 25.2000f, Font::plain));
    label5->setJustificationType (Justification::topLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colour (0x50003d59));
    label5->setColour (Label::textColourId, Colours::white);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slider5 = new Slider (L"Volume_Slider"));
    slider5->setTooltip (L"Volume");
    slider5->setRange (0, 100, 1);
    slider5->setSliderStyle (Slider::LinearHorizontal);
    slider5->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider5->addListener (this);

    addAndMakeVisible (label6 = new Label (L"Volume_Label",
                                           L"Volume"));
    label6->setFont (Font (15.0000f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colours::black);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    


    //[UserPreSize]
	addAndMakeVisible (component = new MidiKeyboardComponent(keyboardState, MidiKeyboardComponent::horizontalKeyboard));
	addAndMakeVisible (deviceSelector = new AudioDeviceSelectorComponent (deviceManager, 0, 2, 0, 2, true, true, true, false));
    component->setName (L"new component");
    //[/UserPreSize]

    setSize (600, 600);


    //[Constructor] You can add your own custom stuff here..
	
    synthAudioSource = new SynthAudioSource (keyboardState, &volume);
    audioSourcePlayer.setSource (synthAudioSource);
	volume = 100;
    deviceManager.addAudioCallback (&audioSourcePlayer);
    deviceManager.addMidiInputCallback (String::empty, &(synthAudioSource->midiCollector));
    //[/Constructor]
}

SiSoS_Component::~SiSoS_Component()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	audioSourcePlayer.setSource (0);
    deviceManager.removeMidiInputCallback (String::empty, &(synthAudioSource->midiCollector));
    deviceManager.removeAudioCallback (&audioSourcePlayer);
    //[/Destructor_pre]

    deleteAndZero (slider);
    deleteAndZero (label);
    deleteAndZero (slider2);
    deleteAndZero (slider3);
    deleteAndZero (slider4);
    deleteAndZero (label2);
    deleteAndZero (label3);
    deleteAndZero (label4);
    deleteAndZero (textButton);
    deleteAndZero (textButton2);
    deleteAndZero (label5);
    deleteAndZero (slider5);
    deleteAndZero (label6);
    deleteAndZero (component);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SiSoS_Component::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1bd2ff));

    g.setColour (Colours::white);
    g.fillRect (8, 75, 584, 172);

    g.setColour (Colours::white);
    g.fillRect (8, 280, 584, 40);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SiSoS_Component::resized()
{
    slider->setBounds (96, 96, 184, 48);
    label->setBounds (16, 108, 64, 24);
    slider2->setBounds (96, 160, 184, 48);
    slider3->setBounds (400, 96, 184, 48);
    slider4->setBounds (400, 160, 184, 48);
    label2->setBounds (16, 171, 64, 24);
    label3->setBounds (320, 108, 64, 24);
    label4->setBounds (320, 173, 64, 24);
    textButton->setBounds (24, 288, 64, 24);
    textButton2->setBounds (88, 288, 64, 24);
    label5->setBounds (8, 48, 584, 27);
    slider5->setBounds (328, 288, 262, 24);
    label6->setBounds (256, 288, 64, 24);
    component->setBounds (8, 328, 584, 104);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SiSoS_Component::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
		
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
        //[/UserSliderCode_slider3]
    }
    else if (sliderThatWasMoved == slider4)
    {
        //[UserSliderCode_slider4] -- add your slider handling code here..
		
        //[/UserSliderCode_slider4]
    }
    else if (sliderThatWasMoved == slider5)
    {
        //[UserSliderCode_slider5] -- add your slider handling code here..
		//volume = slider5->getValue();
		audioSourcePlayer.setGain( slider5->getValue());
        //[/UserSliderCode_slider5]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SiSoS_Component::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..

		FileChooser chooser ("Choose file to open");
	if (chooser.browseForFileToOpen()) {

	} else { }
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SiSoS_Component" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="600" initialHeight="600">
  <BACKGROUND backgroundColour="ff1bd2ff">
    <RECT pos="8 75 584 172" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="8 280 584 40" fill="solid: ffffffff" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Attack_Slider" id="6fd910897a6d3a0b" memberName="slider"
          virtualName="" explicitFocusOrder="0" pos="96 96 184 48" tooltip="Attack"
          bkgcol="8a0f0f" trackcol="7f3fd9ff" rotarysliderfill="ff004040"
          rotaryslideroutline="ff000000" textboxbkgd="ffffffff" min="0"
          max="127" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Attack_Label" id="41df6299e45a7b2b" memberName="label"
         virtualName="" explicitFocusOrder="0" pos="16 108 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="Decay_Slider" id="e2507b952d7bc936" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="96 160 184 48" tooltip="Attack"
          bkgcol="8a0f0f" trackcol="7f3fd9ff" rotarysliderfill="ff004040"
          rotaryslideroutline="ff000000" textboxbkgd="ffffffff" min="0"
          max="127" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Sustain_Slider" id="e0ceb180d680dc2d" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="400 96 184 48" tooltip="Attack"
          bkgcol="8a0f0f" trackcol="7f3fd9ff" rotarysliderfill="ff004040"
          rotaryslideroutline="ff000000" textboxbkgd="ffffffff" min="0"
          max="127" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Release_Slider" id="539789cf3880e6b9" memberName="slider4"
          virtualName="" explicitFocusOrder="0" pos="400 160 184 48" tooltip="Attack"
          bkgcol="8a0f0f" trackcol="7f3fd9ff" rotarysliderfill="ff004040"
          rotaryslideroutline="ff000000" textboxbkgd="ffffffff" min="0"
          max="127" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Decay_Label" id="7f9ab33fedc7fc69" memberName="label2"
         virtualName="" explicitFocusOrder="0" pos="16 171 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Sustain_Label" id="835051a611e243d0" memberName="label3"
         virtualName="" explicitFocusOrder="0" pos="320 108 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Release_Label" id="98f40d34e4bb9c2a" memberName="label4"
         virtualName="" explicitFocusOrder="0" pos="320 173 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Load_Button" id="b5a448d9bc22b3a4" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="24 288 64 24" tooltip="Load file"
              bgColOff="ffffffff" buttonText="Load" connectedEdges="2" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Save_Button" id="ef943c659338f22a" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="88 288 64 24" tooltip="Save file"
              bgColOff="ffffffff" buttonText="Save" connectedEdges="1" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="Config_Label" id="a00d8347bca332b5" memberName="label5"
         virtualName="" explicitFocusOrder="0" pos="8 48 584 27" bkgCol="50003d59"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText="MyConfig"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Aharoni" fontsize="25.2" bold="0" italic="0" justification="9"/>
  <SLIDER name="Volume_Slider" id="ea2c0f92f6c95aff" memberName="slider5"
          virtualName="" explicitFocusOrder="0" pos="328 288 262 24" tooltip="Volume"
          min="0" max="100" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Volume_Label" id="5c2369a975f57010" memberName="label6"
         virtualName="" explicitFocusOrder="0" pos="256 288 64 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Volume" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="new component" id="b54de0be00f9dd3c" memberName="component"
                    virtualName="" explicitFocusOrder="0" pos="8 328 584 104" class="MidiKeyboardComponent"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
