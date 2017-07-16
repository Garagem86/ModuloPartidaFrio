// 
// 
// 

#include "SensorCombReservatorio.h"

void SensorCombReservatorio::setup()
{
	this->vMin = calcularVMin(SCOMB_TR);
}

bool SensorCombReservatorio::temCombustivel()
{
	return !temSinal(this->vMin, SCOMB_PINO);
}

