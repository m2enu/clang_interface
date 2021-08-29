/**
 * @file    ICommunication.c
 * @brief   Interface for communication protocols
 * @author  m2enu
 * @date    2021/08/29
 * @par     License
 *          https://github.com/m2enu/clang_interface/blob/main/LICENSE
 */
#include <stdint.h>
#include <stddef.h>
#include "ICommunication.h"

#define IS_NULL(p)          ((p) == NULL)

void IC_Open(ICommunication * const p_this)
{
    if (IS_NULL(p_this) ||
        IS_NULL(p_this->p_methods) ||
        IS_NULL(p_this->p_methods->open))
    {
        return;
    }
    p_this->p_methods->open(p_this);
}

void IC_Close(ICommunication * const p_this)
{
    if (IS_NULL(p_this) ||
        IS_NULL(p_this->p_methods) ||
        IS_NULL(p_this->p_methods->close))
    {
        return;
    }
    p_this->p_methods->close(p_this);
}
