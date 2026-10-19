#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include <unistd.h>

#include "sm-audio-codec-backend-wavpack.h"

typedef struct SM_Audio_Codec_Backend_WavPack _wavpack_t;
typedef struct SM_Audio_Codec_Create_Info _create_info;

void
_wavpack_create(const _create_info *create_info, SM_Audio_Codec_Backend backend);
void
_wavpack_destroy(SM_Audio_Codec_Backend backend);

struct SM_Audio_Codec_Interface sm_audio_codec_interface = {
   .create = _wavpack_create,
   .destroy = _wavpack_destroy
};

void
_wavpack_create(const _create_info *create_info, SM_Audio_Codec_Backend backend)
{
   _wavpack_t *wavpack = (_wavpack_t *)backend;
   wavpack = (_wavpack_t *)malloc(sizeof (_wavpack_t));
}

void
_wavpack_destroy(SM_Audio_Codec_Backend backend)
{
   _wavpack_t *wavpack = (_wavpack_t *)backend;
   free(wavpack);
}

void
_wavpack_encode(struct SM_Audio_Codec_Backend_WavPack *wavpack, uint8_t *buffer)
{
}

void
_wavpack_decode(struct SM_Audio_Codec_Backend_WavPack *wavpack, uint8_t *encoded_buffer, uint32_t encoded_buffer_size)
{
}
