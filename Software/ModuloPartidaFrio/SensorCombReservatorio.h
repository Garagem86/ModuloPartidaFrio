// SensorCombReservatorio.h

#ifndef _SENSORCOMBRESERVATORIO_h
#define _SENSORCOMBRESERVATORIO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "CfgModulo.h"
#include "LeitorSinal.h"

// Sensor do Nivel do Combustivel 

// - Tolerância do Sinal Pós-Chave
const float SCOMB_TR = 0.9;

// - Pino de Leitura do Sinal Pós-Chave
const int SCOMB_PINO = A2;

class SensorCombReservatorio
{
	protected:
		float vMin;
	public:
		void setup();
		bool temCombustivel();
};

#endif

