/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/
#include "vsf.h"
#include <stdio.h>

/* IO definitions (access restrictions to peripheral registers) */
/**
    \defgroup CMSIS_glob_defs CMSIS Global Defines

    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

/*@} end of group Cortex_M0 */

/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
typedef struct
{
  __IOM  uint32_t  DATA;                     /* Offset: 0x000 (R/W) Data Register    */
  __IOM  uint32_t  STATE;                    /* Offset: 0x004 (R/W) Status Register  */
  __IOM  uint32_t  CTRL;                     /* Offset: 0x008 (R/W) Control Register */
  union {
    __IM   uint32_t  INTSTATUS;              /* Offset: 0x00C (R/ ) Interrupt Status Register */
    __OM   uint32_t  INTCLEAR;               /* Offset: 0x00C ( /W) Interrupt Clear Register  */
    };
  __IOM  uint32_t  BAUDDIV;                  /* Offset: 0x010 (R/W) Baudrate Divider Register */

} CMSDK_UART_TypeDef;

/* CMSDK_UART DATA Register Definitions */
#define CMSDK_UART_DATA_Pos               0                                                  /* CMSDK_UART_DATA_Pos: DATA Position */
#define CMSDK_UART_DATA_Msk              (0xFFUL /*<< CMSDK_UART_DATA_Pos*/)                 /* CMSDK_UART DATA: DATA Mask */

/* CMSDK_UART STATE Register Definitions */
#define CMSDK_UART_STATE_RXOR_Pos         3                                                  /* CMSDK_UART STATE: RXOR Position */
#define CMSDK_UART_STATE_RXOR_Msk        (0x1UL << CMSDK_UART_STATE_RXOR_Pos)                /* CMSDK_UART STATE: RXOR Mask */

#define CMSDK_UART_STATE_TXOR_Pos         2                                                  /* CMSDK_UART STATE: TXOR Position */
#define CMSDK_UART_STATE_TXOR_Msk        (0x1UL << CMSDK_UART_STATE_TXOR_Pos)                /* CMSDK_UART STATE: TXOR Mask */

#define CMSDK_UART_STATE_RXBF_Pos         1                                                  /* CMSDK_UART STATE: RXBF Position */
#define CMSDK_UART_STATE_RXBF_Msk        (0x1UL << CMSDK_UART_STATE_RXBF_Pos)                /* CMSDK_UART STATE: RXBF Mask */

#define CMSDK_UART_STATE_TXBF_Pos         0                                                  /* CMSDK_UART STATE: TXBF Position */
#define CMSDK_UART_STATE_TXBF_Msk        (0x1UL /*<< CMSDK_UART_STATE_TXBF_Pos*/)            /* CMSDK_UART STATE: TXBF Mask */

/* CMSDK_UART CTRL Register Definitions */
#define CMSDK_UART_CTRL_HSTM_Pos          6                                                  /* CMSDK_UART CTRL: HSTM Position */
#define CMSDK_UART_CTRL_HSTM_Msk         (0x01UL << CMSDK_UART_CTRL_HSTM_Pos)                /* CMSDK_UART CTRL: HSTM Mask */

#define CMSDK_UART_CTRL_RXORIRQEN_Pos     5                                                  /* CMSDK_UART CTRL: RXORIRQEN Position */
#define CMSDK_UART_CTRL_RXORIRQEN_Msk    (0x01UL << CMSDK_UART_CTRL_RXORIRQEN_Pos)           /* CMSDK_UART CTRL: RXORIRQEN Mask */

#define CMSDK_UART_CTRL_TXORIRQEN_Pos     4                                                  /* CMSDK_UART CTRL: TXORIRQEN Position */
#define CMSDK_UART_CTRL_TXORIRQEN_Msk    (0x01UL << CMSDK_UART_CTRL_TXORIRQEN_Pos)           /* CMSDK_UART CTRL: TXORIRQEN Mask */

#define CMSDK_UART_CTRL_RXIRQEN_Pos       3                                                  /* CMSDK_UART CTRL: RXIRQEN Position */
#define CMSDK_UART_CTRL_RXIRQEN_Msk      (0x01UL << CMSDK_UART_CTRL_RXIRQEN_Pos)             /* CMSDK_UART CTRL: RXIRQEN Mask */

#define CMSDK_UART_CTRL_TXIRQEN_Pos       2                                                  /* CMSDK_UART CTRL: TXIRQEN Position */
#define CMSDK_UART_CTRL_TXIRQEN_Msk      (0x01UL << CMSDK_UART_CTRL_TXIRQEN_Pos)             /* CMSDK_UART CTRL: TXIRQEN Mask */

