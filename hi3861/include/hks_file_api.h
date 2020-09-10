/**
 * @file hks_file_api.h
 *
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

/**
 * @defgroup iot_hks
 * @ingroup hks
 */

#ifndef _HKS_FILE_API_H
#define _HKS_FILE_API_H

#include <stdint.h>
#include "hks_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct hks_flash_operation_callbacks {
    /**
     * @ingroup  iot_hks
     * @brief Read data from flash. CNcomment:从flash读取数据。CNend
     *
     * @par 描述:
     *           Read data from flash. CNcomment:从flash读取数据。CNend
     *
     * @attention None
     * @param  buf    [OUT] type #uint8_t *，The buffer used to store the content readed from flash.
       CNcomment:用于存储从闪存读取的内容的缓冲区。CNend
     * @param  len    [IN] type #uint32_t，The size count in buffer trying to read from flash.
       CNcomment:尝试从闪存读取的缓冲区中的大小计数。CNend
     * @retval #0       Success.
     * @retval # < 0    Failure.
     * @par 依赖:
     *            @li hks_file_api.h：describes hks_types SDK interfaces.CNcomment:描述hks_types SDK的接口。CNend
     * @see read_flash
     */
    int32_t (*read_flash)(uint8_t *buf, uint32_t len);

    /**
     * @ingroup  iot_hks
     * @brief Write data into flash. CNcomment:将数据写入闪存。CNend
     *
     * @par 描述:
     *           Write data into flash. CNcomment:将数据写入闪存。CNend
     *
     * @attention None
     * @param  buf    [IN] type #uint8_t *，The content which you want write into the file.
       CNcomment:要写入文件的内容。CNend
     * @param  len    [IN] type #uint32_t，The size of the content.CNcomment:要写入的内容大小。CNend
     * @retval #0       Success.
     * @retval # < 0    Failure.
     * @par 依赖:
     *            @li hks_file_api.h：describes hks_types SDK interfaces.CNcomment:描述hks_types SDK的接口。CNend
     * @see read_flash
     */
    int32_t (*write_flash)(const uint8_t *buf, uint32_t len);
};

/**
* @ingroup  iot_hks
* @brief register flash operation callbacks. CNcomment:注册flash操作回调函数。CNend
*
* @par 描述:
*           register flash operation callbacks. CNcomment:注册flash操作回调函数。CNend
*
* @attention None
* @param  callbacks    [IN] type #struct hks_flash_operation_callbacks *，Registered callback function.
  CNcomment:注册的回调函数。CNend
* @retval #0       Success.
* @retval #Other   Failure.
* @par 依赖:
*            @li hks_file_api.h：describes hks_types SDK interfaces.CNcomment:描述hks_types SDK的接口。CNend
* @see hks_register_flash_operation_callbacks
*/
HKS_DLL_API_PUBLIC int32_t hks_register_flash_operation_callbacks(struct hks_flash_operation_callbacks *callbacks);

#ifdef __cplusplus
}
#endif

#endif /* _HKS_FILE_API_H */
