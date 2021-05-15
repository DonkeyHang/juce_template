
#include "PluginProcessor.h"
#include "PluginEditor.h"


NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (AudioFifoTesterAudioProcessor& p):
    AudioProcessorEditor (&p), audioProcessor (p)
{
    this->setBufferedToImage(true);
    setSize (400, 300);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
    this->setLookAndFeel(nullptr);
}

void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}


void NewProjectAudioProcessorEditor::resized()
{
    
}
