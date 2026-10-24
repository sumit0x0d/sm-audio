#ifndef SM_AUDIO_CAPTURE_H
#define SM_AUDIO_CAPTURE_H

#include <sm-api.h>
#include <sm-typedef.h>

typedef struct SM_Audio_Capture SM_Audio_Capture;
typedef union SM_Audio_Capture_Backend SM_Audio_Capture_Backend;

typedef enum {
   SM_AUDIO_CAPTURE_BACKEND_API_ALSA,
   SM_AUDIO_CAPTURE_BACKEND_API_PIPEWIRE,
   SM_AUDIO_CAPTURE_BACKEND_API_PULSEAUDIO
} SM_Audio_Capture_Backend_API;

typedef struct {
   SM_Audio_Capture_Backend_API backend_api;
   SM_Unsigned_8 channel_count;
   SM_Unsigned_32 sample_rate;
} SM_Audio_Capture_Create_Info;

typedef struct {

} SM_Audio_Capture_Device;

typedef struct {
   SM_Audio_Capture_Device **device;
   size_t device_count;
} SM_Audio_Capture_Device_List;

SM_API SM_Audio_Capture *sm_audio_capture_create(const SM_Audio_Capture_Create_Info *create_info);

SM_API void sm_audio_capture_destroy(SM_Audio_Capture *this);

SM_API SM_Audio_Capture_Device_List *sm_audio_capture_get_device_list(SM_Audio_Capture *this);

SM_API void sm_audio_capture_set_device(SM_Audio_Capture *this, SM_Audio_Capture_Device *device);

SM_API void sm_audio_capture_start(SM_Audio_Capture *this);

SM_API void sm_audio_capture_stop(SM_Audio_Capture *this);

#endif
