#include "sm-audio-capture-backend-alsa.h"

typedef struct audio_capture_alsa Alsa;
typedef struct audio_capture_interface Interface;
typedef struct audio_capture_create_config CreateConfig;

SM_Audio_Capture_Backend_ALSA *sm_audio_capture_backend_alsa_create(const CreateConfig *create_config, audio_capture_backend_t backend)
{
   Alsa * alsa = (Alsa *)backend;
   alsa = (Alsa *)malloc(sizeof (Alsa));
   assert(audio_capture_alsa);
   return (SM_Audio_Capture_Backend_ALSA *)alsa;
}

void sm_audio_capture_backend_alsa_destroy(SM_Audio_Capture_Backend_ALSA *this)
{
   Alsa * alsa = (Alsa *)this;
   free(alsa);
}
