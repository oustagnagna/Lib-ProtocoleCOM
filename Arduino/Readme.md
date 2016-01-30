Pour la partie arduino il y a 3 types de librairies:

Lib ProtocoleCOM
Lib ProtocoleCOM_Periph
Lib ProtocoleCOM_TechnoCom

1-) Description architecture

1-a) Message en réception

+----------------+ 

|msg recu en Hard|

+----------------+

        |
        
        v
        
Lib ProtocoleCOM_TechnoCom
        |
        v 
Lib ProtocoleCOM
        |
        v 
Lib ProtocoleCOM_Periph

1-b) Message en émission

Lib ProtocoleCOM_Periph
        |
        v
Lib ProtocoleCOM
        |
        v
Lib ProtocoleCOM_TechnoCom
        |
        v 
+----------------+
|msg emis en Hard|
+----------------+

2-) Description Librairies

2-a) Lib ProtocoleCOM_TechnoCom

Une par type de Hardware (UDP,nrf24l01,IR,433mhz,...)
Permet de lire les msg recus et d'envoyer des msg

2-b) Lib ProtocoleCOM

En réception permet de décoder la trame, de séparer les champs, de calculer cks,...
En emission permet d'assembler la trame, de calculer cks,...

2-c) Lib ProtocoleCOM_Periph

Une par projet, lie une commande du protocole a une action spécifique

3-) Communication entre les librairies

Les données circulent entre librairies dans une structure globale 
désignée par poiteurs
TODO : créer cette structure
