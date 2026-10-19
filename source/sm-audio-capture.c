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
   SM_Audio_Capture_Backend_Type backend_type;
   SM_Audio_Capture_Backend backend;
};

SM_Audio_Capture *sm_audio_capture_create(const SM_Audio_Capture_Create_Info *create_info)
{
   SM_Audio_Capture *this;

   this = (SM_Audio_Capture *)malloc(sizeof(SM_Audio_Capture));
   if (!this) {
      return NULL;
   }

   switch (create_info->backend_type) {
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_PULSEAUDIO:
      this->backend.pulseaudio = sm_audio_capture_backend_pulseaudio_create(create_info);
      break;
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_PIPEWIRE:
      // audio_capture->backend = sm_audio_capture_backend_pipewire_create(create_info);
      break;
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_ALSA:
      // audio_capture->backend = sm_audio_capture_backend_alsa_create(create_info);
      break;
   }

   this->backend_type = create_info->backend_type;
   
   return this;
}

void sm_audio_capture_destroy(SM_Audio_Capture *this)
{
   switch (this->backend_type) {
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_PULSEAUDIO:
      sm_audio_capture_backend_pulseaudio_destroy(this->backend.pulseaudio);
      break;
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_PIPEWIRE:
      break;
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_ALSA:
      break;
   }

   free(this);
}
