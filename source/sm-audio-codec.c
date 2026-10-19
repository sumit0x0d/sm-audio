#include <assert.h>
#include <stdlib.h>

#include "sm-audio-codec.h"

#include "sm-audio-codec-ffmpeg.h"

typedef struct SM_Audio_Codec SM_Audio_Codec;

SM_Audio_Codec *
sm_audio_codec_create(unsigned int width, unsigned int height, unsigned int frame_rate)
{
   SM_Audio_Codec *audio_codec = (SM_Audio_Codec *)malloc(sizeof (SM_Audio_Codec));
   assert(audio_codec);

   audio_codec->ffmpeg = sm_audio_codec_ffmpeg_create(true, VIDEO_CODEC_FFMPEG_H264_VAAPI, 1920, 1080, 60);

   return audio_codec;
}

void
sm_audio_codec_destroy(SM_Audio_Codec *audio_codec)
{
   free(audio_codec);
}

void
sm_audio_codec_encode(struct SM_Audio_Codec *audio_codec, uint8_t *buffer)
{
   sm_audio_codec_ffmpeg_encode(audio_codec->ffmpeg, buffer);
   audio_codec->encoded_buffer = audio_codec->ffmpeg->av_packet->data;
   audio_codec->encoded_buffer_size = audio_codec->ffmpeg->av_packet->size;
}

void
sm_audio_codec_decode(struct SM_Audio_Codec *audio_codec, uint8_t *encoded_buffer, uint32_t encoded_buffer_size)
{
   sm_audio_codec_ffmpeg_decode(audio_codec->ffmpeg, encoded_buffer, encoded_buffer_size);
}
