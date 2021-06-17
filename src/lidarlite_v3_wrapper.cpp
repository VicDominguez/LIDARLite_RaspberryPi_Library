/*------------------------------------------------------------------------------
  LIDARLite_v3 C Wrapper Raspberry Pi Library

  Realised by Victor Manuel Dominguez Rivas using this tutorial:
  https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/
------------------------------------------------------------------------------*/


#include <linux/types.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <cstddef>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "lidarlite_v3.h"
#include "lidarlite_v3_wrapper.h"

/*------------------------------------------------------------------------------
  Lidar struct and create and destroy functions
------------------------------------------------------------------------------*/

struct lidar 
{
	void *obj;
};


lidar_t *lidar_create()
{
	lidar_t *l;
	LIDARLite_v3 *obj;

	l      = (typeof(l))malloc(sizeof(*l));
	obj    = new LIDARLite_v3();
	l->obj = obj;

	return l;
}

void lidar_destroy(lidar_t *l)
{
	if (l == NULL)
		return;
	
  delete static_cast<LIDARLite_v3 *>(l->obj);
	free(l);
}

/*------------------------------------------------------------------------------
  I2C Init
  Initialize the I2C peripheral in the processor core
------------------------------------------------------------------------------*/
__s32 lidar_i2c_init (lidar_t *l)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return -1;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	return obj->i2c_init();
}

/*------------------------------------------------------------------------------
  I2C Connect
  Connect to the I2C device with the specified device address

  Parameters
  ------------------------------------------------------------------------------
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
__s32 lidar_i2c_connect (lidar_t *l )
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return -1;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	return obj->i2c_connect();
}

__s32 lidar_i2c_connect_customAddress(lidar_t *l, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return -1;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  return obj->i2c_connect(lidarliteAddress);
}

/*------------------------------------------------------------------------------
  Configure
  Selects one of several preset configurations.

  Parameters
  ------------------------------------------------------------------------------
  configuration:  Default 0.
    0: Default mode, balanced performance.
    1: Short range, high speed. Uses 0x1d maximum acquisition count.
    2: Default range, higher speed short range. Turns on quick termination
        detection for faster measurements at short range (with decreased
        accuracy)
    3: Maximum range. Uses 0xff maximum acquisition count.
    4: High sensitivity detection. Overrides default valid measurement detection
        algorithm, and uses a threshold value for high sensitivity and noise.
    5: Low sensitivity detection. Overrides default valid measurement detection
        algorithm, and uses a threshold value for low sensitivity and noise.
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
void lidar_configure(lidar_t *l)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	obj->configure();
   
}

void lidar_configure_mode(lidar_t *l, __u8 configuration)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->configure(configuration);
   
} 

void lidar_configure_customAddress(lidar_t *l, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->configure(0, lidarliteAddress);
   
}

void lidar_configure_mode_customAddress(lidar_t *l, __u8 configuration , __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->configure(configuration, lidarliteAddress);
   
}



/*------------------------------------------------------------------------------
  Set I2C Address
  Set Alternate I2C Device Address. See Operation Manual for additional info.

  Parameters
  ------------------------------------------------------------------------------
  newAddress: desired secondary I2C device address
  disableDefault: a non-zero value here means the default 0x62 I2C device
    address will be disabled.
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
void lidar_setI2Caddr(lidar_t *l, __u8 newAddress, __u8 disableDefault)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->setI2Caddr(newAddress, disableDefault);
}

void lidar_setI2Caddr_customAddress(lidar_t *l, __u8 newAddress, __u8 disableDefault, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->setI2Caddr(newAddress, disableDefault, lidarliteAddress);
}

/*------------------------------------------------------------------------------
  Take Range
  Initiate a distance measurement by writing to register 0x00.

  Parameters
  ------------------------------------------------------------------------------
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
void lidar_takeRange(lidar_t *l)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->takeRange();
}

void lidar_takeRange_customAddress(lidar_t *l, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->takeRange(lidarliteAddress);
}

/*------------------------------------------------------------------------------
  Wait for Busy Flag
  Blocking function to wait until the Lidar Lite's internal busy flag goes low

  Parameters
  ------------------------------------------------------------------------------
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
void lidar_waitForBusy(lidar_t *l)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	obj->waitForBusy();
}

void lidar_waitForBusy_customAddress(lidar_t *l, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->waitForBusy(lidarliteAddress);
} 

/*------------------------------------------------------------------------------
  Get Busy Flag
  Read BUSY flag from device registers. Function will return 0x00 if not busy.

  Parameters
  ------------------------------------------------------------------------------
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
__u8 lidar_getBusyFlag(lidar_t *l)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return 0;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	return obj->getBusyFlag();
}

__u8 lidar_getBusyFlag_customAddress(lidar_t *l, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return 0;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  return obj->getBusyFlag(lidarliteAddress);
}

/*------------------------------------------------------------------------------
  Read Distance
  Read and return result of distance measurement.

  Parameters
  ------------------------------------------------------------------------------
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
__u16 lidar_readDistance(lidar_t *l)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return 0;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	return obj->readDistance();
}

__u16 lidar_readDistance_customAddress(lidar_t *l, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return 0;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  return obj->readDistance(lidarliteAddress);
}

/*------------------------------------------------------------------------------
  Write
  Perform I2C write to device.

  Parameters
  ------------------------------------------------------------------------------
  regAddr:   register address to write to
  dataBytes: pointer to data bytes to write
  numBytes:  number of bytes to write
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
__s32 lidar_i2cWrite(lidar_t *l, __u8 regAddr,  __u8 * dataBytes, __u8 numBytes)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return -1;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	return obj->i2cWrite(regAddr,dataBytes,numBytes);
} 

__s32 lidar_i2cWrite_customAddress(lidar_t *l, __u8 regAddr,  __u8 * dataBytes,
                             __u8 numBytes, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return -1;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  return obj->i2cWrite(regAddr,dataBytes,numBytes, lidarliteAddress);
} 

/*------------------------------------------------------------------------------
  Read
  Perform I2C read from device.

  Parameters
  ------------------------------------------------------------------------------
  regAddr:   register address to write to
  dataBytes: pointer to array to place read bytes
  numBytes:  number of bytes in 'dataBytes' array to read (32 bytes max)
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
  operating manual for instructions.
------------------------------------------------------------------------------*/
__s32 lidar_i2cRead(lidar_t *l, __u8 regAddr,  __u8 * dataBytes, __u8 numBytes)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return -1;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	return obj->i2cRead(regAddr,dataBytes,numBytes);
}

