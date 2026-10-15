#define _POSIX_C_SOURCE 199309L

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sm-audio-capture.h>

static int get_time(struct timespec *time)
{
   if (clock_gettime(CLOCK_MONOTONIC, time) != 0) {
      perror("clock_gettime");
      return 0;
   }

   return 1;
}

static double elapsed_milliseconds(const struct timespec *start, const struct timespec *end)
{
   return ((double)(end->tv_sec - start->tv_sec) * 1000.0) +
      ((double)(end->tv_nsec - start->tv_nsec) / 1000000.0);
}

static int parse_iteration_count(const char *argument, unsigned long *iteration_count)
{
   char *end;
   unsigned long parsed;

   errno = 0;
   parsed = strtoul(argument, &end, 10);
   if (errno != 0 || argument[0] == '\0' || argument[0] == '-' || *end != '\0' || parsed == 0) {
      return 0;
   }

   *iteration_count = parsed;
   return 1;
}

int main(int argc, char **argv)
{
   unsigned long iteration_count = 1;
   unsigned long iteration;
   double create_time_ms = 0.0;
   double destroy_time_ms = 0.0;
   SM_Audio_Capture_Create_Info create_info = {
      .backend_type = SM_AUDIO_CAPTURE_BACKEND_TYPE_PULSEAUDIO,
      .channel_count = 2,
      .sample_rate = 44100
   };

   if (argc > 2 || (argc == 2 && !parse_iteration_count(argv[1], &iteration_count))) {
      fprintf(stderr, "Usage: %s [iteration-count]\n", argv[0]);
      return EXIT_FAILURE;
   }

   for (iteration = 0; iteration < iteration_count; ++iteration) {
      struct timespec start;
      struct timespec end;
      SM_Audio_Capture *audio_capture;

      if (!get_time(&start)) {
         return EXIT_FAILURE;
      }
      audio_capture = sm_audio_capture_create(&create_info);
      if (!get_time(&end)) {
         if (audio_capture != NULL) {
            sm_audio_capture_destroy(audio_capture);
         }
         return EXIT_FAILURE;
      }
      if (audio_capture == NULL) {
         fprintf(stderr, "Audio capture creation failed at iteration %lu\n", iteration + 1);
         return EXIT_FAILURE;
      }
      create_time_ms += elapsed_milliseconds(&start, &end);

      if (!get_time(&start)) {
         sm_audio_capture_destroy(audio_capture);
         return EXIT_FAILURE;
      }
      sm_audio_capture_destroy(audio_capture);
      if (!get_time(&end)) {
         return EXIT_FAILURE;
      }
      destroy_time_ms += elapsed_milliseconds(&start, &end);
   }

   printf("Backend: PulseAudio\n");
   printf("Iterations: %lu\n", iteration_count);
   printf("Create average: %.3f ms\n", create_time_ms / (double)iteration_count);
   printf("Destroy average: %.3f ms\n", destroy_time_ms / (double)iteration_count);

   return EXIT_SUCCESS;
}