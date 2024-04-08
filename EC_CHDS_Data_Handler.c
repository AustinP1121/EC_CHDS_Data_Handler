/*Std includes*/
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/i2c/smbus.h>
#include <linux/i2c-dev.h>


int main()
{
    int file;
    //using i2c-1
    int adapter_nr = 1;
    char filename[20];
    char buf[3];
    int mcp4725_addr = 0x62;

    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    file = open(filename, 0_RDWR);
    if(file < 0)
    {
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