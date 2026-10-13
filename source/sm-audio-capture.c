#include <stdlib.h>
#include <assert.h>

#include <sm-audio-capture.h>

#include "sm-audio-capture-pulseaudio.h"

struct SM_Audio_Capture {
   SM_Audio_Capture_Backend backend;
   SM_Audio_Capture_Interface interface;
};

SM_Audio_Capture *sm_audio_capture_create(const SM_Audio_Capture_Create_Info *create_info)
{
   SM_Audio_Capture *audio_capture = (SM_Audio_Capture *)malloc(sizeof(SM_Audio_Capture));
   assert(audio_capture);

   switch (create_info->backend_type) {
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_PULSEAUDIO:
      audio_capture->interface = audio_capture_interface_pulseaudio;
      break;
   case SM_AUDIO_CAPTURE_BACKEND_TYPE_PIPEWIRE:
      // audio_capture->interface = audio_capture_interface_pipewire;
      break;
   }

   audio_capture->interface.create(create_info, audio_capture->backend);
}

void sm_audio_capture_destroy(SM_Audio_Capture *audio_capture)
{
   audio_capture->interface.destroy(audio_capture->backend);
}
