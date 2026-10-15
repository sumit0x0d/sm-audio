#include "sm-audio-capture.h"

int main()
{
	SM_Audio_Capture_Create_Info create_info = {
		.backend_type = SM_AUDIO_CAPTURE_BACKEND_TYPE_PULSEAUDIO,
		.sample_rate = 44100,
		.channel_count = 2
	};
	SM_Audio_Capture *audio_capture = sm_audio_capture_create(&create_info);
	// sm_audio_capture_mic(audio_capture);
	return 0;
}
