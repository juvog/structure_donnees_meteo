#pragma once
#include<string>


class Datapoint {
		private :
	double latitude;
	double longitude;
	std::string dateHeure;
	double temperature;
	
		public :
	Datapoint(std::string une_dateHeure, double une_latitude,double une_longitude, double une_temperature){
		this->dateHeure = une_dateHeure, 
		this->latitude = une_latitude, 
		this->longitude = une_longitude, 
		this->temperature = une_temperature;
	}
		
	
	std::string afficherEnregistrement(){
		return this->dateHeure +" " +this->latitude+" "+ this->longitude +" " +this->temperature;
	}
	
	
}	
