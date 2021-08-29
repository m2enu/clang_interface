/**
 * @file    drv_can.h
 * @brief   CAN communication driver
 * @author  m2enu
 * @date    2021/08/29
 * @par     License
 *          https://github.com/m2enu/clang_interface/blob/main/LICENSE
 */
#ifndef DRV_CAN_H_INCLUDED
#define DRV_CAN_H_INCLUDED

#include <stdint.h>
#include "ICommunication.h"

typedef struct Can_t
{
    /* Public */
    ICommunication      Interface;

    /* Private */
    uint16_t            baudrate;
} Can_t;

void CanNew(Can_t * const);

#endif  /* DRV_CAN_H_INCLUDED */
