
#include "ProtocoleCOM.h"


#define COM_PREFIX_POS	0
#define COM_PREFIX_SIZ	1

#define COM_LEN_POS	1
#define COM_LEN_SIZ	1

#define COM_CMD_POS	2
#define COM_CMD_SIZ	2

#define COM_ID_POS	4
#define COM_ID_SIZ	1
//**************************************************************************
//**************************************************************************
//**************************************************************************
// Constructeur
Protocole_COM::Protocole_COM(uint16_t *longueurtrameudp) : buffrecep(NULL),lenbuff(longueurtrameudp) 
{
	if((buffrecep = (uint8_t *)malloc(261))) 
	{
		memset(buffrecep, 0x00, 261);
	}
}
//**************************************************************************
//**************************************************************************
//**************************************************************************
uint8_t Protocole_COM::calcul_cks()
{
	uint8_t cks;
	
	cks = buffrecep[1];
	
	for(unsigned int cpt = 2 ; cpt < *lenbuff ; cpt++)
	{
		cks ^= buffrecep[cpt];
	}
	
	return (cks);	
}
//**************************************************************************
uint8_t Protocole_COM::extract_len()
{
	return (buffrecep[COM_LEN_POS]);
}
//**************************************************************************
unsigned int Protocole_COM::extract_cmd()
{
	return (((buffrecep[COM_CMD_POS] << 0x08) && buffrecep[COM_CMD_POS+1]));
}
//**************************************************************************
uint8_t Protocole_COM::extract_id()
{
	return (buffrecep[COM_ID_POS]);
}
//**************************************************************************
uint8_t Protocole_COM::extract_data(uint8_t *adressedata,uint8_t *nbrcases)
{
	uint8_t error = 0x01;
	
	if(*lenbuff >= 7) // 7 รงa veut dire qu'il y a au moins un octet de data
	{
		adressedata = (buffrecep + 5);  // pour pointer la premiere case de data
		*nbrcases 	= *lenbuff - 6; 	// nbr de cases de data
	}
	else
	{
		// pas de data
		adressedata = NULL;
		*nbrcases 	= 0x00;
		error 		= 0x00;
	}
	
	return(error);
}
//**************************************************************************
uint8_t Protocole_COM::is_cks_enabled(void)
{
	if(buffrecep[COM_PREFIX_POS]==0xFF)
	{
		return (0x01);	
	}
	else
	{
		return (0x00);	
	}
}
//**************************************************************************
