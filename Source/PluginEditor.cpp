/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
IRLoaderAudioProcessorEditor::IRLoaderAudioProcessorEditor (IRLoaderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(loadBtn);
    loadBtn.setButtonText("Load IR");
    loadBtn.onClick = [this]()
    {
        fileChooser = std::make_unique<juce::FileChooser>("Choose File",
                                                           audioProcessor.root,
                                                           "*");

        const auto fileChooserFlags = juce::FileBrowserComponent::openMode |
            juce::FileBrowserComponent::canSelectFiles |
            juce::FileBrowserComponent::canSelectDirectories;

        fileChooser->launch
    };
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);
}

IRLoaderAudioProcessorEditor::~IRLoaderAudioProcessorEditor()
{
}

//==============================================================================
void IRLoaderAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void IRLoaderAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    const auto btnX = getWidth() * 0.35;//JUCE_LIVE_CONSTANT(0.25);
    const auto btnY = getHeight() * 0.5;//JUCE_LIVE_CONSTANT(0.25);
    const auto btnWidth = getWidth() * 0.15;//JUCE_LIVE_CONSTANT(0.1);
    const auto btnHeight = btnWidth * 0.8;


    loadBtn.setBounds(btnX, btnY, btnWidth, btnHeight); 

}
