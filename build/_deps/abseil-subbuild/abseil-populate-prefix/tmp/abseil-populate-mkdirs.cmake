# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-src")
  file(MAKE_DIRECTORY "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-build"
  "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-subbuild/abseil-populate-prefix"
  "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-subbuild/abseil-populate-prefix/tmp"
  "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-subbuild/abseil-populate-prefix/src/abseil-populate-stamp"
  "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-subbuild/abseil-populate-prefix/src"
  "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-subbuild/abseil-populate-prefix/src/abseil-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-subbuild/abseil-populate-prefix/src/abseil-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/victo/OneDrive/Área de Trabalho/Nova pasta/Hotel/build/_deps/abseil-subbuild/abseil-populate-prefix/src/abseil-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()