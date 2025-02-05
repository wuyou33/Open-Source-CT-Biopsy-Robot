#include "led.h"
#include "hwlib.h"
#include "soc_cv_av/socal/socal.h"
#include "soc_cv_av/socal/hps.h"
#include "soc_cv_av/socal/alt_gpio.h"
extern volatile unsigned long *h2p_lw_led_addr;
extern volatile unsigned long *h2p_lw_gpio_addr;

void LEDR_LightCount(unsigned char LightCount){ // 1: light, 0:unlight
    uint32_t Mask = 0;
    int i;
    for(i=0;i<LightCount;i++){
        Mask <<= 1;
        Mask |= 0x01;
    }
    //IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, Mask);  //0:ligh, 1:unlight
    alt_write_word(h2p_lw_led_addr, Mask );  //0:ligh, 1:unlight
}
void LEDR_OffCount(unsigned char OffCount){ // 1: light, 0:unlight
    uint32_t Mask = 0x03ff;
    int i;  
    for(i=0;i<OffCount;i++){
        Mask >>= 1;
    }
    //IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, Mask);  //0:ligh, 1:unlight
    alt_write_word(h2p_lw_led_addr, Mask );  //0:ligh, 1:unlight
}

void LEDR_AllOn(void)
{
	alt_write_word(h2p_lw_led_addr, 0b10000000);  //0:ligh, 1:unlight
	alt_write_word(h2p_lw_gpio_addr, 0b10000000);  //0:ligh, 1:unlight
}
void LEDR_AllOff(void)
{
	alt_write_word(h2p_lw_led_addr, 0xf3);  //0:ligh, 1:unlight
	alt_write_word(h2p_lw_gpio_addr, 0xf3);  //0:ligh, 1:unlight
}