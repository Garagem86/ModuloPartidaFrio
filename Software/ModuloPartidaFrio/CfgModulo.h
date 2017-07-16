// CfgModulo.h

#ifndef _CFGMODULO_h
#define _CFGMODULO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

///
// Configurações do Módulo
///

// - Pino para o Sinal da Bomba de Combustivel
// -
const int BCOMB_PINO = PD2;

// - Pino para a Regulagem do Tempo de Injeção
const int RTEMP_PINO = A6;

// - Valor Padrão para o Tempo de Injeção
const int TEMP_INJ = 2000;

// - Valor Padrão da Tensão de Entrada
// Em Volts 
const float VIN = 4.99;

// - Levar em Consideração o Nivel do Combustivel?
const int USAR_NIVELCOMB = 0; 

// Configuração dos Sinais de Saida //

// - Alerta do Nivel de Combustivel
const int ACOMB_PINO = PD3;

// - Alerta da Partida a Frio
const int APARTIDA_PINO = 13;


#endif

