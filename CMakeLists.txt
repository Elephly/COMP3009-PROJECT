cmake_minimum_required(VERSION 2.6)

project(N3DIL)

set(CMAKE_CXX_STANDARD 11)

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(PUBLIC_INCLUDE_DIR "${PROJECT_BINARY_DIR}/include")
set(PUBLIC_RESOURCE_DIR_NAME "res")
set(PUBLIC_RESOURCE_DIR "${PROJECT_BINARY_DIR}/${PUBLIC_RESOURCE_DIR_NAME}")
set(CONFIG_HEADER_IN "${PROJECT_SOURCE_DIR}/ProjectConfig.h.in")
set(CONFIG_HEADER_OUT "${PUBLIC_INCLUDE_DIR}/ProjectConfig.h")
set(LOCAL_SUBMODULE_DIR "${PROJECT_SOURCE_DIR}/submodules")
set(LOCAL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(LOCAL_RESOURCE_DIR "${PROJECT_SOURCE_DIR}/res")
set(LOCAL_SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(LOCAL_INCLUDES
  "${CONFIG_HEADER_IN}"
  "${LOCAL_INCLUDE_DIR}/MyAnimation.h"
  "${LOCAL_INCLUDE_DIR}/MyAnimationTrack.h"
  "${LOCAL_INCLUDE_DIR}/MyApplication.h"
  "${LOCAL_INCLUDE_DIR}/MyCamera.h"
  "${LOCAL_INCLUDE_DIR}/MyDefines.h"
  "${LOCAL_INCLUDE_DIR}/MyFileIO.h"
  "${LOCAL_INCLUDE_DIR}/MyGeometry.h"
  "${LOCAL_INCLUDE_DIR}/MyGraphics.h"
  "${LOCAL_INCLUDE_DIR}/MyGraphicsObject3D.h"
  "${LOCAL_INCLUDE_DIR}/MyImage.h"
  "${LOCAL_INCLUDE_DIR}/MyImageUtil.h"
  "${LOCAL_INCLUDE_DIR}/MyIncludes.h"
  "${LOCAL_INCLUDE_DIR}/MyIndexedVertexArray.h"
  "${LOCAL_INCLUDE_DIR}/MyInputManager.h"
  "${LOCAL_INCLUDE_DIR}/MyKeyframe.h"
  "${LOCAL_INCLUDE_DIR}/MyLightSource.h"
  "${LOCAL_INCLUDE_DIR}/MyManikin.h"
  "${LOCAL_INCLUDE_DIR}/MyMaterial.h"
  "${LOCAL_INCLUDE_DIR}/MyMath.h"
  "${LOCAL_INCLUDE_DIR}/MyMatrix.h"
  "${LOCAL_INCLUDE_DIR}/MyMeshFactory.h"
  "${LOCAL_INCLUDE_DIR}/MyObject3D.h"
  "${LOCAL_INCLUDE_DIR}/MyObjectManager.h"
  "${LOCAL_INCLUDE_DIR}/MyShaderManager.h"
  "${LOCAL_INCLUDE_DIR}/MyShaderProgram.h"
  "${LOCAL_INCLUDE_DIR}/MyStringUtil.h"
  "${LOCAL_INCLUDE_DIR}/MyTexture2D.h"
  "${LOCAL_INCLUDE_DIR}/MyVector.h"
  "${LOCAL_INCLUDE_DIR}/MyVertex.h"
)
set(LOCAL_RESOURCES
  "${LOCAL_RESOURCE_DIR}/images/lenovo.PNG"
  "${LOCAL_RESOURCE_DIR}/images/sample2.png"
  "${LOCAL_RESOURCE_DIR}/images/sample.png"
  "${LOCAL_RESOURCE_DIR}/images/TuxTorso.png"
  "${LOCAL_RESOURCE_DIR}/shaders/ColorFrag.glsl"
  "${LOCAL_RESOURCE_DIR}/shaders/ColorVert.glsl"
  "${LOCAL_RESOURCE_DIR}/shaders/GouraudFrag.glsl"
  "${LOCAL_RESOURCE_DIR}/shaders/GouraudVert.glsl"
  "${LOCAL_RESOURCE_DIR}/shaders/PhongFrag.glsl"
  "${LOCAL_RESOURCE_DIR}/shaders/PhongVert.glsl"
  "${LOCAL_RESOURCE_DIR}/shaders/WhiteVert.glsl"
)
set(LOCAL_SRCS
  "${LOCAL_SRC_DIR}/main.cpp"
  "${LOCAL_SRC_DIR}/MyAnimation.cpp"
  "${LOCAL_SRC_DIR}/MyAnimationTrack.cpp"
  "${LOCAL_SRC_DIR}/MyApplication.cpp"
  "${LOCAL_SRC_DIR}/MyCamera.cpp"
  "${LOCAL_SRC_DIR}/MyFileIO.cpp"
  "${LOCAL_SRC_DIR}/MyGeometry.cpp"
  "${LOCAL_SRC_DIR}/MyGraphics.cpp"
  "${LOCAL_SRC_DIR}/MyGraphicsObject3D.cpp"
  "${LOCAL_SRC_DIR}/MyImage.cpp"
  "${LOCAL_SRC_DIR}/MyImageUtil.cpp"
  "${LOCAL_SRC_DIR}/MyIndexedVertexArray.cpp"
  "${LOCAL_SRC_DIR}/MyInputManager.cpp"
  "${LOCAL_SRC_DIR}/MyKeyframe.cpp"
  "${LOCAL_SRC_DIR}/MyLightSource.cpp"
  "${LOCAL_SRC_DIR}/MyManikin.cpp"
  "${LOCAL_SRC_DIR}/MyMaterial.cpp"
  "${LOCAL_SRC_DIR}/MyMath.cpp"
  "${LOCAL_SRC_DIR}/MyMatrix.cpp"
  "${LOCAL_SRC_DIR}/MyMeshFactory.cpp"
  "${LOCAL_SRC_DIR}/MyObject3D.cpp"
  "${LOCAL_SRC_DIR}/MyShaderManager.cpp"
  "${LOCAL_SRC_DIR}/MyShaderProgram.cpp"
  "${LOCAL_SRC_DIR}/MyStringUtil.cpp"
  "${LOCAL_SRC_DIR}/MyTexture2D.cpp"
  "${LOCAL_SRC_DIR}/MyVector.cpp"
  "${LOCAL_SRC_DIR}/MyVertex.cpp"
)

# The version number.
set(PROJ_VERSION_MAJOR 0)
set(PROJ_VERSION_MINOR 1)
set(PROJ_VERSION_PATCH 0)
execute_process(COMMAND git rev-list --count HEAD WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" OUTPUT_VARIABLE PROJ_VERSION_REVISION)

# Configure a header file to pass some of the CMake settings to the source code.
configure_file(
  "${CONFIG_HEADER_IN}"
  "${CONFIG_HEADER_OUT}"
)

include_directories("${LOCAL_INCLUDE_DIR}")
include_directories("${PUBLIC_INCLUDE_DIR}")
include_directories("${LOCAL_SUBMODULE_DIR}/FreeGLUT/freeglut/freeglut/include")
include_directories("${LOCAL_SUBMODULE_DIR}/glew/include")
include_directories("${LOCAL_SUBMODULE_DIR}/Simple-OpenGL-Image-Library/src")

add_subdirectory("${LOCAL_SUBMODULE_DIR}/FreeGLUT/freeglut/freeglut")
add_subdirectory("${LOCAL_SUBMODULE_DIR}/glew/build/cmake")
add_subdirectory("${LOCAL_SUBMODULE_DIR}/Simple-OpenGL-Image-Library")

# Build glew registry and extensions
execute_process(COMMAND bash -c make WORKING_DIRECTORY "${LOCAL_SUBMODULE_DIR}/glew/auto")

add_executable("${PROJECT_NAME}" "${LOCAL_INCLUDES}" "${LOCAL_RESOURCES}" "${LOCAL_SRCS}")

add_custom_command(TARGET "${PROJECT_NAME}" POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${LOCAL_RESOURCE_DIR}" "${PUBLIC_RESOURCE_DIR}")

target_link_libraries("${PROJECT_NAME}"
  freeglut
  glew
  SOIL
)

set_target_properties(freeglut PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

# Add the install targets
install (TARGETS "${PROJECT_NAME}"
  RUNTIME DESTINATION "bin"
  LIBRARY NAMELINK_ONLY DESTINATION "lib"
  ARCHIVE DESTINATION "lib/static")
install (FILES "${CONFIG_HEADER_OUT}" DESTINATION "include")
install (DIRECTORY "${LOCAL_RESOURCE_DIR}/" DESTINATION "bin/${PUBLIC_RESOURCE_DIR_NAME}")
