#include "SensorCombReservatorio.h"
#include "LeitorSinal.h"
#include "SensorPosChave.h"
#include "CfgModulo.h"
#include "SensorTemp.h"

/*
 * Módulo de Partida a Frio 
 *
 * Created: 7/6/2017 3:27:26 PM
 * Author: marcelo.junior
 */ 

SensorTemp sensorTemp;
SensorPosChave sensorPChave;
SensorCombReservatorio nivelComb;

bool prontoParaInjetar = true;
long ultimoInjecao = 0;
int tempoInjecao = 0;

void setup()
{	
	// - Configura a Serial
	Serial.begin(19200);
	
	// - Configura o Sensor de Temperatura
	sensorTemp.setup();
	
	// - Configura o Sensor Pos-Chave
	sensorPChave.setup();
	
	// - Configura a Saida da Bomba de Combustivel
	pinMode(BCOMB_PINO, OUTPUT);
	digitalWrite(BCOMB_PINO, HIGH);
	
	// - Configura o Sensor de Nivél da Boia de Combustivel
	nivelComb.setup();
	
	// -
	prontoParaInjetar = true;
	ultimoInjecao = 999;
}

void loop()
{		
	// - Configura o Tempo de Injeção de Combustivel
	calcularTempoInj();
	
	// Invalida o Sistema se Caso o Nivel de Combustivel estiver baixo //
	// Liga o Sinal de Baixo Nivel de Combustivel
	if(USAR_NIVELCOMB == 1) {
		if(nivelComb.temCombustivel() == true) {
			prontoParaInjetar = false;
			digitalWrite(ACOMB_PINO, HIGH);
		}
		else {
			digitalWrite(ACOMB_PINO, LOW);
		}
	}
	else {
		digitalWrite(ACOMB_PINO, LOW);
	}
		
	// Le o Estado do Motor
	bool motorEstaFrio = sensorTemp.estaFrio();
	bool temSinalPosChave = sensorPChave.posChaveLigado();
	
	// Se o Sistema estiver pronto para injetar 
	if(motorEstaFrio && temSinalPosChave && prontoParaInjetar) {	
		
		#ifdef _DEBUG		
			Serial.print("TULT=");
			Serial.println(ultimoInjecao);
		#endif
		
		if(ultimoInjecao > 50) {				
			// Injeta o Combustivel e Desabilita o sistema até o sinal pos chave resetar
			injetarCombustivel(tempoInjecao);
			prontoParaInjetar = false;		
			ultimoInjecao = 0;
		}
	} else {
		ultimoInjecao++;
	}
	
	// Reseta estado de injeção 
	// 
	if(temSinalPosChave == false && prontoParaInjetar == false) {
		prontoParaInjetar = true;
	}
	
	#ifdef _DEBUG		
		Serial.print("INJ=");
		Serial.println(prontoParaInjetar);
	#endif // DEBUG
	
	delay(150);
}

void injetarCombustivel(int tempo) {	
	delay(1000);
	
	digitalWrite(APARTIDA_PINO, HIGH);
	digitalWrite(BCOMB_PINO, LOW);	
	delay(tempo);
	digitalWrite(BCOMB_PINO, HIGH);
	digitalWrite(APARTIDA_PINO, LOW);
}

void calcularTempoInj() {
	tempoInjecao = TEMP_INJ;
	int regTempInj = analogRead(RTEMP_PINO);
	float valorPorMili = ceil(8000 / 1023);
	int tempoAdicional = regTempInj * valorPorMili;
	tempoInjecao += tempoAdicional;
	
	#ifdef _DEBUG	
		Serial.print("TI=");
		Serial.println(tempoInjecao);
		
		Serial.print("TIR=");
		Serial.println(regTempInj);
	#endif // DEBUG
}