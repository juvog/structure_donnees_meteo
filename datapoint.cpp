#include "datapoint.h"

bool Datapoint::operator<(const Datapoint& r_datapoint) const {
        
    double latitude_gauche = this->latitude; // pourquoi ca ne marche pas si je fais this->getLatitude(); ????
    double latitude_droite = r_datapoint.latitude;
    
    double longitude_gauche = this->longitude;
    double longitude_droite = r_datapoint.longitude;
    
    
    if (latitude_gauche < latitude_droite){
        
            return true; 
    }
    
    else if (latitude_gauche == latitude_droite){
        
            if (longitude_gauche < longitude_droite) {
           
                return true;
            }
        
    }
    else 
        return false;
        
}
