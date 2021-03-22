//
//  datapoint.cpp
//  structures_donnees_meteo
//
//  Created by Vincent Pinard on 2021-03-22.
//

#include "datapoint.h"



Datapoint::Datapoint(string tstamp, double lat, double lon, double cel)
{
    this->celsius = cel;
    this->latitude = lat;
    this->longitude = lon;
    this->timestamp = tstamp;

}


bool Datapoint::operator<(const Datapoint& r_datapoint) const {
        
    double latitude_gauche = this->latitude;
    double latitude_droite = r_datapoint.latitude;
    
    double longitude_gauche = this->longitude;
    double longitude_droite = r_datapoint.longitude;
    
    
    if (latitude_gauche > latitude_droite){
        
            return true;
    }
    
    else if (latitude_gauche == latitude_droite){
        
            if (longitude_gauche < longitude_droite) {
           
                return true;
            }
        
    }
    return false;
}


    void Datapoint::afficherDataPoint() const{
        
        std::cout << "Timestamp: " << this->getTimestamp() << " ";
        std::cout << "Latitude: " << this->getLatitude() << " ";
        std::cout << "Longitude: " << this->getLongitude() << " ";
        std::cout << "Celsius: " << this->getCelsius() << std::endl;
            
    }
 
