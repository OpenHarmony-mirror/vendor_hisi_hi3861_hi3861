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

#ifndef __HI3861_H__
#define __HI3861_H__

typedef enum IRQn {
    /******  RISC-V  Privilege Interrupts ***************************************************/
    MACHINE_SOFTWARE_IRQ            = 3,
    MACHINE_TIMER_IRQ               = 7,
    MACHINE_EXTERNAL_IRQ            = 11,
    NMI_IRQ                         = 12,

    /******  HiMedeer local Interrupts ***************************************************/
    TIMER_0_IRQ                     = 26,
    TIMER_1_IRQ                     = 27,
    TIMER_2_IRQ                     = 28,
    RTC_0_IRQ                       = 29,
    RTC_1_IRQ                       = 30,
    RTC_2_IRQ                       = 31,
    RTC_3_IRQ                       = 32,
    WDT_IRQ                         = 33,
    WLAN_IRQ                        = 34,
    DMA_IRQ                         = 35,
    SFC_IRQ                         = 36,
    SDIO_IRQ                        = 37,
    UART_0_IRQ                      = 38,
    UART_1_IRQ                      = 39,
    UART_2_IRQ                      = 40,
    I2C_0_IRQ                       = 41,
    I2C_1_IRQ                       = 42,
    SSP_0_IRQ                       = 43,
    SSP_1_IRQ                       = 44,
    GPIO_IRQ                        = 45,
    TSENSOR_IRQ                     = 46,
    WLAN_SLEEP_IRQ                  = 47,
    WLAN_WAKEUPT_IRQ                = 48,
    OVER_TEMP_IRQ                   = 49,
    PMU_CMU_ERR_IRQ                 = 50,
    CPU_SOFT_0_IRQ                  = 51,
    CPU_SOFT_1_IRQ                  = 52,
    CPU_SOFT_2_IRQ                  = 53,
    CPU_SOFT_3_IRQ                  = 54,
    SSS_PKE_IRQ                     = 55,
    SSS_SYM_IRQ                     = 56,
    SSS_TRNG_IRQ                    = 57,
    ISADC_IRQ                       = 58,
    I2S_IRQ                         = 59,
    UDSLEEP_IRQ                     = 60,
    RAMMONITOR_IRQ                  = 61
} IRQn_Type;

#endif // __HI3861_H__

