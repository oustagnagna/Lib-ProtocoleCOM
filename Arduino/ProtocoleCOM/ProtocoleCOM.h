#ifndef PROTOCOLECOM_H
#define PROTOCOLECOM_H

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

class Protocole_COM 
{

	public:

	Protocole_COM(uint16_t *longueurtrameudp);


	uint8_t 
	calcul_cks(),
	is_cks_enabled(),
	extract_id(),
	extract_len(),
	extract_data(uint8_t *adressedata,uint8_t *nbrcases);
	
	unsigned int 
	extract_cmd();

	private:

	uint8_t
	*buffrecep;
	uint16_t
	*lenbuff;
};

#endif 
