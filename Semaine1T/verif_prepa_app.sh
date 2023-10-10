#! /bin/bash

echo2 () {
	echo $1 1>&2
}

SCRIPT_PATH=$(pwd)
DATA=verif_data

clear 

if [ "$1" == "-h" ]; then 
	echo "Ce script ne doit etre exécuté que sur une machine Linux (PC en natif ou VM, MACOS)"
	echo "Le programme et son fichier makefile doivent être présents dans le répertoire courant"
	exit 0
fi

if [ ! -s main.c ]; then 
	echo2 "Le fichier main.c est absent ou vide"
	exit 1
fi 


if [ ! -s makefile ]; then 
	echo2 "Le fichier makefile est absent ou vide"
	exit 1
fi 

# contexte
if [ -e checksum.exe ]; then 
	echo2 "- Le fichier checksum.exe existe déjà, exécution de la commande de nettoyage"
	if [ -z "$(cat makefile | grep clean)" ]; then 
		echo2 "Règle de nettoyage absente"
		exit 1
	fi 
	echo "make clean"
	make clean 
	if [ -e checksum.exe ]; then 
		echo2 "La règle de nettoyage n'a pas supprimé le fichier checksum.exe"
		exit 1
	fi
fi

if [ -e collected_data ]; then 
	echo2 "- Le fichier collected_data.exe existe déjà, exécution de la commande de nettoyage"
	if [ -z "$(cat makefile | grep clean)" ]; then 
		echo2 "Règle de nettoyage absente"
		exit 1
	fi 
	echo "make clean"
	make clean 
	if [ -e collected_data ]; then 
		echo2 "La règle de nettoyage n'a pas supprimé le fichier collected_data"
		exit 1
	fi
fi

# compilation
echo ""
echo "- Compilation de checksum.exe"
echo "make"
make 
if [ ! -e checksum.exe ]; then 
	echo2 "La règle de compilation n'a pas produit le fichier checksum.exe"
	exit 1
fi

# exécution 
echo ""
echo '- Exécution de checksum.exe'
if [ -z $(./checksum.exe) ]; then 
	echo2 "=> Le programme checksum.exe n'affiche rien"
	exit 1
fi
echo "make test"
make test 
if [ ! -s collected_data ]; then 
	echo2 "=> La règle test ne produit pas le fichier collected_data"
	exit 1
fi

SUMPROG=$(cat collected_data)
echo "=> Checksum renvoyée par votre programme : $SUMPROG" 

# vérifications 
echo "" 
echo -n "- Entrez votre nom (identique à celui utilisé dans votre programme) : "
read NOM

echo ""
echo "- Calcul de la somme de contrôle de $NOM modulo 256"
TAILLE=$(echo $NOM | wc -c)

NEXTL=$(echo $NOM | cut -c1)
NEXTV=$(echo $NEXTL | tr -d "\n" | od -An -t uC | tr -d " ")
SUM=$NEXTV
echo "Lettre $NEXTL / Valeur $NEXTV / Somme $SUM"
I=2

while [ $I -lt $TAILLE ]; do
	NEXTL=$(echo $NOM | cut -c$I)
	NEXTV=$(echo $NEXTL | tr -d "\n" | od -An -t uC | tr -d " ")
	SUM=$(expr \( $SUM + $NEXTV \) \% 256 )
	
	echo "Lettre $NEXTL / Valeur $NEXTV / Somme $SUM"
	I=$(expr $I + 1)
done 

echo "=> Checksum attendue : $SUM"

if [ $SUM -ne $SUMPROG ]; then 
	echo2 "  => Sommes différentes, revoyez votre programme"
	exit 1
fi

echo "=> Votre programme calcule la bonne somme de contrôle"

echo ""
echo "- Création du fichier verif_data à associer à votre CR "

> $DATA

echo -n "Nom: " >> $DATA
echo $NOM >> $DATA


echo -n "Version du Noyau: " >> $DATA
uname -r >> $DATA

echo -n "Compte: " >> $DATA
id >> $DATA

echo -n "Machine: " >> $DATA
hostname >> $DATA

echo -n "Horaire: " >> $DATA
date >> $DATA

echo -n "Réseau: " >> $DATA
ifconfig >> $DATA

echo "=> Le fichier verif_data a été créé dans le répertoire courant"













