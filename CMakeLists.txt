cmake_minimum_required(VERSION 2.6)
project(ARES)

set(CMAKE_EXECUTABLE_SUFFIX ".html")

string(TOLOWER "${CMAKE_CXX_COMPILER_ID}" COMP)
string(TOLOWER "${CMAKE_SYSTEM_NAME}" PLATFORM)
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" ARCH)
message("${COMP}-${PLATFORM}-${ARCH}")

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
  src
  ${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/include
)

link_directories(
  ${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/lib
)

if(MINGW)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s -static")
  add_definitions(-DGLEW_STATIC)
  set(STATIC_LIBS imm32 iconv winmm ole32 gdi32 oleaut32 version)
  set(LIBGLEW glew32)
  set(LIBSDL2 SDL2)
elseif(MSVC)
  add_definitions(-DGLEW_STATIC)
  set(STATIC_LIBS imm32 winmm setupapi version)
  set(LIBGLEW glew32s)
  set(LIBSDL2 SDL2-static)
endif()

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC OR MINGW)
  target_link_libraries(rend ${LIBGLEW} opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(ares
  src/ares/Core.cpp
  src/ares/Entity.cpp
  src/ares/Component.cpp
  src/ares/Exception.cpp
  src/ares/Renderer.cpp
  src/ares/Transform.cpp
  src/ares/Resource.cpp
  src/ares/Texture.cpp
  src/ares/Screen.cpp
  src/ares/Keyboard.cpp

  src/ares/Core.h
  src/ares/Entity.h
  src/ares/Component.h
  src/ares/Exception.h
  src/ares/Renderer.h
  src/ares/Transform.h
  src/ares/Resource.h
  src/ares/Texture.h
  src/ares/Screen.h
  src/ares/Keyboard.h
  src/ares/ares.h
)
target_link_libraries(ares rend ${LIBSDL2} ${STATIC_LIBS})

add_executable(demo
  src/demo/main.cpp
)
target_link_libraries(demo ares)
