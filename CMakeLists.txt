cmake_minimum_required(VERSION 3.22.1)

project(sm-audio-capture
   VERSION 1.0.0
   DESCRIPTION "Audio Capture (libsm-x)"
   LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_BUILD_API Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
   add_compile_options(/W4 /WX)
else()
   set(CMAKE_C_VISIBILITY_PRESET hidden)
   set(CMAKE_CXX_VISIBILITY_PRESET hidden)
   set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
   # add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(ALSA REQUIRED IMPORTED_TARGET alsa)
pkg_check_modules(PULSEAUDIO REQUIRED IMPORTED_TARGET libpulse)
# pkg_check_modules(PIPEWIRE REQUIRED IMPORTED_TARGET libpipewire-0.3)

add_library(sm-audio-capture SHARED
   "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture.c"
   # "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture-backend-alsa.c"
   # "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture-backend-pipewire.c"
   "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture-backend-pulseaudio.c")
target_link_libraries(sm-audio-capture PRIVATE ${PULSEAUDIO_LIBRARIES})
target_include_directories(sm-audio-capture PRIVATE ${PULSEAUDIO_INCLUDE_DIRS} PUBLIC include)

include(GNUInstallDirs)

install(TARGETS sm-audio-capture
   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY include/
   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
   enable_testing()

   add_executable(test-sm-audio-capture test/test-sm-audio-capture.c)
   target_link_libraries(test-sm-audio-capture PUBLIC sm-audio-capture)
endif()
