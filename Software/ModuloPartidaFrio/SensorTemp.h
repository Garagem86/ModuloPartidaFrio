// SensorTemp.h

#ifndef _SENSORTEMP_h
#define _SENSORTEMP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "CfgModulo.h"

/// Sensor de Temperatura
// Pino
const int STEMP_PINO = A1;

// Valor da Resist�ncia para o Sensor de Temperatura
// NTC = Acima desse valor de Resist�ncia o Sensor indica que o Motor est� FRIO
// PTC = Abaixo desse valor de Resist�ncia o Sensor indica que o Motor est� FRIO
const float STEMP_VFRIO = 2.200;

// - Potenciometro da Sensibilidade do Sensor
const int STEMP_SENB = A5;

// Modo de Funcionamento do Sensor (Tipo do Sensor)
// -
// 1 = NTC
// 2 = PTC
const int STEMP_TIPO = 1;

// - Tens�o M�xima que pode ser levada em considera��o
const float STEMP_MTENSAO = 3.000;

const float STEMP_SENSI = 0.8;

class SensorTemp
{
 protected: 
	float sens;
	
 public:
	void setup();
	
	// Valida se o Motor est� Frio ou Quente
	bool estaFrio();	
	float LerSensor();
	float LerSensibilidade();
};

#endif

