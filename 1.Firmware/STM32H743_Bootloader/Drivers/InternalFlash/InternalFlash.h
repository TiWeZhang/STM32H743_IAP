/*
 * @FilePath: \STM32H743_Bootloader\Drivers\InternalFlash\InternalFlash.h
 * @Author: MaxDYi
 * @Date: 2024-01-16 16:32:07
 * @LastEditors: MaxDYi
 * @LastEditTime: 2024-01-19 11:11:37
 * @Description:  内部FLash读、写、擦除操作库
 */

#ifndef _INTERNALFLASH_H_
#define _INTERNALFLASH_H_

#include "main.h"
#include "string.h"

#define CPU_FLASH_BASE_ADDR (uint32_t)(FLASH_BASE) /* 0x08000000 */
#define CPU_FLASH_END_ADDR (uint32_t)(0x081FFFFF)

#define CPU_FLASH_SIZE (2 * 1024 * 1024)   /* FLASH总容量 */
#define CPU_FLASH_SECTOR_SIZE (128 * 1024) /* 扇区大小，字节 */

/* Base address of the Flash sectors Bank 1 */
#define ADDR_FLASH_SECTOR_0_BANK1 ((uint32_t)0x08000000) /* Base @ of Sector 0, 128 Kbytes */
#define ADDR_FLASH_SECTOR_1_BANK1 ((uint32_t)0x08020000) /* Base @ of Sector 1, 128 Kbytes */
#define ADDR_FLASH_SECTOR_2_BANK1 ((uint32_t)0x08040000) /* Base @ of Sector 2, 128 Kbytes */
#define ADDR_FLASH_SECTOR_3_BANK1 ((uint32_t)0x08060000) /* Base @ of Sector 3, 128 Kbytes */
#define ADDR_FLASH_SECTOR_4_BANK1 ((uint32_t)0x08080000) /* Base @ of Sector 4, 128 Kbytes */
#define ADDR_FLASH_SECTOR_5_BANK1 ((uint32_t)0x080A0000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6_BANK1 ((uint32_t)0x080C0000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7_BANK1 ((uint32_t)0x080E0000) /* Base @ of Sector 7, 128 Kbytes */

/* Base address of the Flash sectors Bank 2 */
#define ADDR_FLASH_SECTOR_0_BANK2 ((uint32_t)0x08100000) /* Base @ of Sector 0, 128 Kbytes */
#define ADDR_FLASH_SECTOR_1_BANK2 ((uint32_t)0x08120000) /* Base @ of Sector 1, 128 Kbytes */
#define ADDR_FLASH_SECTOR_2_BANK2 ((uint32_t)0x08140000) /* Base @ of Sector 2, 128 Kbytes */
#define ADDR_FLASH_SECTOR_3_BANK2 ((uint32_t)0x08160000) /* Base @ of Sector 3, 128 Kbytes */
#define ADDR_FLASH_SECTOR_4_BANK2 ((uint32_t)0x08180000) /* Base @ of Sector 4, 128 Kbytes */
#define ADDR_FLASH_SECTOR_5_BANK2 ((uint32_t)0x081A0000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6_BANK2 ((uint32_t)0x081C0000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7_BANK2 ((uint32_t)0x081E0000) /* Base @ of Sector 7, 128 Kbytes */

#define FLASH_IS_EQU 0    /* Flash内容和待写入的数据相等，不需要擦除和写操作 */
#define FLASH_REQ_WRITE 1 /* Flash不需要擦除，直接写 */
#define FLASH_REQ_ERASE 2 /* Flash需要先擦除,再写 */
#define FLASH_PARAM_ERR 3 /* 函数参数错误 */

uint8_t ReadCpuFlash(uint32_t _ulFlashAddr, uint8_t *_ucpDst, uint32_t _ulSize);
uint8_t WriteCpuFlash(uint32_t _ulFlashAddr, uint8_t *_ucpSrc, uint32_t _ulSize);
uint8_t CmpCpuFlash(uint32_t _ulFlashAddr, uint8_t *_ucpBuf, uint32_t _ulSize);

uint8_t EraseCpuFlash(uint32_t _ulFlashAddr);

#endif
