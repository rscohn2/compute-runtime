#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(IGDRCL_SRCS_aub_helper_tests
  ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_center_tests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}${BRANCH_DIR_SUFFIX}/aub_helper_tests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_helper_tests.inl
)

if(NOT DEFINED AUB_STREAM_PROJECT_NAME)
  list(APPEND IGDRCL_SRCS_aub_helper_tests
    ${CMAKE_CURRENT_SOURCE_DIR}/aub_center_using_aubstream_stubs_tests.cpp
  )
endif()

target_sources(igdrcl_tests PRIVATE ${IGDRCL_SRCS_aub_helper_tests})
add_subdirectories()
