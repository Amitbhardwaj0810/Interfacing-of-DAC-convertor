// Code for Method 1
#include <reg51.h>
sfr DAC = 0xA0; // Port P2 address
void main()
{
    int sin_value[12] = (128, 192, 238, 255, 238, 192, 128, 64, 17, 0, 17, 64);
    int i;
    while (1)
    {
        for (i = 0; i < 12; i++)
        {
            DAC = sin_value[i];
        }
    }
}

// Code for Method 2
#include <reg51.h>
unsigned int array1[8] = {0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff};
void delay(unsigned int);
sbit l1 = P1 ^ 0;
sbit l2 = P1 ^ 1;
sbit l3 = P1 ^ 2;
sbit l4 = P1 ^ 3;
sbit l5 = P1 ^ 4;
sbit l6 = P1 ^ 5;
sbit l7 = P1 ^ 6;
sbit l8 = P1 ^ 7;
int main()
{
    unsigned int i;
    P1 = 0xff;
    for (i = 0; i < 9; i++)
    {
        P1 = array1[i];
        delay(100000);
        ACC = P1;
        P3 = ACC;
        delay(500000);
    }
}
void delay(unsigned int count)
{
    unsigned int i;
    for (i = 0; i <= count; i++);
}
