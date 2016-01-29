Le ProtocoleCOM est basé sur un échange question/réponse 
d'une trame.
Le maitre envoi une question à un esclave, l'esclave réponds.

1-) Description de la trame

+--------+-----+-----+-----+-------+------+
|prefixe |len	 |cmd	 |id	 |Data	 |cks   |
+--------+-----+-----+-----+-------+------+

taille min de la trame : 6 octets
taille max de la trame : 255 octets

détail des champs:
prefixe : 1 octet : Sert à savoir si CKS actif ou non
len     : 1 octet : Nombre total d'octets de la trame (prefixe+len+cmd+id+Data+cks)
cmd     : 2 octets: Commande
id      : 1 octet : Sous commande
Data    : 0 à 249 octets : Données de la commande
cks     : 1 octet : checksum




