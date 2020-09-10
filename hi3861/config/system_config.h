/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/* =============================================================================
                                       LiteOS kernel version configuration
============================================================================= */
/**
 * @ingroup los_config
 * Version number
 */
#define LITEOS_VER

/** system source configuration**/
/**
 * @ingroup los_config
 * system clock
 */
#ifdef HI_BOARD_ASIC
#define OS_SYS_CLOCK_CONFIG                               160000000
#else
#define OS_SYS_CLOCK_CONFIG                               53000000
#endif

/** system source configuration**/
/**
 * @ingroup los_config
 * Number of Ticks in one second
 */
#define LOSCFG_BASE_CORE_TICK_PER_SECOND_CONFIG           100

/** system source configuration**/
/**
 * @ingroup los_config
 * Maximum supported number of tasks except the idle task rather than the number of usable tasks
 */
#define LOSCFG_BASE_CORE_TSK_LIMIT_CONFIG                 32

/**
 * @ingroup los_config
 * Maximum supported number of semaphores
 */
#define LOSCFG_BASE_IPC_SEM_LIMIT_CONFIG                  32
/**
 * @ingroup los_config
 * Maximum supported number of mutexes
 */
#define LOSCFG_BASE_IPC_MUX_LIMIT_CONFIG                  32

/**
 * @ingroup los_config
 * Maximum supported number of queues rather than the number of usable queues
 */
#define LOSCFG_BASE_IPC_QUEUE_LIMIT_CONFIG                32
/**
 * @ingroup los_config
 * Maximum supported number of software timers rather than the number of usable software timers
 */
#define LOSCFG_BASE_CORE_SWTMR_LIMIT_CONFIG               32

/**
 * @ingroup los_config
 * Default task stack size
 */
#define LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE_CONFIG          (0x1000UL)
/**
 * @ingroup los_config
 * Idle task stack size.
 */
#define LOSCFG_BASE_CORE_TSK_IDLE_STACK_SIZE_CONFIG             (0x400UL)
/**
 * @ingroup los_config
 * Idle task stack size.
 */
#define LOSCFG_BASE_CORE_TSK_SWTMR_STACK_SIZE_CONFIG             (0x800UL)

/**
 * @ingroup los_config
 * Minimum stack size.
 */
#define LOSCFG_BASE_CORE_TSK_MIN_STACK_SIZE_CONFIG              (0x180UL)
/**
 * @ingroup los_config
 * Stack point align size.
 */
#define LOSCFG_STACK_POINT_ALIGN_SIZE                           16
/**
 * @ingroup los_config
 * Longest execution time of tasks with the same priorities
 */
#define LOSCFG_BASE_CORE_TIMESLICE_TIMEOUT_CONFIG               2
/**
 * @ingroup los_cpup
 * Number of track items
 */
#define LOSCFG_BASE_MISC_TRACK_COUNT_CONFIG                     10

#define LOSCFG_NMI_SERVICE                                      0

#ifdef LOSCFG_DEBUG_KASAN
#define LOSCFG_KASAN_TASK_STACK_LIMIT_NUM                       3
#endif

#define LOSCFG_MEM_POOL_SIZE                                    0x3C00

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _SYSTEM_CONFIG_H */
