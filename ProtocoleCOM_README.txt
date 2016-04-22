Le ProtocoleCOM est basé sur un échange question/réponse 
d'une trame.
Le maitre envoi une question à un esclave, l'esclave réponds.

1-) Description de la trame

+--------+-----+-----+-----+-----+---+----+---+
|prefixe |@dest|@src |len  |cmd  |id |Data|cks|
+--------+-----+-----+-----+-----+---+----+---+

taille min de la trame : 8 octets
taille max de la trame : 255 octets

détail des champs:
prefixe : 1 octet : Sert à savoir si CKS actif ou non
@dest   : 1 octet : Adresse du destinataire
@src    : 1 octet : Adresse de l'emmetteur
len     : 1 octet : Nombre total d'octets de la trame 
cmd     : 2 octets: Commande
id      : 1 octet : Sous commande
Data    : 0 à 247 octets : Données de la commande
cks     : 1 octet : checksum

2-) Structure

TODO : ajouter detail de la structure

3-) Description champs en détail

prefixe : 0xAA => le champs cks est laissé vide
          0x55 => le champs cks est calculé
          Ce champ est toujours transmis meme vide

@dest   : Octet contenant l'adresse unique du destinataire 
          0x00 et 0xFF interdit 254 adresses possibles

@src    : Octet contenant l'adresse unique de l'emmetteur 
          0x00 et 0xFF interdit 254 adresses possibles
          
len     : Comptabilise le nombre total d'octets de la trame 
          (prefixe+@+@+len+cmd+id+Data+cks)
          Valeur min = 0x08 Valeur max = 0xFF
          
cmd     : Commande à executer (voir fichier TODO:ajouter fichier détail commandes)

id      : Sous commande, permet de savoir si on pose la question/ ou que l'on y réponds, 
          et de signifier d'autres subtilités (voir fichier TODO:ajouter fichier détail id)
          
Data    : Données présentes ou non en fonction de la commande (voir fichier TODO:ajouter fichier détail commandes)

cks     : Checksum xor de (prefixe+@+@+len+cmd+id+data)
