/* ###################################################################
**     Filename    : Events.c
**     Project     : Potentiometer_Reading_2015_10_06
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-10-06, 00:09, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

static int _BC_Counter = 0;
static int _state = lcL_bcL;
uint8 _pixel[128];

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnBlockReceived (module Events)
**
**     Component   :  AS1 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called when the requested number of data is
**         moved to the input buffer.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void AS1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
	UART_Desc *ptr = (UART_Desc*)UserDataPtr;

	(void)ptr->rxPutFct(ptr->rxChar); /* but received character into buffer */
	(void)AS1_ReceiveBlock(ptr->handle, (LDD_TData *)&ptr->rxChar, sizeof(ptr->rxChar));
}

/*
** ===================================================================
**     Event       :  AS1_OnBlockSent (module Events)
**
**     Component   :  AS1 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void AS1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
	UART_Desc *ptr = (UART_Desc*)UserDataPtr;

	ptr->isSent = TRUE; /* set flag so sender knows we have finished */
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnEnd(void)
{
	if (_BC_Counter < 129)
	{
//		AD1_GetValue(&);
	}
}

/*
** ===================================================================
**     Event       :  AD1_OnCalibrationEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  LitleClock_OnInterrupt (module Events)
**
**     Component   :  LitleClock [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LitleClock_OnInterrupt(void)
{
	switch (_state)
	{
		case (lcL_bcL):
		{
			/* Inicio de um novo ciclo. */
			if (_BC_Counter == 0)
			{
				/* SI recebe nivel logico alto. */
				SI_SetVal();
			}
			_state = lcH_bcH;
			break;
		}

		case (lcH_bcH):
		{
			/* Big Clock esta em nivel logico alto. */
			BigClock_SetVal();

			/* Incrementacao do numero de big clocks. */
			_BC_Counter++;

			/* A tensão do pixel (BC_Counter)
			 * esta disponivel na saida analogica. */

			_state = lcL_bcH;
			break;
		}

		case (lcL_bcH):
		{
			if (_BC_Counter == 1)
			{
				/* SI recebe nivel logico baixo. */
				SI_ClrVal();
			}

			/* Apos um tempo necessario para estabilizar a tensao. */
			AD1_Measure(FALSE);

			_state = lcH_bcL;
			break;
			}

		case (lcH_bcL):
		{
			/* Big Clock esta em nivel logico baixo. */
			BigClock_ClrVal();

			/* Fim do ciclo de leitura. */
			if (_BC_Counter == 129)
			{
				_BC_Counter = 0;
				/* Imprime_Vetor */
				LitleClock_Disable();

			}

				_state = lcL_bcL;
		}
	}
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
