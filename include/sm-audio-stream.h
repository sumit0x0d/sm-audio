#ifndef SM_AUDIO_STREAM_H
#define SM_AUDIO_STREAM_H

#include <sm-api.h>
#include <sm-typedef.h>

typedef union SM_Audio_Stream_Backend SM_Audio_Stream_Backend;
typedef struct SM_Audio_Stream SM_Audio_Stream;

typedef enum SM_Audio_Stream_Backend_API {
   SM_AUDIO_Stream_BACKEND_API_PIPEWIRE,
   SM_AUDIO_Stream_BACKEND_API_PULSEAUDIO,
} SM_Audio_Stream_Backend_API;

typedef struct SM_Audio_Stream_Create_Info {
   SM_Audio_Stream_Backend_API backend_enum;
   SM_Unsigned_32 format;
   SM_Unsigned_32 sample_rate;
   SM_Unsigned_8 channel_count;
} SM_Audio_Stream_Create_Info;

SM_API SM_Audio_Stream *sm_audio_Stream_create(const SM_Audio_Stream_Create_Info *create_info);

SM_API void sm_audio_Stream_destroy(SM_Audio_Stream *this);


#endif