/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic outline for a simple desktop window.

  ==============================================================================
*/

#include "MainWindow.h"


//==============================================================================
MainAppWindow::MainAppWindow()
    : DocumentWindow ("Simple Software Synthesizer",
                      Colour (0xff1bd2ff),
                      DocumentWindow::allButtons
					  )
{
    centreWithSize (820, 510);
	setResizable(false, false);
    setVisible (true);
	sisComp = new SiSoS_Component(deviceManager);
	sisComp->setTopLeftPosition(10, 30);
	addAndMakeVisible(sisComp);

	deviceManager.initialise (2, 2, 0, true, String::empty, 0);
	
}

MainAppWindow::~MainAppWindow()
{
}

void MainAppWindow::closeButtonPressed()
{
    JUCEApplication::getInstance()->systemRequestedQuit();
}
