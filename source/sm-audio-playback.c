#include <stdlib.h>
#include <assert.h>

#include <sm-audio-playback.h>

#include "sm-audio-playback-backend-pulseaudio.h"

union SM_Audio_Playback_Backend {
   SM_Audio_Playback_Backend_PulseAudio *pulseaudio;
   // SM_Audio_Playback_Backend_PipeWire *pipewire;
};

struct SM_Audio_Playback {
   SM_Audio_Playback_Backend_API backend_type;
   SM_Audio_Playback_Backend backend;
};

SM_Audio_Playback *sm_audio_playback_create(const SM_Audio_Playback_Create_Info *create_info)
{
   SM_Audio_Playback *this = (SM_Audio_Playback *)malloc(sizeof (SM_Audio_Playback));
   if (!this) {
      return NULL;
   }

   switch (create_info->backend_type) {
   case SM_AUDIO_PLAYBACK_BACKEND_API_PULSEAUDIO:
      this->backend.pulseaudio = sm_audio_playback_backend_pulseaudio_create(create_info);
      break;
   case SM_AUDIO_PLAYBACK_BACKEND_API_PIPEWIRE:
      // this->backend.pipewire = sm_audio_playback_backend_pipewire_create(create_info);
      break;
   }

   this->backend_type = create_info->backend_type;

   return this;
}

void sm_audio_playback_destroy(SM_Audio_Playback *this)
{
   switch (this->backend_type) {
   case SM_AUDIO_PLAYBACK_BACKEND_API_PULSEAUDIO:
      sm_audio_playback_backend_pulseaudio_destroy(this->backend.pulseaudio);
      break;
   case SM_AUDIO_PLAYBACK_BACKEND_API_PIPEWIRE:
      break;
   }

   free(this);
}
