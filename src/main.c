/**
 * @file    main.c
 * @brief   Main function
 * @author  m2enu
 * @date    2021/08/29
 * @par     License
 *          https://github.com/m2enu/clang_interface/blob/main/LICENSE
 */
#include "ICommunication.h"
#include "drv_can.h"
#include "drv_spi.h"

int main(void)
{
    /* Construct CAN communication */
    static Can_t can;
    CanNew(&can);

    /* Construct SPI communication */
    static Spi_t spi;
    SpiNew(&spi);

    /* Open communication interfaces */
    IC_Open(IC_CAST(can));
    IC_Open(IC_CAST(spi));

    /* Close communication interfaces */
    IC_Close(IC_CAST(can));
    IC_Close(IC_CAST(spi));
}
