// 
// 
// 

#include "SensorTemp.h"

void SensorTemp::setup()
{
	
}

bool SensorTemp::estaFrio()
{
	bool estaFrio = false;
	
	float leituraSens = this->LerSensibilidade();
	
	if(this->sens != leituraSens) {
		this->sens = leituraSens;	
	}
	
	float leitura = this->LerSensor();	
	
	float vFrio = (STEMP_VFRIO - (this->sens * 2)) + STEMP_SENSI;
	
	#ifdef _DEBUG
		Serial.print("VALOR-FRIO=");
		Serial.println(vFrio);
	#endif
	
    if(leitura > STEMP_MTENSAO) {
		leitura = 0.1;
    }
	
	if(leitura >= vFrio) {
		estaFrio = true;
	}
	
	#ifdef _DEBUG
		if(estaFrio) {
			Serial.println("ESTA-FRIO!");
		}
	#endif 
	
	return estaFrio;
}

float SensorTemp::LerSensor()
{
	float vLeitura = analogRead(STEMP_PINO);
	
	vLeitura = vLeitura * ( VIN / 1024.0);	

	#ifdef _DEBUG
		Serial.print("VALOR-TEMP=");
		Serial.println(vLeitura);	
	#endif
	
	return vLeitura;
}

float SensorTemp::LerSensibilidade()
{
	float leituraPot = analogRead(STEMP_SENB);
		
	if(leituraPot < 100) {
		leituraPot = 100;
	}
	
	if(leituraPot > 900) {
		leituraPot = 900;
	}
		
	leituraPot = leituraPot / 1000;	
	
	
	#ifdef _DEBUG
		Serial.print("VALOR-SENST=");
		Serial.println(leituraPot);
	#endif
	
	return leituraPot;
}

