
#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
#include "PluginProcessor.h"



class NewProjectAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    
    NewProjectAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};
