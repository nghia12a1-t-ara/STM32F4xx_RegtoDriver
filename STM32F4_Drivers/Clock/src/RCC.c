/**
 * Filename		: RCC.c
 * Author		: Nghia Taarabt
 * Create Date 	: 18/12/22
 * Brief		: Clock driver header file
 */

#include "RCC.h"

uint16 AHB_PreScaler[8] = { 2, 4, 8, 16, 64, 128, 256, 512 };
uint8 APB1_PreScaler[4] = { 2, 4, 8, 16 };


uint32 RCC_GetPCLK1Value(void)
{
	uint32 pclk1,SystemClk;

	uint8 clksrc,temp,ahbp,apb1p;

	clksrc = ((RCC->CFGR >> 2) & 0x3);

	if(clksrc == 0 )
	{
		SystemClk = 16000000;
	}else if(clksrc == 1)
	{
		SystemClk = 8000000;
	}else if (clksrc == 2)
	{
		SystemClk = RCC_GetPLLOutputClock();
	}

	//for ahb
	temp = ((RCC->CFGR >> 4 ) & 0xF);

	if(temp < 8)
	{
		ahbp = 1;
	}else
	{
		ahbp = AHB_PreScaler[temp-8];
	}



	//apb1
	temp = ((RCC->CFGR >> 10 ) & 0x7);

	if(temp < 4)
	{
		apb1p = 1;
	}else
	{
		apb1p = APB1_PreScaler[temp-4];
	}

	pclk1 =  (SystemClk / ahbp) /apb1p;

	return pclk1;
}



/*********************************************************************
 * @fn      		  - RCC_GetPCLK2Value
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint32 RCC_GetPCLK2Value(void)
{
	uint32 SystemClock = 0, tmp = 0, pclk2 = 0;
	uint8 clk_src = ( RCC->CFGR >> 2) & 0X3;

	uint8 ahbp,apb2p;

	if(clk_src == 0)
	{
		SystemClock = 16000000;
	}else
	{
		SystemClock = 8000000;
	}

	if(tmp < 0x08)
	{
		ahbp = 1;
	}else
	{
       ahbp = AHB_PreScaler[tmp-8];
	}

	tmp = (RCC->CFGR >> 13 ) & 0x7;
	if(tmp < 0x04)
	{
		apb2p = 1;
	}else
	{
		apb2p = APB1_PreScaler[tmp-4];
	}

	pclk2 = (SystemClock / ahbp )/ apb2p;

	return pclk2;
}

uint32 RCC_GetPLLOutputClock()
{

	return 0;
}

