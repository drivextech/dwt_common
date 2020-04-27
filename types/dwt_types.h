// Copyright 2020 DriveX.Tech. All rights reserved.
// 
// Licensed under the License.

#pragma once
#ifndef _DWT_TYPES_H_
#define _DWT_TYPES_H_

#include <stdbool.h>
#include "types/types.h"


#ifdef __cplusplus
namespace dxt_common {
extern "C" {
#endif


typedef UINT64 dwt_time_counter_t;
typedef INT64 dwt_time_counter_diff_t;


typedef struct _radio_cbers_t {
    cber0_t rx_good_cber;
    cber0_t rx_timeout_cber;
    cber0_t rx_error_cber;
    cber0_t rx_header_good_cber;
    cber0_t tx_good_cber;
    cber0_t tx_error_cber;
    cber0_t tx_header_good_cber;
} radio_cbers_t;

#define NULL_RADIO_CBERS ((radio_cbers_t){ NULL_CBER0, NULL_CBER0, NULL_CBER0, NULL_CBER0, NULL_CBER0, NULL_CBER0, NULL_CBER0 })



/* UWB microsecond (uus) to device time unit (dtu, around 15.65 ps) conversion factor.
* 1 uus = 512 / 499.2 µs and 1 µs = 499.2 * 128 dtu. */
#define UUS_TO_DWT_TIME (65536)
#define DWT_TO_UUS_TIME (1.0 / 65536)
#define US_TO_DWT_TIME (499.2 * 128)
#define DWT_TO_US_TIME (1.0 / 128 / 499.2)

#define dwt_uus_to_us(_inst, dt) (dt * (65536.0 / 128.0 / 499.2))
#define dwt_us_to_uus(_inst, dt) (dt * (128.0 * 499.2 / 65536.0))
#define dwt_uus_to_dtu(_inst, dt) (dt * 65536.0)
#define dwt_dtu_to_uus(_inst, dt) (dt / 65536.0)
#define dwt_us_to_dtu(_inst, dt) (dt * 128.0 * 499.2)
#define dwt_dtu_to_us(_inst, dt) (dt / 128.0 / 499.2)


#define DWT_TIME_COUNTER_SUM(a, b)     ((dwt_time_counter_t)((a)+(b)))
#define DWT_TIME_COUNTER_DIFF(a, b)    ((dwt_time_counter_diff_t)((a)-(b)))
#define DWT_TIME_COUNTER_LT(a, b)      (DWT_TIME_COUNTER_DIFF(a, b) < 0)
#define DWT_TIME_COUNTER_GT(a, b)      (DWT_TIME_COUNTER_DIFF(a, b) > 0)
#define DWT_TIME_COUNTER_LE(a, b)      (DWT_TIME_COUNTER_DIFF(a, b) <= 0)
#define DWT_TIME_COUNTER_GE(a, b)      (DWT_TIME_COUNTER_DIFF(a, b) >= 0)


#ifdef __cplusplus
}
}
#endif

#endif