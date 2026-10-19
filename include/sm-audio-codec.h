#ifndef SM_AUDIO_CODEC_H
#define SM_AUDIO_CODEC_H

#include <stdint.h>

struct SM_Audio_Codec;

typedef void * SM_Audio_Codec_Backend;
typedef struct SM_Audio_Codec SM_Audio_Codec;

typedef enum SM_Audio_Codec_Backend_Type {
   SM_AUDIO_CODEC_BACKEND_TYPE_PIPEWIRE,
   SM_AUDIO_CODEC_BACKEND_TYPE_PULSEAUDIO,
} SM_Audio_Codec_Backend_Type;

typedef struct SM_Audio_Codec_Create_Info {
   SM_Audio_Codec_Backend_Type backend_type;
   SM_Unsigned_32 sample_rate;
   SM_Unsigned_8 channel_count;
} SM_Audio_Codec_Create_Info;

typedef struct SM_Audio_Codec_Interface {
   void (*create)(const SM_Audio_Codec_Create_Info *create_info, SM_Audio_Codec_Backend backend);
   void (*destroy)(SM_Audio_Codec_Backend backend);
} SM_Audio_Codec_Interface;

void sm_audio_codec_create(const SM_Audio_Codec_Create_Info *create_info, SM_Audio_Codec *this);
void sm_audio_codec_destroy(SM_Audio_Codec *this);

#endif
