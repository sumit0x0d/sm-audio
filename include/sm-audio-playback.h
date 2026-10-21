#ifndef SM_AUDIO_PLAYBACK_H
#define SM_AUDIO_PLAYBACK_H

#include <sm-api.h>
#include <sm-typedef.h>

typedef union SM_Audio_Playback_Backend SM_Audio_Playback_Backend;
typedef struct SM_Audio_Playback SM_Audio_Playback;

typedef enum SM_Audio_Playback_Backend_API {
   SM_AUDIO_PLAYBACK_BACKEND_API_PIPEWIRE,
   SM_AUDIO_PLAYBACK_BACKEND_API_PULSEAUDIO,
} SM_Audio_Playback_Backend_API;

typedef struct SM_Audio_Playback_Create_Info {
   SM_Audio_Playback_Backend_API backend_enum;
   SM_Unsigned_32 format;
   SM_Unsigned_32 sample_rate;
   SM_Unsigned_8 channel_count;
} SM_Audio_Playback_Create_Info;

SM_API SM_Audio_Playback *sm_audio_playback_create(const SM_Audio_Playback_Create_Info *create_info);

SM_API void sm_audio_playback_destroy(SM_Audio_Playback *this);

#endif
