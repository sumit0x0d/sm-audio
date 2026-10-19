#ifndef SM_AUDIO_CAPTURE_BACKEND_PULSEAUDIO_H
#define SM_AUDIO_CAPTURE_BACKEND_PULSEAUDIO_H

#include <pulse/pulseaudio.h>

#include <sm-audio-capture.h>

typedef struct {
   pa_mainloop *pa_mainloop;
   pa_context *pa_context;
   pa_stream *pa_stream;
} SM_Audio_Capture_Backend_PulseAudio;

SM_Audio_Capture_Backend_PulseAudio *sm_audio_capture_backend_pulseaudio_create(const SM_Audio_Capture_Create_Info *create_info);
void sm_audio_capture_backend_pulseaudio_destroy(SM_Audio_Capture_Backend_PulseAudio *this);

#endif
