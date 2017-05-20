#include "beaglebone_gpio.h"

int main(int argc, char *argv[]) {
    volatile void *gpio_addr = NULL;
    volatile unsigned int *gpio_oe_addr = NULL;
    volatile unsigned int *gpio_setdataout_addr = NULL;
    volatile unsigned int *gpio_cleardataout_addr = NULL;
    unsigned int reg;

  int fd = open("/dev/mem", O_RDWR);
    gpio_addr = mmap(0, GPIO1_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO1_START_ADDR);
    gpio_oe_addr = gpio_addr + GPIO_OE;
    gpio_setdataout_addr = gpio_addr + GPIO_SETDATAOUT;
    gpio_cleardataout_addr = gpio_addr + GPIO_CLEARDATAOUT;

    if(gpio_addr == MAP_FAILED) {
        exit(1);
    }

    reg = *gpio_oe_addr;
    reg = reg & (0xFFFFFFFF - PIN);
    *gpio_oe_addr = reg;
    while(1) {

        *gpio_setdataout_addr= PIN; //HIGH
        *gpio_cleardataout_addr = PIN; //LOW
      }

    close(fd);
    return 0;
}
