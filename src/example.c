/*------------------------------------------------------------------------------
  This example illustrates how to use the LIDAR-Lite library to gain quick
  access to the basic functions of LIDAR-Lite via the Raspberry Pi interface.
  Additionally, it provides users of any platform with a template for their
  own application code.
  
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

#include <linux/types.h>
#include <stdio.h>

#include "lidarlite_v3_wrapper.h"

int main()
{
    __u16 distance;
    __u8  busyFlag;
    
    lidar_t *myLidarLite = lidar_create();

    // Initialize i2c peripheral in the cpu core
    lidar_i2c_init(myLidarLite);

    // Optionally configure LIDAR-Lite
    lidar_configure_mode(myLidarLite, 4);

    while(1)
    {
        // Each time through the loop, check BUSY
        busyFlag = lidar_getBusyFlag(myLidarLite);

        if (busyFlag == 0x00)
        {
            // When no longer busy, immediately initialize another measurement
            // and then read the distance data from the last measurement.
            // This method will result in faster I2C rep rates.
            lidar_takeRange(myLidarLite);
            distance = lidar_readDistance(myLidarLite);

            printf("La distancia desde C es%4d\n", distance);
        }
    }
    
	lidar_destroy(myLidarLite);
}


/*
 * ================================================================
 * The set of instructions below illustrates one method of setting
 * an alternate I2C device address in the LIDAR-Lite v3. See the
 * operator manual and C++ libraries for further details.
 * ================================================================
 */

/*
#define i2cSecondaryAddr 0x44  // Set I2C address of LIDAR-Lite v3 to 0x44

int main()
{
    __u16 distance;

    // Initialize i2c peripheral in the cpu core
    lidar_i2c_init();

    // Set an alternate i2c address in the LIDAR-Lite
    // The 2nd argument, if non-zero, disables the default addr 0x62
    lidar_setI2Caddr(i2cSecondaryAddr, true);

    while(1)
    {
        lidar_waitForBusy(i2cSecondaryAddr);
        lidar_takeRange(i2cSecondaryAddr);
        distance      = lidar_readDistance(i2cSecondaryAddr);

        printf("%4d\n", distance);
    }
}
*/
