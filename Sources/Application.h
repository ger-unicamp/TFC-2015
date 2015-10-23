/*
 * Application.h
 *
 *  Created on: 11/09/2015
 *      Author: Marcelo
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "PE_Types.h"
#include "PE_LDD.h"

/* Tamanho da resolucao do conversor. */
#define TAM 255

typedef struct {
  LDD_TDeviceData *handle; /* LDD device handle */
  volatile uint8_t isSent; /* this will be set to 1 once the block has been sent */
  uint8_t rxChar; /* single character buffer for receiving chars */
  uint8_t (*rxPutFct)(uint8_t); /* callback to put received character into buffer */
} UART_Desc;

void APP_Run(void);

void Char_Read(void);

void Send_char(unsigned char caractere);
void Send_uint8_t(int numero);

#endif /* APPLICATION_H_ */
