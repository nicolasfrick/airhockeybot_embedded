/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Tx1.h
**     Project     : Landungsbruecke_KDS_v2.0.0
**     Processor   : MK20DN512VLL10
**     Component   : RingBuffer
**     Version     : Component 01.025, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-09, 16:27, # CodeGen: 0
**     Abstract    :
**         This component implements a ring buffer for different integer data type.
**     Settings    :
**          Component name                                 : Tx1
**          Buffer Size                                    : 1
**     Contents    :
**         Clear           - void Tx1_Clear(void);
**         Put             - byte Tx1_Put(Tx1_ElementType elem);
**         Get             - byte Tx1_Get(Tx1_ElementType *elemP);
**         NofElements     - Tx1_BufSizeType Tx1_NofElements(void);
**         NofFreeElements - Tx1_BufSizeType Tx1_NofFreeElements(void);
**         Init            - void Tx1_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014, all rights reserved.
**     Web: http://www.mcuoneclipse.com
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file Tx1.h
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/
/*!
**  @addtogroup Tx1_module Tx1 module documentation
**  @{
*/

#ifndef __Tx1_H
#define __Tx1_H

/* MODULE Tx1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "MK20D10.h"
/* Include inherited beans */
#include "CS1.h"

//#include "Cpu.h"


#define Tx1_BUF_SIZE   64   /* number of elements in the buffer */
#define Tx1_ELEM_SIZE   1  /* size of a single element in bytes */
  #define Tx1_IS_REENTRANT   0  /* 0: Critical section NOT used for accessing shared data, 1 otherwise  */
#if Tx1_ELEM_SIZE==1
  typedef uint8 Tx1_ElementType; /* type of single element */
#elif Tx1_ELEM_SIZE==2
  typedef uint16 Tx1_ElementType; /* type of single element */
#elif Tx1_ELEM_SIZE==4
  typedef uint32 Tx1_ElementType; /* type of single element */
#else
  #error "illegal element type size in properties"
#endif
#if Tx1_BUF_SIZE<=256
  typedef uint8 Tx1_BufSizeType; /* up to 256 elements (index 0x00..0xFF) */
#else
  typedef uint16 Tx1_BufSizeType; /* more than 256 elements, up to 2^16 */
#endif

byte Tx1_Put(Tx1_ElementType elem);
/*
** ===================================================================
**     Method      :  Tx1_Put (component RingBuffer)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte Tx1_Get(Tx1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  Tx1_Get (component RingBuffer)
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

Tx1_BufSizeType Tx1_NofElements(void);
/*
** ===================================================================
**     Method      :  Tx1_NofElements (component RingBuffer)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void Tx1_Init(void);
/*
** ===================================================================
**     Method      :  Tx1_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

Tx1_BufSizeType Tx1_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  Tx1_NofFreeElements (component RingBuffer)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void Tx1_Clear(void);
/*
** ===================================================================
**     Method      :  Tx1_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Tx1. */

#endif
/* ifndef __Tx1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.11]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
