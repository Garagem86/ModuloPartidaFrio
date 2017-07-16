// LeitorSinal.h

#ifndef _LEITORSINAL_h
#define _LEITORSINAL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "CfgModulo.h"

inline float calcularVMin(float perc)
{
	return (VIN * perc);
}

inline bool temSinal(float VMin, int pino)
{
	float valorAtual = analogRead(pino);
	float tensao = (valorAtual * VIN) / 1024.0;

	bool temSinal = false;

	if(tensao >= VMin) {
		temSinal = true;
	}

	return temSinal;
}

#endif

