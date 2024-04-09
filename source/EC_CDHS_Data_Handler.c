/*Std includes*/
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include </usr/include/i2c/smbus.h>
#include <fcntl.h> // Include the necessary header file for 'open' function
#include <sys/ioctl.h> // Include the necessary header file for 'ioctl' function

//#include "../includes"

int main(int argc, char *argv[])
{
    int file;
    //using i2c-1
    int adapter_nr = 1;
    char filename[20];
    char buf[3];
    int mcp4725_addr = 0x62;

    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    file = open(filename, I2C_RDWR);
    if (file < 0)
    {
        printf("not found");
        exit(1);
    }

    //select the mcp4725 on the I2C bus
    if(ioctl(file, I2C_SLAVE, mcp4725_addr) < 0)
    {
        printf("\nslave not found\n");
        exit(1);
    }

    return 0;
}