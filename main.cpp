#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <limits>
#include <deque>

int main(){

	// Ouverture en lecture du fichier rawdata.txt 

	std::ifstream lecteur("/rawdata.txt");

	//Instanciation des 5 deques où seront stockées les données du fichier rawdata.txt
	// D'après le fichier d'aide à la prise de décision c'est la contenant le plus approprié
	
	std::deque<double> latitudes;
	std::deque<double> longitudes;
	std::deque<std::string> stations;
	std::deque<unsigned int> temperatures;
	std::deque<std::string> dateHeures;


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
	latitudes.push_front(std::stod(latitude_temp));

	std::string longitude_temp;
	lecteur_temp >> longitude_temp;
	longitudes.push_front(std::stod(longitude_temp));

	std::string station_temp;
	lecteur_temp >> station_temp;
	stations.push_front(station_temp);

	std::string temperature_temp;
	lecteur_temp >> temperature_temp;
	temperatures.push_front(std::stoi(temperature_temp));

	std::string dateHeure_temp;
	dateHeures.push_front(dateHeure_temp);

	//fermeture de fichier_temp
	fichier_temp.close();

	//code afin que le prochain getline(lecteur, ligne_rawdata) puisse fonctionner.
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	}
	
	// Vérification que les tableaux sont bien remplis
	for (int i =0;i<latitudes.size();i++){
		std::cout << latitudes[i]<<std::endl;
	}
	
	for (int i =0;i<longitudes.size();i++){
		std::cout << longitudes[i]<<std::endl;
	}
	for (int i =0;i<stations.size();i++){
		std::cout << stations[i]<<std::endl;
	}
	for (int i =0;i<temperatures.size();i++){
		std::cout << temperatures[i]<<std::endl;
	}
	for (int i =0;i<dateHeures.size();i++){
		std::cout << dateHeures[i]<<std::endl;
	}
	
	
}





//