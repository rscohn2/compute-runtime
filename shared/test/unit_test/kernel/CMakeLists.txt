#
# Copyright (C) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

target_sources(${TARGET_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
  ${CMAKE_CURRENT_SOURCE_DIR}/kernel_arg_descriptor_tests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/kernel_arg_metadata_tests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/kernel_descriptor_from_patchtokens_tests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/kernel_descriptor_tests.cpp
)
