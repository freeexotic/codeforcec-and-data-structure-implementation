# Install script for directory: /Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/prj.lab

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/complex/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/stackarr/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/stacklst/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/queuelst/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/queuearr/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/queuelstpr/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/bitset/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/stackarrt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/stacklstt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/queuearrt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/dynarr/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/queuelstt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/vsevolodsilaev/CLionProjects/misis2024s-23-03-silaev-v-v/cmake-build-release/prj.lab/rational/cmake_install.cmake")
endif()

