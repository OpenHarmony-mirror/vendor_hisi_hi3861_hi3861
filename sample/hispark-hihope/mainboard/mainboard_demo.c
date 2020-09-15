/*
 * Copyright (c) 2020, HiHope Community.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>

#include <unistd.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"

#define LED_DELAY_TIME_US 300000
#define LED_YIELD_TIME_US 10000
#define LED_TASK_STACK_SIZE 512
#define LED_TASK_PRIO 25

#define LED_PIN_NAME WIFI_IOT_IO_NAME_GPIO_9
#define LED_BRIGHT WIFI_IOT_GPIO_VALUE0
#define LED_DARK WIFI_IOT_GPIO_VALUE1

#define BTN_PIN_NAME WIFI_IOT_IO_NAME_GPIO_5

static void *LedTask(const char *arg)
{
    (void)arg;

    for (int i = 0; i < 3; i++) {
        GpioSetOutputVal(LED_PIN_NAME, LED_BRIGHT);
        usleep(LED_DELAY_TIME_US);
        GpioSetOutputVal(LED_PIN_NAME, LED_DARK);
        usleep(LED_DELAY_TIME_US);
    }
    return NULL;
}

static void OnButtonPressed(char *arg)
{
    (void) arg;
    static WifiIotGpioValue ledState = LED_DARK;

    switch (ledState) {
        case LED_BRIGHT:
            ledState = LED_DARK;
            break;
        case LED_DARK:
            ledState = LED_BRIGHT;
            break;
        default:
            break;
    }
    GpioSetOutputVal(LED_PIN_NAME, ledState);
}

static void MainBoardDemo(void)
{
    osThreadAttr_t attr;

    GpioInit();
    IoSetFunc(LED_PIN_NAME, WIFI_IOT_IO_FUNC_GPIO_9_GPIO);
    GpioSetDir(LED_PIN_NAME, WIFI_IOT_GPIO_DIR_OUT);

    IoSetFunc(BTN_PIN_NAME, WIFI_IOT_IO_FUNC_GPIO_5_GPIO);
    GpioRegisterIsrFunc(BTN_PIN_NAME, WIFI_IOT_INT_TYPE_EDGE, WIFI_IOT_GPIO_EDGE_FALL_LEVEL_LOW,
        OnButtonPressed, NULL);

    attr.name = "LedTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = LED_TASK_STACK_SIZE;
    attr.priority = LED_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)LedTask, NULL, &attr) == NULL) {
        printf("[MainBoardDemo] Falied to create LedTask!\n");
    }
}

APP_FEATURE_INIT(MainBoardDemo);
