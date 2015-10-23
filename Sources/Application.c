/*
 * Application.c
 *
 *  Created on: 11/09/2015
 *      Author: Marcelo
 */


#include "Application.h"
#include "RxBuf.h"
#include "AS1.h"

static UART_Desc deviceData;

static void SendChar(unsigned char ch, UART_Desc *desc) {
  desc->isSent = FALSE;  /* this will be set to 1 once the block has been sent */
  while(AS1_SendBlock(desc->handle, (LDD_TData*)&ch, 1)!=ERR_OK) {} /* Send char */
  while(!desc->isSent) {} /* wait until we get the green flag from the TX interrupt */
}

static void SendString(const unsigned char *str,  UART_Desc *desc) {
  while(*str!='\0') {
    SendChar(*str++, desc);
  }
}

static void Init(void) {
  /* initialize struct fields */
  deviceData.handle = AS1_Init(&deviceData);
  deviceData.isSent = FALSE;
  deviceData.rxChar = '\0';
  deviceData.rxPutFct = RxBuf_Put;
  /* set up to receive RX into input buffer */
  RxBuf_Init(); /* initialize RX buffer */
  /* Set up ReceiveBlock() with a single byte buffer. We will be called in OnBlockReceived() event. */
  while(AS1_ReceiveBlock(deviceData.handle, (LDD_TData *)&deviceData.rxChar, sizeof(deviceData.rxChar))!=ERR_OK) {} /* initial kick off for receiving data */
}

void APP_Run(void) {
  Init();
  SendString((unsigned char*)"Hello World\r\n", &deviceData);
  for(;;) {
    if (RxBuf_NofElements()!=0) {
      SendString((unsigned char*)"echo: ", &deviceData);
      while (RxBuf_NofElements()!=0) {
        unsigned char ch;

        (void)RxBuf_Get(&ch);
        SendChar(ch, &deviceData);
      }
      SendString((unsigned char*)"\r\n", &deviceData);
    }
  }
}

/** Lê um caractere digitado no teclado pelo terminal salva em uma variavel em ch e envia essa essa variavel de volta para o terminal. E pula de linha .*/
void Char_Read(void)
{
  Init(); /* Inicializa a estrutura do tipo UART_Desc. */
  SendString((unsigned char*)"Digite um caractere:\r\n", &deviceData); /* Envia uma string para o mestre, recebe a string e o endereco da estrutura UART_Desc. */

  for(;;)
  {
	  /* Caso exista algum elemento no buffer */
	  if (RxBuf_NofElements()!=0)
	  {

		  /* Enquanto o buffer nao estiver vazio. */
		  while (RxBuf_NofElements()!=0)
		  {
			  unsigned char ch; /* Variavel do tipo char para armazenar o valor lido. */

			  (void)RxBuf_Get(&ch); /* Leitura do teclado. Remove um elemento do buffer e salva em ch. */

			  SendChar(ch, &deviceData); /* Envia ch para o terminal. */

			  SendChar('\r',&deviceData); /* Retorno de carro. */
			  SendChar('\n', &deviceData); /* Pulo de linha. */
		  }
	  }
  }
}

/* Recebe um numero inteiro. */
void Send_uint8_t(int numero)
{
	char R1, R2, R3;
	int Q1, Q2;

	Init(); /* Inicializa a estrutura do tipo UART_Desc. */

	/* Verifica se ele eh negativo. */
	if (numero < 0)
	{
		  Send_char('e');
	}

	/* Verifica se ele ultrapassa o valor maximo da resolucao do ADC. */
	else if (numero > TAM)
	{
		Send_char('E');
	}

	/* Decompoe o numero inteiro em tres variaveis do tipo char. */
	else
	{
		R1 = (unsigned char) (numero % 10) + '0';
		Q1 = numero / 10;

		R2 = (unsigned char) (Q1 % 10) + '0';
		Q2 = Q1 / 10;

		R3 = (unsigned char) (Q2 % 10) + '0';

		/* Envia os digitos para o terminal. */
		SendChar(R3, &deviceData);
		SendChar(R2, &deviceData);
		SendChar(R1, &deviceData);
	}

	/* Troca de linha e retorno de carro. */
	SendChar('\r', &deviceData);
	SendChar('\n', &deviceData);
}

void Send_char(unsigned char caractere)
{
	Init(); /* Inicializa a estrutura do tipo UART_Desc. */

	SendChar(caractere,  &deviceData);
	SendChar('\r', &deviceData);
	SendChar('\n', &deviceData);
}
