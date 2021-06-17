/*------------------------------------------------------------------------------
  LIDARLite_v3 Raspberry Pi Library

  This library provides quick access to basic functions of the LIDAR-Lite
  via the Raspberry Pi interface. Additionally, it can provide a user of any
  platform with a template for their own application code.

  Copyright (c) 2019 Garmin Ltd. or its subsidiaries.
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
  http://www.apache.org/licenses/LICENSE-2.0
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
------------------------------------------------------------------------------*/

#ifndef LIDARLite_v3_h_wrapper
#define LIDARLite_v3_h_wrapper

#ifdef __cplusplus
extern "C" {
#endif
    
struct lidar;
typedef struct lidar lidar_t;

lidar_t *lidar_create();
void lidar_destroy(lidar_t *l);

__s32     lidar_i2c_init                      (lidar_t *l);
__s32     lidar_i2c_connect                   (lidar_t *l);
__s32     lidar_i2c_connect_customAddress     (lidar_t *l, __u8 lidarliteAddress);
void      lidar_configure                     (lidar_t *l);
void      lidar_configure_mode                (lidar_t *l, __u8 configuration);
void      lidar_configure_customAddress       (lidar_t *l, __u8 lidarliteAddress);
void      lidar_configure_mode_customAddress  (lidar_t *l, __u8 configuration , __u8 lidarliteAddress);
void      lidar_setI2Caddr                    (lidar_t *l, __u8 newAddress, __u8 disableDefault);
void      lidar_setI2Caddr_customAddress      (lidar_t *l, __u8 newAddress, __u8 disableDefault, __u8 lidarliteAddress);
__u16     lidar_readDistance                  (lidar_t *l);
__u16     lidar_readDistance_customAddress    (lidar_t *l, __u8 lidarliteAddress);
void      lidar_waitForBusy                   (lidar_t *l);
void      lidar_waitForBusy_customAddress     (lidar_t *l, __u8 lidarliteAddress);
__u8      lidar_getBusyFlag                   (lidar_t *l);
__u8      lidar_getBusyFlag_customAddress     (lidar_t *l, __u8 lidarliteAddress);
void      lidar_takeRange                     (lidar_t *l);
void      lidar_takeRange_customAddress       (lidar_t *l, __u8 lidarliteAddress);
__s32     lidar_i2cWrite                      (lidar_t *l, __u8 regAddr, __u8 * dataBytes, __u8 numBytes);
__s32     lidar_i2cWrite_customAddress        (lidar_t *l, __u8 regAddr, __u8 * dataBytes, __u8 numBytes, __u8 lidarliteAddress);
__s32     lidar_i2cRead                       (lidar_t *l, __u8 regAddr, __u8 * dataBytes, __u8 numBytes);
__s32     lidar_i2cRead_customAddress         (lidar_t *l, __u8 regAddr, __u8 * dataBytes, __u8 numBytes, __u8 lidarliteAddress);
void      lidar_correlationRecordRead         (lidar_t *l, __s16 * corrValues);
void      lidar_correlationRecordRead_num     (lidar_t *l, __s16 * corrValues, __u16 numberOfReadings);
void      lidar_correlationRecordRead_add     (lidar_t *l, __s16 * corrValues, __u8 lidarliteAddress);
void      lidar_correlationRecordRead_num_add (lidar_t *l, __s16 * corrValues, __u16 numberOfReadings, __u8 lidarliteAddress);

#ifdef __cplusplus
}
#endif

#endif
