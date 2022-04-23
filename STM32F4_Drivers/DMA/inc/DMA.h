#ifndef _DMA_H_
#define _DMA_H_

#include "DMA_Base.h"

/**
 * Function Prototypes
 */
void DMA_Init(void);
void DMA_Config (uint32_t srcAdd, uint32_t destAdd, uint16_t datasize);
void DMA1_Stream0_IRQHandler (void);

#endif	/* !(_DMA_H_) */
