#include "xparameters.h"
#include "xgpio.h"
#include "led_ip.h"
//====================================================

int main (void)
{

   XGpio dip, push;
   int i, psb_check, dip_check;

   xil_printf("-- Start of the Program --\r\n");

   XGpio_Initialize(&dip, XPAR_SWS_8BITS_DEVICE_ID); // Modify this
   XGpio_SetDataDirection(&dip, 1, 0xffffffff);

   XGpio_Initialize(&push, XPAR_BTNS_5BITS_DEVICE_ID); // Modify this
   XGpio_SetDataDirection(&push, 1, 0xffffffff);


   while (1)
   {
	  psb_check = XGpio_DiscreteRead(&push, 1);
	  xil_printf("Push Buttons Status %x\r\n", psb_check);
	  dip_check = XGpio_DiscreteRead(&dip, 1);
	  xil_printf("DIP Switch Status %x\r\n", dip_check);

	  // output dip switches value on LED_ip device
	  LED_IP_mWriteReg(XPAR_LED_IP_S_AXI_BASEADDR, 0, dip_check);
	  //reading the value of grayout,  LED_IP_S_AXI_SLV_REG1_OFFSET=4  4*8bytes after slv1
	  xil_printf("Current counter value: %x\r\n", LED_IP_mReadReg(XPAR_LED_IP_S_AXI_BASEADDR,LED_IP_S_AXI_SLV_REG1_OFFSET) );

	  	 // GRAY_IP_mWriteReg(XPAR_GRAY_IP_S_AXI_BASEADDR, 0, dip_check);

	  	 // Gray_current_value=GRAY_IP_mReadReg(XPAR_GRAY_IP_S_AXI_BASEADDR,0);


	  for (i=0; i<9999999; i++);
   }
}
