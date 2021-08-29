/**
 * @file    drv_spi.h
 * @brief   SPI communication driver
 * @author  m2enu
 * @date    2021/08/29
 * @par     License
 *          https://github.com/m2enu/clang_interface/blob/main/LICENSE
 */
#ifndef DRV_SPI_H_INCLUDED
#define DRV_SPI_H_INCLUDED

#include <stdint.h>
#include "ICommunication.h"

typedef struct Spi_t
{
    /* Public */
    ICommunication      Interface;

    /* Private */
    uint8_t             polarity;
    uint32_t            frequency;
    uint8_t             chipSelect;
} Spi_t;

void SpiNew(Spi_t * const);

#endif  /* DRV_SPI_H_INCLUDED */
