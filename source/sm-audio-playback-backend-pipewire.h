#ifndef SM_AUDIO_PLAYBACK_BACKEND_PIPEWIRE_H
#define SM_AUDIO_PLAYBACK_BACKEND_PIPEWIRE_H

#include <math.h>

#include <pipewire/pipewire.h>
#include <spa/param/audio/format-utils.h>

#include <sm-audio-playback.h>

struct SM_Audio_Playback_Backend_PipeWire {
   int seq;
   unsigned move:1;
   struct pw_main_loop *main_loop;
   struct pw_context *context;
   struct pw_core *core;
   struct spa_hook core_listener;
   struct pw_registry *registry;
   struct spa_hook registry_listener;
   struct pw_stream *stream;
   struct spa_hook stream_listener;
   struct spa_audio_info format;
};

#endif
