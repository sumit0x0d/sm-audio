#ifndef SM_AUDIO_PLAYBACK_H
#define SM_AUDIO_PLAYBACK_H

#include <stdint.h>

struct SM_Audio_Playback;

typedef union SM_Audio_Playback_Backend SM_Audio_Playback_Backend;
typedef struct SM_Audio_Playback SM_Audio_Playback;

typedef enum SM_Audio_Playback_Backend_Type {
   SM_AUDIO_PLAYBACK_BACKEND_TYPE_PIPEWIRE,
   SM_AUDIO_PLAYBACK_BACKEND_TYPE_PULSEAUDIO,
} SM_Audio_Playback_Backend_Type;

typedef struct SM_Audio_Playback_Create_Info {
   SM_Audio_Playback_Backend_Type backend_type;
   uint32_t format;
   uint32_t sample_rate;
   uint8_t channel_count;
} SM_Audio_Playback_Create_Info;

SM_Audio_Playback *sm_audio_playback_create(const SM_Audio_Playback_Create_Info *create_info);
void sm_audio_playback_destroy(SM_Audio_Playback *this);

#endif
