#include <stdio.h>
#include <intrin.h>
int main(void){
    int cpuInfo[4] = { 0, 0, 0, 0 };
    __cpuid(cpuInfo, 0);
    if(cpuInfo[0] >= 0x16){
        __cpuid(cpuInfo, 0x16);
        printf("EAX: 0x%08x EBX: 0x%08x ECX: 0x%08x\r\n", cpuInfo[0], cpuInfo[1], cpuInfo[2]);
        printf("Processor Base Frequency: %04d MHz\r\n", cpuInfo[0]);
        printf("Maximum Frequency: %04d MHz\r\n", cpuInfo[1]);
        printf("Bus (Reference) Frequency: %04d MHz\r\n", cpuInfo[2]);
    } 
    else{
        printf("CPUID level 16h unsupported\r\n");
    }
    return 0;
}