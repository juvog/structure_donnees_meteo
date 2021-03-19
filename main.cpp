#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <limits>
#include <deque>
#include "datapoint.h"

int main(){

	// Ouverture en lecture du fichier rawdata.txt 

	std::ifstream lecteur("/rawdata.txt");

	//Instanciation du deque où seront stockées les objet Datapoint récoltés à partir du fichier rawdata.txt
	// D'après le fichier d'aide à la prise de décision c'est la contenant le plus approprié // Il faudra en discuter !!
	
	std::deque<Datapoint> enregistrements_meteo;



	// Parcours du fichier rawdata.txt afin de lire tout le texte
	while(!lecteur.eof()){
	
	
	// Récupération d'une ligne que l'on place dans fichier_temp ouvert en écriture en mode TRUNC
	std::string ligne_rawdata;
	getline(lecteur, ligne_rawdata);
	std::ofstream fichier_temp("temp.txt");
	fichier_temp << ligne_rawdata;
	fichier_temp.close();

	// Ouverture en lecture de fichier_temp
	std::ifstream lecteur_temp("temp.txt");


	//Interprétation des chaines de caractères dans le format souhaité et remplissage des tableaux
	
	std::string latitude_temp;
	lecteur_temp >> latitude_temp;
	double latitude = std::stod(latitude_temp);

	std::string longitude_temp;
	lecteur_temp >> longitude_temp;
	double longitude = std::stod(longitude_temp);

	std::string station;
	lecteur_temp >> station;

	std::string temperature_temp;
	lecteur_temp >> temperature_temp;
	double temperature_f = std::stod(temperature_temp);
	double temperature = temperature_f*2; // vrai formule à retrouver

	std::string dateHeure;
	lecteur_temp >> dateHeure;


	//Instanciation du premier objet de la classe Datapoint
	Datapoint un_enregistrement(dateHeure, latitude, longitude, temperature);
	enregistrements_meteo.push_back(un_enregistrement);


	//fermeture de fichier_temp
	fichier_temp.close();

	//code afin que le prochain getline(lecteur, ligne_rawdata) puisse fonctionner.
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	}
	
	// Vérification que le deque mes_enregisterments est bien rempli
	
	for (int i = 0; i< enregistrements_meteo.size(); i++){
		enregistrements_meteo[i].afficherEnregistrement();
	}
	
	
}





//