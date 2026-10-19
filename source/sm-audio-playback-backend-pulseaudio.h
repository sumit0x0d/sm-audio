#ifndef SM_AUDIO_PLAYBACK_BACKEND_PULSEAUDIO_H
#define SM_AUDIO_PLAYBACK_BACKEND_PULSEAUDIO_H

#include <sm-audio-playback.h>

#include <pulse/pulseaudio.h>

typedef struct SM_Audio_Playback_Backend_PulseAudio {
   pa_mainloop *pa_mainloop;
   pa_context *pa_context;
   pa_stream *pa_stream;
   pa_operation *pa_operation;
} SM_Audio_Playback_Backend_PulseAudio;

SM_Audio_Playback_Backend_PulseAudio *sm_audio_playback_backend_pulseaudio_create(const SM_Audio_Playback_Create_Info *create_info);
void sm_audio_playback_backend_pulseaudio_destroy(SM_Audio_Playback_Backend_PulseAudio *this);

#endif
