#include<stdint.h>
void Reset_Handler();
void Default_Handler();
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void NMI_Handler()__attribute__((weak,alias("Default_Handler")));

extern unsigned int _E_text;
extern unsigned int _S_Data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_Data;
extern int main(void);

static unsigned long Stack_top[256];
 void(*const g_p_fn_vectors[])() __attribute__((section(".vectors")))={
  (void(*)())((unsigned long)Stack_top+sizeof(Stack_top)),
  &Reset_Handler,
  &NMI_Handler,
  &H_fault_Handler,

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
