#
# Copyright (C) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

if(UNIX)
    target_sources(${TARGET_NAME}
        PRIVATE
           ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
           ${CMAKE_CURRENT_SOURCE_DIR}${BRANCH_DIR_SUFFIX}/mock_sysfs_standby.h
           ${CMAKE_CURRENT_SOURCE_DIR}${BRANCH_DIR_SUFFIX}/test_zes_sysman_standby.cpp

    )
endif()
