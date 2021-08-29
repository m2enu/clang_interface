/**
 * @file    drv_can.c
 * @brief   CAN communication driver
 * @author  m2enu
 * @date    2021/08/29
 * @par     License
 *          https://github.com/m2enu/clang_interface/blob/main/LICENSE
 */
#include <stdio.h>
#include <stdint.h>
#include "drv_can.h"

static void canOpen(ICommunication * const);
static void canClose(ICommunication * const);

static const CommunicationMethods CAN_METHODS = {
    &canOpen,
    &canClose };

static void canOpen(ICommunication * const p_this)
{
    Can_t * const p = (Can_t * const)p_this;
    p->baudrate = 500u;
    printf("[I] canOpen: %d\n", p->baudrate);
}

static void canClose(ICommunication * const p_this)
{
    Can_t * const p = (Can_t * const)p_this;
    p->baudrate = 0u;
    printf("[I] canClose: %d\n", p->baudrate);
}

void CanNew(Can_t * const p_this)
{
    ((ICommunication *)p_this)->p_methods = &CAN_METHODS;
}
