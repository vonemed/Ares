cmake_minimum_required(VERSION 2.6)
project(ARES)

include_directories(
	src
	contrib
)

if(MSVC)
  include_directories(
    #contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    contrib/msvc-windows-x86/SDL2/lib
    #${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  )
else()
  include_directories(
    /usr/X11R6/include
    /usr/local/include
  )

  link_directories(
    /usr/X11R6/lib
    /usr/local/lib
  )
endif()

add_library(ares 
	src/ares/Core.cpp
)

if(MSVC)
  target_link_libraries(ares
    SDL2 
  )
else()
  target_link_libraries(ares
    SDL2 
  )
endif()

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo ares)