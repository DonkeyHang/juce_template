
cmake_minimum_required (VERSION 3.18) 

project (NewProject VERSION 0.0.1 LANGUAGES CXX) 

#

set (NewProject_sourceDir ${CMAKE_CURRENT_LIST_DIR}/Source)  # This could conceivably be in a different place, but the source tree must be intact 

#

set (NewProject_sourceFiles
    ${NewProject_sourceDir}/PluginProcessor.cpp
    ${NewProject_sourceDir}/PluginProcessor.h
    ${NewProject_sourceDir}/PluginEditor.cpp
    ${NewProject_sourceDir}/PluginEditor.h)

#

set (NewProject_Bundle_ID com.BenViningMusicSoftware.Imogen)
set (NewProject_Manufacturer_Code Benv)
set (NewProject_Plugin_Code Nwpg)
set (NewProject_Description "New project")
set (NewProject_Is_Synth FALSE)
set (NewProject_Needs_MIDI_Input FALSE)
set (NewProject_Needs_MIDI_Output FALSE)
set (NewProject_Is_MIDI_Effect FALSE)
set (NewProject_Editor_Wants_Keyboard_Focus FALSE)
set (NewProject_VST3_Categories "")
set (NewProject_AU_Main_Type "")
set (NewProject_Company_Name BenViningMusicSoftware)
set (NewProject_Company_Website "www.benvining.com")
set (NewProject_Company_Email "ben.the.vining@gmail.com")
set (NewProject_Company_Copyright "This software is provided as-is, with no guarantee of completion or fitness for any particular purpose, by Ben Vining, under the terms and conditions of the GNU Public License.")
set (NewProject_Copy_Plugin_After_Build TRUE)

set (NewProject_UseRecommendedWarningFlags TRUE)
set (bv_generatePreprocessorDefinitions TRUE)

#

include (JUCE-CmakeWrapper/CMakeLists.txt)

#

juce_add_module (${PitchDetectorTester_sourceDir}/Shared-code/bv_SharedCode)

target_link_libraries (NewProject PRIVATE bv_SharedCode)

#

target_compile_features (NewProject PUBLIC cxx_std_17)

target_compile_definitions (NewProject PUBLIC 
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_STRICT_REFCOUNTEDPTR=1
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_MODAL_LOOPS_PERMITTED=0
    )

#

