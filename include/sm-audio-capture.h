#ifndef SM_AUDIO_CAPTURE_H
#define SM_AUDIO_CAPTURE_H

#include <sm-typedef.h>

typedef void * SM_Audio_Capture_Backend;
typedef struct SM_Audio_Capture SM_Audio_Capture;

typedef enum {
   SM_AUDIO_CAPTURE_BACKEND_TYPE_ALSA,
   SM_AUDIO_CAPTURE_BACKEND_TYPE_PIPEWIRE,
   SM_AUDIO_CAPTURE_BACKEND_TYPE_PULSEAUDIO,
} SM_Audio_Capture_Backend_Type;

typedef struct {
   SM_Audio_Capture_Backend_Type backend_type;
   SM_Unsigned_8 channel_count;
   SM_Unsigned_32 sample_rate;
} SM_Audio_Capture_Create_Info;

typedef struct {
   SM_Audio_Capture_Backend (*create)(const SM_Audio_Capture_Create_Info *create_info);
   void (*destroy)(SM_Audio_Capture_Backend backend);
} SM_Audio_Capture_Interface;

SM_Audio_Capture *sm_audio_capture_create(const SM_Audio_Capture_Create_Info *create_info);
void sm_audio_capture_destroy(SM_Audio_Capture *audio_capture);

#endif