__s32 lidar_i2cRead_customAddress(lidar_t *l, __u8 regAddr,  __u8 * dataBytes,
                            __u8 numBytes, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return -1;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  return obj->i2cRead(regAddr,dataBytes,numBytes, lidarliteAddress);
} 

/*------------------------------------------------------------------------------
  Correlation Record Read
  The correlation record used to calculate distance can be read from the device.
  It has a bipolar wave shape, transitioning from a positive going portion to a
  roughly symmetrical negative going pulse. The point where the signal crosses
  zero represents the effective delay for the reference and return signals.

  Process
  ------------------------------------------------------------------------------
  1.  Take a distance reading (there is no correlation record without at least
      one distance reading being taken)
  2.  Set test mode select by writing 0x07 to register 0x40
  3.  For as many points as you want to read from the record (max is 1024) ...
      1.  Read two bytes from 0x52
      2.  The Low byte is the value from the record
      3.  The high byte is the sign from the record

  Parameters
  ------------------------------------------------------------------------------
  correlationArray: pointer to memory location to store the correlation record
                    ** Two bytes for every correlation value must be
                       allocated by calling function
  numberOfReadings: Default = 256. Maximum = 1024
  lidarliteAddress: Default 0x62. Fill in new address here if changed. See
    operating manual for instructions.
------------------------------------------------------------------------------*/
void lidar_correlationRecordRead(lidar_t *l, __s16 * correlationArray)
{
  LIDARLite_v3 *obj;

	if (l == NULL)
		return;

	obj = static_cast<LIDARLite_v3 *>(l->obj);
	obj->correlationRecordRead(correlationArray);
    
}

void lidar_correlationRecordRead_num(lidar_t *l, __s16 * correlationArray, __u16 numberOfReadings)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->correlationRecordRead(correlationArray, numberOfReadings);
    
}

void lidar_correlationRecordRead_add(lidar_t *l, __s16 * correlationArray, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->correlationRecordRead(correlationArray, 256, lidarliteAddress);
    
}

void lidar_correlationRecordRead_num_add(lidar_t *l, __s16 * correlationArray, __u16 numberOfReadings, __u8 lidarliteAddress)
{
  LIDARLite_v3 *obj;

  if (l == NULL)
    return;

  obj = static_cast<LIDARLite_v3 *>(l->obj);
  obj->correlationRecordRead(correlationArray, numberOfReadings, lidarliteAddress);
    
}
