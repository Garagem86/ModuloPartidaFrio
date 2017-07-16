// CfgModulo.h

#ifndef _CFGMODULO_h
#define _CFGMODULO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

///
// Configura��es do M�dulo
///

// - Pino para o Sinal da Bomba de Combustivel
// -
const int BCOMB_PINO = PD2;

// - Pino para a Regulagem do Tempo de Inje��o
const int RTEMP_PINO = A6;

// - Valor Padr�o para o Tempo de Inje��o
const int TEMP_INJ = 2000;

// - Valor Padr�o da Tens�o de Entrada
// Em Volts 
const float VIN = 4.99;

// - Levar em Considera��o o Nivel do Combustivel?
const int USAR_NIVELCOMB = 0; 

// Configura��o dos Sinais de Saida //

// - Alerta do Nivel de Combustivel
const int ACOMB_PINO = PD3;

// - Alerta da Partida a Frio
const int APARTIDA_PINO = 13;


#endif

