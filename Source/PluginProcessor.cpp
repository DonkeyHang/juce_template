
#include "PluginProcessor.h"
#include "PluginEditor.h"


NewProjectAudioProcessor::NewProjectAudioProcessor():
    AudioProcessor (BusesProperties()
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
}


void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused (sampleRate, samplesPerBlock);
}


void NewProjectAudioProcessor::releaseResources()
{
    
}


void NewProjectAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::AudioBuffer<float> input  = getBusBuffer (buffer, true, 0);
    juce::AudioBuffer<float> output = getBusBuffer (buffer, false, 0);
    
    juce::ignoreUnused (midiMessages);
}



void NewProjectAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    juce::ignoreUnused (destData);
}


void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    juce::ignoreUnused (data, sizeInBytes);
}



bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainInputChannelSet() == juce::AudioChannelSet::disabled())
        return false;
    
    if (layouts.getMainInputChannelSet() != layouts.getMainOutputChannelSet())
        return false;
    
    return true;
}


int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
    juce::ignoreUnused (index);
}

const juce::String NewProjectAudioProcessor::getProgramName (int index)
{
    juce::ignoreUnused (index);
    return {};
}

void NewProjectAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
    juce::ignoreUnused (index, newName);
}



const juce::String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
    return false;
}

bool NewProjectAudioProcessor::producesMidi() const
{
    return false;
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
    return false;
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}


bool NewProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}


juce::AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
    return new NewProjectAudioProcessorEditor (*this);
}

// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}
