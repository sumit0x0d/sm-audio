#ifndef SM_AUDIO_CAPTURE_BACKEND_ALSA_H
#define SM_AUDIO_CAPTURE_BACKEND_ALSA_H

#include <sm-audio-capture.h>

#include <alsa/asoundlib.h>

typedef struct  {
} SM_Audio_Capture_Backend_ALSA;


SM_Audio_Capture_Backend_ALSA *sm_audio_capture_backend_alsa_create(const SM_Audio_Capture_Create_Info *create_info);
void sm_audio_capture_backend_alsa_destroy(SM_Audio_Capture_Backend_ALSA *this);

#endif
