LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := app
LOCAL_CFLAGS    := -Wall -Wextra
LOCAL_SRC_FILES :== native-lib.cpp
LOCAL_LDLIBS := -lGLESv2

include $(BUILD_SHARED_LIBRARY)