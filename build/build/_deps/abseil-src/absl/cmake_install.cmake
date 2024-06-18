# Install script for directory: C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-src/absl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Hotel")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/base/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/algorithm/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/cleanup/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/container/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/crc/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/debugging/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/flags/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/functional/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/hash/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/log/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/memory/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/meta/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/numeric/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/profiling/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/random/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/status/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/strings/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/synchronization/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/time/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/types/cmake_install.cmake")
  include("C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/build/_deps/abseil-src/absl/utility/cmake_install.cmake")

endif()

