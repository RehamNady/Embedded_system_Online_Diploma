
#include<stdint.h>

extern unsigned int _stack_top;
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern main(void);

void Reset_Handler();
void Default_Handler();
void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void MM_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void BUS_Fault()__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__((weak,alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".vectors"))) ={
     (uint32_t) &_stack_top,
     (uint32_t) &Reset_Handler,
     (uint32_t) &NMI_Handler,
     (uint32_t) &H_fault_Handler,
     (uint32_t) &MM_fault_Handler,
     (uint32_t) &BUS_Fault,
     (uint32_t) &Usage_Fault_Handler,
};

void Reset_Handler(){
  int i=0;
  // copy . data section from flash to sram
  unsigned int Data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
  unsigned char * p_src = (unsigned char*)&_E_text;
  unsigned char * p_dst = (unsigned char*)&_S_data;
  for(i=0;i<Data_size;i++){
    *((unsigned char *)p_dst++) = *((unsigned char *)p_src++);
  }
  // initilaize . bss section
  unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
  p_dst = (unsigned char*)&_S_bss;
  for(i=0;i<bss_size;i++){
    *((unsigned char *)p_dst++) = (unsigned char)0;
  }
  // branch to main
  main();
}
void Default_Handler(){
  Reset_Handler();
}