#define CMSDK_UART_CTRL_RXEN_Pos          1                                                  /* CMSDK_UART CTRL: RXEN Position */
#define CMSDK_UART_CTRL_RXEN_Msk         (0x01UL << CMSDK_UART_CTRL_RXEN_Pos)                /* CMSDK_UART CTRL: RXEN Mask */

#define CMSDK_UART_CTRL_TXEN_Pos          0                                                  /* CMSDK_UART CTRL: TXEN Position */
#define CMSDK_UART_CTRL_TXEN_Msk         (0x01UL /*<< CMSDK_UART_CTRL_TXEN_Pos*/)            /* CMSDK_UART CTRL: TXEN Mask */

#define CMSDK_UART_INTSTATUS_RXORIRQ_Pos  3                                                  /* CMSDK_UART CTRL: RXORIRQ Position */
#define CMSDK_UART_CTRL_RXORIRQ_Msk      (0x01UL << CMSDK_UART_INTSTATUS_RXORIRQ_Pos)        /* CMSDK_UART CTRL: RXORIRQ Mask */

#define CMSDK_UART_CTRL_TXORIRQ_Pos       2                                                  /* CMSDK_UART CTRL: TXORIRQ Position */
#define CMSDK_UART_CTRL_TXORIRQ_Msk      (0x01UL << CMSDK_UART_CTRL_TXORIRQ_Pos)             /* CMSDK_UART CTRL: TXORIRQ Mask */

#define CMSDK_UART_CTRL_RXIRQ_Pos         1                                                  /* CMSDK_UART CTRL: RXIRQ Position */
#define CMSDK_UART_CTRL_RXIRQ_Msk        (0x01UL << CMSDK_UART_CTRL_RXIRQ_Pos)               /* CMSDK_UART CTRL: RXIRQ Mask */

#define CMSDK_UART_CTRL_TXIRQ_Pos         0                                                  /* CMSDK_UART CTRL: TXIRQ Position */
#define CMSDK_UART_CTRL_TXIRQ_Msk        (0x01UL /*<< CMSDK_UART_CTRL_TXIRQ_Pos*/)           /* CMSDK_UART CTRL: TXIRQ Mask */

/* CMSDK_UART BAUDDIV Register Definitions */
#define CMSDK_UART_BAUDDIV_Pos            0                                                  /* CMSDK_UART BAUDDIV: BAUDDIV Position */
#define CMSDK_UART_BAUDDIV_Msk           (0xFFFFFUL /*<< CMSDK_UART_BAUDDIV_Pos*/)           /* CMSDK_UART BAUDDIV: BAUDDIV Mask */


/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/* Peripheral and SRAM base address */
#define CMSDK_APB_BASE          (0x40000000UL)

#define CMSDK_UART0_BASE        (CMSDK_APB_BASE + 0x4000UL)
#define CMSDK_UART1_BASE        (CMSDK_APB_BASE + 0x5000UL)
#define CMSDK_UART2_BASE        (CMSDK_APB_BASE + 0x6000UL)



/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define CMSDK_UART0             ((CMSDK_UART_TypeDef              *) CMSDK_UART0_BASE       )
#define CMSDK_UART1             ((CMSDK_UART_TypeDef              *) CMSDK_UART1_BASE       )
#define CMSDK_UART2             ((CMSDK_UART_TypeDef              *) CMSDK_UART2_BASE       )



void uart_config(void)
{

    CMSDK_UART0->CTRL = 0;         /* Disable UART when changing configuration */
    CMSDK_UART0->BAUDDIV = 651;    /* 25MHz / 38400 = 651 */
    CMSDK_UART0->CTRL = CMSDK_UART_CTRL_TXEN_Msk|CMSDK_UART_CTRL_RXEN_Msk;  
}

void vsf_stdout_init(void)
{
    uart_config();
}

void vsf_stdin_init(void)
{

}

char vsf_stdin_getchar(void)
{
    while(!(CMSDK_UART0->STATE & CMSDK_UART_STATE_RXBF_Msk));
    return (char)(CMSDK_UART0->DATA);
}

int vsf_stdout_putchar(char txchar)
{
    if (txchar == 10) vsf_stdout_putchar((char) 13);

    while(CMSDK_UART0->STATE & CMSDK_UART_STATE_TXBF_Msk);
    CMSDK_UART0->DATA = (uint32_t)txchar;
    (*(volatile uint32_t *)0x41000000) = txchar;
    return (int) txchar;
}


