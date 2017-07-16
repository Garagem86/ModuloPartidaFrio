// 
// 
// 

#include "SensorPosChave.h"

void SensorPosChave::setup()
{
	this->vMin = calcularVMin(PCHAVE_TR);
}

bool SensorPosChave::posChaveLigado()
{
	bool taLigado = temSinal(this->vMin, PCHAVE_PINO);
	
	#ifdef _DEBUG
		Serial.print("PC=");
		Serial.println(taLigado);
	#endif
	
	return taLigado;
}
