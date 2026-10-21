#ifndef SM_AUDIO_CODEC_H
#define SM_AUDIO_CODEC_H

#include <sm-api.h>
#include <sm-typedef.h>

struct SM_Audio_Codec;

typedef void * SM_Audio_Codec_Backend;
typedef struct SM_Audio_Codec SM_Audio_Codec;

typedef enum SM_Audio_Codec_Backend_API {
   SM_AUDIO_CODEC_BACKEND_API_PIPEWIRE,
   SM_AUDIO_CODEC_BACKEND_API_PULSEAUDIO,
} SM_Audio_Codec_Backend_API;

typedef struct SM_Audio_Codec_Create_Info {
   SM_Audio_Codec_Backend_API backend_type;
   SM_Unsigned_32 sample_rate;
   SM_Unsigned_8 channel_count;
} SM_Audio_Codec_Create_Info;

SM_API void sm_audio_codec_create(const SM_Audio_Codec_Create_Info *create_info, SM_Audio_Codec *this);

SM_API void sm_audio_codec_destroy(SM_Audio_Codec *this);

#endif
