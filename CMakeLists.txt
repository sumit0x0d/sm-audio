cmake_minimum_required(VERSION 3.22.1)

project(sm-audio-capture
   VERSION 1.0.0
   DESCRIPTION "Audio Capture (libsm-x)"
   LANGUAGES C
)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
   add_compile_options(/W4 /WX)
else()
   set(CMAKE_C_VISIBILITY_PRESET hidden)
   set(CMAKE_CXX_VISIBILITY_PRESET hidden)
   set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
   add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(ALSA REQUIRED IMPORTED_TARGET alsa)
pkg_check_modules(PULSEAUDIO REQUIRED IMPORTED_TARGET libpulse)
# pkg_check_modules(PIPEWIRE REQUIRED IMPORTED_TARGET libpipewire-0.3)

add_library(sm-audio-capture SHARED
   "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture.c"
   "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture-pulseaudio.c"
   # "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture-pipewire.c"
   "${CMAKE_CURRENT_SOURCE_DIR}/source/sm-audio-capture-alsa.c")
target_link_libraries(sm-audio-capture PRIVATE ${ALSA_LIBRARIES} ${PULSEAUDIO_LIBRARIES})
target_include_directories(sm-audio-capture PRIVATE ${ALSA_INCLUDE_DIRS} ${PULSEAUDIO_INCLUDE_DIRS} PUBLIC include)

include(GNUInstallDirs)

install(TARGETS
   sm-audio-capture
   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/
   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
   enable_testing()

   add_executable(sm-audio-capture-test test/sm-audio-capture-test.c)
   add_test(NAME sm-audio-capture COMMAND sm-audio-capture-test)
   target_link_libraries(sm-audio-capture-test PUBLIC sm-audio-capture)
endif()
