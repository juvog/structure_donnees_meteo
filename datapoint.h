#ifndef DATAPOINT_H
#define DATAPOINT_H
#include <string>
#include <iostream>

using namespace std;

class Datapoint
{

private:
    string timestamp;
    double latitude;
    double longitude;
    double celsius;

public:
    Datapoint(string tstamp, double lat, double lon, double cel);
    
    void setTimestamp(string timestamp){this->timestamp = timestamp;};
    void setLatitude(double latitude){this->latitude = latitude;};
    void setLongitude(double longitude){this->longitude = longitude;};
    void setCelsius (double celcius){this->celsius = celsius;};
    
    
    double getLatitude() const {return this->latitude;}; // pourquoi le const est necessaire ici
    double getLongitude() const {return this->longitude;};
    double getCelsius() const {return this->celsius;};
    string getTimestamp() const {return this->timestamp;};
    
    bool operator<(const Datapoint& r_datapoint) const;
    void afficherDataPoint() const;
    
    //fonction amies - servent pas directement dans le cadre de ce probleme mais permette d utiliser cout << un_datapoint pour afficher un datapoint
    //friend ostream& operator<<(ostream& os, const Datapoint& datapoint);
   // friend istream& operator>>(istream& is, Datapoint& datapoint);

};

#endif // DATAPOINT_H
