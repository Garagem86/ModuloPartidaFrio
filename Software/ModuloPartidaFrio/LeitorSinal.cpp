// 
// 
// 

#include "LeitorSinal.h"


float calcularVMin(float perc)
{
	 return (VIN * perc);
}

bool temSinal(float VMin, int pino)
{
	float valorAtual = analogRead(pino);
	float tensao = (valorAtual * VIN) / 1024.0;

	bool temSinal = false;

	if(tensao >= VMin) {
		temSinal = true;
	}

	return temSinal;
}
