# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
    LOCAL_ARM_MODE := arm
endif

LOCAL_MODULE := juce_jni
LOCAL_SRC_FILES := \
  ../../../Source/ControlPanel.cpp\
  ../../../Source/FaceCanvas.cpp\
  ../../../Source/Main.cpp\
  ../../../Source/MainComponent.cpp\
  ../../../Source/ReactiveGraphicsElement.cpp\
  ../../../Source/ReactiveRectangleElement.cpp\
  ../../../Source/ReactiveSplineElement.cpp\
  ../../../Source/TransformElement.cpp\
  ../../../Source/ImageElement.cpp\
  ../../../Source/PathElement.cpp\
  ../../../Source/LineElement.cpp\
  ../../../Source/PolygonElement.cpp\
  ../../../Source/TextElement.cpp\
  ../../../Source/GraphicsElement.cpp\
  ../../../Source/RectangleElement.cpp\
  ../../../Source/EllipseElement.cpp\
  ../../../Source/SplineElement.cpp\
  ../../../Source/GestureInterpretor.cpp\
  ../../../Source/TouchGestureEvent.cpp\
  ../../../JuceLibraryCode/BinaryData.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_audio_basics/juce_audio_basics.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_audio_devices/juce_audio_devices.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_audio_formats/juce_audio_formats.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_audio_processors/juce_audio_processors.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_audio_utils/juce_audio_utils.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_core/juce_core.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_cryptography/juce_cryptography.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_data_structures/juce_data_structures.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_events/juce_events.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_graphics/juce_graphics.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_gui_basics/juce_gui_basics.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_gui_extra/juce_gui_extra.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_opengl/juce_opengl.cpp\
  ../../../../Juce/JUCE-OSX/modules/juce_video/juce_video.cpp\

ifeq ($(NDK_DEBUG),1)
  LOCAL_CPPFLAGS += -fsigned-char -fexceptions -frtti -g -I "../../JuceLibraryCode" -I "../../../Juce/JUCE-OSX/modules" -O0 -std=c++11 -std=gnu++11 -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=10" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=com_yourcompany_faces_Faces" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"com/yourcompany/faces/Faces\" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000"
  LOCAL_LDLIBS := -llog -lGLESv2
  LOCAL_CFLAGS += -fsigned-char -fexceptions -frtti -g -I "../../JuceLibraryCode" -I "../../../Juce/JUCE-OSX/modules" -O0 -std=c++11 -std=gnu++11 -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=10" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=com_yourcompany_faces_Faces" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"com/yourcompany/faces/Faces\" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000"
  LOCAL_LDLIBS := -llog -lGLESv2
else
  LOCAL_CPPFLAGS += -fsigned-char -fexceptions -frtti -I "../../JuceLibraryCode" -I "../../../Juce/JUCE-OSX/modules" -O3 -std=c++11 -std=gnu++11 -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=10" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=com_yourcompany_faces_Faces" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"com/yourcompany/faces/Faces\" -D "NDEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000"
  LOCAL_LDLIBS := -llog -lGLESv2
  LOCAL_CFLAGS += -fsigned-char -fexceptions -frtti -I "../../JuceLibraryCode" -I "../../../Juce/JUCE-OSX/modules" -O3 -std=c++11 -std=gnu++11 -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=10" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=com_yourcompany_faces_Faces" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"com/yourcompany/faces/Faces\" -D "NDEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000"
  LOCAL_LDLIBS := -llog -lGLESv2
endif

include $(BUILD_SHARED_LIBRARY)
