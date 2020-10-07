cmake_minimum_required(VERSION 2.6)
project(ARES)

include_directories(
	src
)

if(MSVC)
	include_directories(
		contrib/msvc-windows-x86_64/glew/include
	)
	
	link_directories(
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_64/glew/lib
)
endif()

add_definitions(-DSDL_MAIN_HANDLED)

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
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(ares 
	src/ares/Core.cpp
	src/ares/Core.h
	src/ares/Entity.h
	src/ares/Entity.cpp
	src/ares/Component.h
	src/ares/Component.cpp
	src/ares/ares.h
)

target_link_libraries(ares rend)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo ares)