#ifndef SM_AUDIO_CAPTURE_PULSEAUDIO_H
#define SM_AUDIO_CAPTURE_PULSEAUDIO_H

#include <pulse/pulseaudio.h>

#include <sm-audio-capture.h>

typedef struct {
   pa_mainloop *pa_mainloop;
   pa_context *pa_context;
   pa_stream *pa_stream;
} SM_Audio_Capture_Pulseaudio;

extern SM_Audio_Capture_Interface audio_capture_interface_pulseaudio;

#endif
