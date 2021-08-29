/**
 * @file    drv_spi.c
 * @brief   SPI communication driver
 * @author  m2enu
 * @date    2021/08/29
 * @par     License
 *          https://github.com/m2enu/clang_interface/blob/main/LICENSE
 */
#include <stdio.h>
#include <stdint.h>
#include "drv_spi.h"

static void spiOpen(ICommunication * const);
static void spiClose(ICommunication * const);

static const CommunicationMethods SPI_METHODS = {
    &spiOpen,
    &spiClose };

static void spiOpen(ICommunication * const p_this)
{
    Spi_t * const p = (Spi_t * const)p_this;
    p->polarity = 1u;
    p->frequency = 1000000u;
    p->chipSelect = 3u;
    printf("[I] spiOpen: %d %d %d\n",
        p->polarity, p->frequency, p->chipSelect);
}

static void spiClose(ICommunication * const p_this)
{
    Spi_t * const p = (Spi_t * const)p_this;
    p->polarity = 0u;
    p->frequency = 0u;
    p->chipSelect = 0u;
    printf("[I] spiClose: %d %d %d\n",
        p->polarity, p->frequency, p->chipSelect);
}

void SpiNew(Spi_t * const p_this)
{
    ((ICommunication *)p_this)->p_methods = &SPI_METHODS;
}
