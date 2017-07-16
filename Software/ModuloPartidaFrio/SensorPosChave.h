// SensorPosChave.h

#ifndef _SENSORPOSCHAVE_h
#define _SENSORPOSCHAVE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "CfgModulo.h"
#include "LeitorSinal.h"

// Sensor do Pós-Chave (Posição Elétrica da Chave no Comutador de Ignição)

// - Tolerância do Sinal Pós-Chave
const float PCHAVE_TR = 0.8;

// - Pino de Leitura do Sinal Pós-Chave
const int PCHAVE_PINO = A3;

class SensorPosChave
{
 protected:
	float vMin;
 public:
	void setup();
	bool posChaveLigado();
};

#endif

