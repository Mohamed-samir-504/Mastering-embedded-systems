

#include "STM32F103C6_GPIO_driver.h"
#include "STM32F103x6.h"


#define SEG_PORT GPIOB

//#define ZERO  0x01
//#define ONE   0x79
//#define TWO   0x24
//#define THREE 0x30
//#define FOUR  0x4C
//#define FIVE  0x12
//#define SIX   0x02
//#define SEVEN 0x19
//#define EIGHT 0x00
//#define NINE  0x10

#define zero 	0x01
#define one 	0x79
#define two 	0x24
#define three 	0x30
#define four 	0x98
#define five 	0x12
#define six	 	0x02
#define seven 	0x19
#define eight 	0x00
#define nine 	0x10

void SEG_init(void);
void SEG_clear(void);
void SEG_Write_Number(uint8_t num);
