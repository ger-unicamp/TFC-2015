/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RxBuf.h
**     Project     : Camera_com_Lag
**     Processor   : MKL25Z128VLK4
**     Component   : RingBufferUInt8
**     Version     : Component 01.003, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-10-06, 13:33, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**          Component name                                 : RxBuf
**          Buffer Size                                    : 64
**     Contents    :
**         Put             - byte RxBuf_Put(byte elem);
**         Get             - byte RxBuf_Get(byte *elemP);
**         NofElements     - byte RxBuf_NofElements(void);
**         NofFreeElements - byte RxBuf_NofFreeElements(void);
**         Init            - void RxBuf_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file RxBuf.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup RxBuf_module RxBuf module documentation
**  @{
*/         

#ifndef __RxBuf_H
#define __RxBuf_H

/* MODULE RxBuf. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"


#define RxBuf_BUF_SIZE   64  /* number of elements in the buffer */


byte RxBuf_Put(byte elem);
/*
** ===================================================================
**     Method      :  RxBuf_Put (component RingBufferUInt8)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RxBuf_Get(byte *elemP);
/*
** ===================================================================
**     Method      :  RxBuf_Get (component RingBufferUInt8)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RxBuf_NofElements(void);
/*
** ===================================================================
**     Method      :  RxBuf_NofElements (component RingBufferUInt8)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void RxBuf_Init(void);
/*
** ===================================================================
**     Method      :  RxBuf_Init (component RingBufferUInt8)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

byte RxBuf_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  RxBuf_NofFreeElements (component RingBufferUInt8)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

/* END RxBuf. */

#endif
/* ifndef __RxBuf_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
