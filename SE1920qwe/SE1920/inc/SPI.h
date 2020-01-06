/**
* @file		SPI.h
* @brief	Contains the SPI function utility.
* @version	1.1
* @date		12 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/

#ifndef SPI_H_
#define SPI_H_

#include "LPC17xx.h"
/** @defgroup SPI SPI
 * This package provides the core capabilities for SPI functions.
 * @{
 */
/** @defgroup SPI_Public_Constants SPI Public Constants
 * @{
*/
/**
 * @brief SPI Function value that will be used
 */
#define SPI_FUNCTION 3
/**
 * @brief Position value of Serial Clock at PINSEL
 */
#define PINSEL_SCK_BIT_POS 30
/**
 * @brief Position value of Master In Slave Out at PINSEL
 */
#define PINSEL_MISO_BIT_POS 2
/**
 * @brief Position value of Master Out Slave In at PINSEL
 */
#define PINSEL_MOSI_BIT_POS 4

/**
 * @brief Position value of SPI at PCLKSEL0
 */
#define PCLK_SPI_BIT_POSITION 16 //PCLKSEL0
/**
 * @brief set PCLK to CCLK with negative logic
 */
#define PCLK_CCLK_FUNCTION_L 2

/** @defgroup SPI_Control_Register SPI Control Register
 * @{
*/

/**
 * @brief Position value of Enable bit at SPCR
 */
#define BIT_ENABLE_BIT_POSITION 2
/**
 * @brief if 0 the SPI controller sends and receives 8 bits of data per
transfer. if 1 the SPI controller sends and receives 8 to 16 bits of data per
transfer
 */
#define BITS_MODE 1

/**
 * @brief Position value of BITS_BIT at SPCR
 */
#define BITS_BIT_POSITION 8
/**
 * @brief Mask that represents BITS_BIT at SPCR
 */
#define BITS_MASK 0xF

/**
 * @brief Position value of Master Mode at SPCR
 */
#define MASTER_MODE_BIT_POSITION 5
/**
 * @brief Master Mode value
 */
#define MASTER_MODE 1

/**
 * @brief Position value of LSBF at SPCR
 */
#define LSBF_BIT_POSITION 6
/**
 * @brief MSB mode of LSBF with negative logic
 */
#define MSB_MODE_L 1
/**
 * @brief Position value of CPHA and CPOL at SPCR
 */
#define CPHA_CPOL_BIT_POSITION 3
/**
 * @brief Mask that represent CPHA and CPOL
 */
#define CPHA_CPOL_BIT_MASK 0x3

/**
 * @brief Enum that contain the CPHA and CPOL configuration values
 */
enum CPHA_CPOL_VALUES{
	CPHA_CPOL_LL=0,
	CPHA_CPOL_HL,
	CPHA_CPOL_LH,
	CPHA_CPOL_HH
};
/**
 * @brief Enum that contain the number of bits that will be transfered
 */
enum BITS{
	EIGHT_BITS=8,
	NINE_BITS,
	TEN_BITS,
	ELEVEN_BITS,
	THIRTEEN_BITS,
	FOURTEEN_BITS,
	FIFTEEN_BITS,
	SIXTEEN_BITS=0
};
/**
 * @}
 */
/**
 * @brief custom configuration transfer value
 */
#define CUSTOM_CONFIG_TRANSFER 0
/**
 * @brief default frequency value
 */
#define DEFAULT_FREQUENCY 1
/**
 * @brief default databit value
 */
#define DEFAULT_DATABIT DEFAULT_FREQUENCY<<1
/**
 * @brief default mode value
 */
#define DEFAULT_MODE DEFAULT_FREQUENCY<<2


/** @defgroup SPI_Status_Register SPI Status Register
 * @{
*/
/**
 * @brief ABRT value
 */
#define ABRT 1
/**
 * @brief MODF value
 */
#define MODF 2
/**
 * @brief ROVR value
 */
#define ROVR 4
/**
 * @brief WCOL value
 */
#define WCOL 8
/**
 * @brief SPIF value
 */
#define SPIF 16
/**
 * @}
 * @}
 */
/** @defgroup SPI_Public_Functions SPI Public Functions
 * @{
*/
/**
 * @brief Initialize SPI functions
 * @note must be called first
 */
void init_spi(void);
/**
 * @brief set SPI transfers configurations
 */
int SPI_ConfigTransfer(int frequency, int bitData, int mode);
/**
 * @brief perform a transfer of data.
 * @return success or error
 */
int SPI_Transfer(unsigned short *txBuffer, unsigned short *rxBuffer, int length);
/* Realiza uma transferência. Retorna sucesso ou erro na transferência. */
/**
 * @}
 * @}
 */
#endif /* SPI_H_ */
