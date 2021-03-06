/*
 * Copyright (C) 2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include <level_zero/zet_api.h>

namespace L0 {
struct OsSysman;
class OsScheduler {
  public:
    virtual ze_result_t getPreemptTimeout(uint64_t &timeout, ze_bool_t getDefault) = 0;
    virtual ze_result_t getTimesliceDuration(uint64_t &timeslice, ze_bool_t getDefault) = 0;
    virtual ze_result_t getHeartbeatInterval(uint64_t &heartbeat, ze_bool_t getDefault) = 0;
    virtual ze_result_t setPreemptTimeout(uint64_t timeout) = 0;
    virtual ze_result_t setTimesliceDuration(uint64_t timeslice) = 0;
    virtual ze_result_t setHeartbeatInterval(uint64_t heartbeat) = 0;
    virtual ze_bool_t canControlScheduler() = 0;
    virtual bool isSchedulerSupported() = 0;
    static OsScheduler *create(OsSysman *pOsSysman);
    virtual ~OsScheduler() = default;
};

} // namespace L0
