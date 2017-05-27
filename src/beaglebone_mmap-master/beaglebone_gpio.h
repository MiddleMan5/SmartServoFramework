#ifndef _BEAGLEBONE_GPIO_H_
#define _BEAGLEBONE_GPIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 *  Base addresses for GPIO blocks in memory
 *  GPIO numbers 0-31 located at memory address 0x44e07000
 *  GPIO numbers 32-63 located at 0x4804c000
 *  GPIO numbers 64-95 located at 0x481ac000
 *  GPIO numbers 96-127 located at 0x481ae000
 */

 //I haven't delved into the code, but this sets up GPIO60 for switching

#define GPIO1_START_ADDR 0x4804C000 //GPIO1 Block Start
#define GPIO1_END_ADDR 0x4804DFFF
#define GPIO1_SIZE (GPIO1_END_ADDR - GPIO1_START_ADDR)
#define GPIO_OE 0x134
#define GPIO_SETDATAOUT 0x194
#define GPIO_CLEARDATAOUT 0x190


#define PIN (1<<28)


#endif
