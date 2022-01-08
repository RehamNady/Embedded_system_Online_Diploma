#include<stdint.h>
void Reset_Handler();
void Default_Handler();
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void NM_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void BUs_Fault()__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__((weak,alias("Default_Handler")));
extern unsigned int _stack_top;
extern unsigned int _E_text;
extern unsigned int _S_Data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_Data;
extern int main(void);
uint32_t vectors[] __attribute__((section(".vectors")))={
  (uint32_t) &_stack_top,
  (uint32_t) &Reset_Handler,
  (uint32_t) &NMI_Handler,
  (uint32_t) &H_fault_Handler,
  (uint32_t) &NM_fault_Handler,
  (uint32_t) &BUs_Fault,
  (uint32_t) &Usage_Fault_Handler,

};
void Reset_Handler(){
  //copy .data SECTIONS
  int i ;
  unsigned int Data_Size= (unsigned char*)&_E_Data - (unsigned char*)&_S_Data;
  unsigned char * p_src = (unsigned char*)&_E_text;
  unsigned char * p_dest = (unsigned char*)&_S_Data;
  for(i=0;i<Data_Size;i++){
    *((unsigned char *)p_dest++) = *((unsigned char *)p_src++);
  }

  //initialize .bss section
  unsigned int bss_Size= (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
  p_dest = (unsigned char*)&_S_bss;
  for(i=0;i<bss_Size;i++){
    *((unsigned char *)p_dest++) = (unsigned char)0;
  }
  main();
}
void Default_Handler(){
  Reset_Handler();
}
