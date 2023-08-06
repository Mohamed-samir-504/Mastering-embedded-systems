//startup.c by Mohamed samir


#include <stdint.h>
#define STACK_Start_SP 0x20001000
extern int main(void);

void reset_handler (void) ;
void Default_Handler()
{
reset_handler() ;
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void MM_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_Fault(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;

extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_Text;
extern unsigned int _stack_top ;

static unsigned long stack_top[256];
void (* const vectors[])()__attribute__((section(".vectors"))) = 
{
  (void(*)()) ((unsigned long)stack_top + sizeof(stack_top)) , 
  &reset_handler , 
  &NMI_Handler , 
  &H_fault_Handler , 
  &MM_Fault_Handler ,
  &Bus_Fault ,
  &Usage_Fault_Handler ,
};

void reset_handler (void)
{


  unsigned int DATA_SIZE= (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
  unsigned char *P_SRC=(unsigned char *)&_E_Text;
  unsigned char *P_dst=(unsigned char *)&_S_DATA;

  for(int i=0;i<DATA_SIZE;i++)
  {

     *((unsigned char*)P_dst++)=*((unsigned char*)P_SRC++);

  } 


unsigned int bss_size=(unsigned char *)&_E_bss - (unsigned  char *)&_S_bss ;
P_dst=(unsigned char *)&_S_bss;

for(int i=0;i<bss_size;i++)
  {

     *((unsigned char*)P_dst++)=(unsigned char)0;

  } 


main();
}
