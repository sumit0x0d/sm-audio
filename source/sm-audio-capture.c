#include <stdlib.h>
#include <assert.h>

#include <sm-audio-capture.h>

#include "sm-audio-capture-backend-pulseaudio.h"

union SM_Audio_Capture_Backend {
   SM_Audio_Capture_Backend_PulseAudio *pulseaudio;
   // SM_Audio_Capture_Backend_ALSA *alsa;
   // SM_Audio_Capture_Backend_PipeWire *pipewire;
};

struct SM_Audio_Capture {
   SM_Audio_Capture_Backend_API backend_api;
   SM_Audio_Capture_Backend backend;
};

SM_Audio_Capture *sm_audio_capture_create(const SM_Audio_Capture_Create_Info *create_info)
{
   SM_Audio_Capture *this;

   this = (SM_Audio_Capture *)malloc(sizeof(SM_Audio_Capture));
   if (!this) {
      return NULL;
   }

   switch (create_info->backend_api) {
   case SM_AUDIO_CAPTURE_BACKEND_API_PULSEAUDIO:
      this->backend.pulseaudio = sm_audio_capture_backend_pulseaudio_create(create_info);
      break;
   case SM_AUDIO_CAPTURE_BACKEND_API_PIPEWIRE:
      // audio_capture->backend = sm_audio_capture_backend_pipewire_create(create_info);
      break;
   case SM_AUDIO_CAPTURE_BACKEND_API_ALSA:
      // audio_capture->backend = sm_audio_capture_backend_alsa_create(create_info);
      break;
   }

   this->backend_api = create_info->backend_api;
   
   return this;
}

void sm_audio_capture_destroy(SM_Audio_Capture *this)
{
   switch (this->backend_api) {
   case SM_AUDIO_CAPTURE_BACKEND_API_PULSEAUDIO:
      sm_audio_capture_backend_pulseaudio_destroy(this->backend.pulseaudio);
      break;
   case SM_AUDIO_CAPTURE_BACKEND_API_PIPEWIRE:
      break;
   case SM_AUDIO_CAPTURE_BACKEND_API_ALSA:
      break;
   }

   free(this);
}
