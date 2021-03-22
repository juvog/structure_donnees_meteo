#include <stdio.h>
#include <iostream>
#include "datapoint.h"
#include  <fstream>
#include <cstdlib>
#include <string>
#include <set>
#include <sstream>


using namespace std;

int main(int argc, char **argv)
{
    
    //creation du set data
    set<Datapoint> data;
    
    //cout << " Le size du containeur data (qui est un set>: " << data.size() << endl; // donne combien de datapoint se trouve dans le set
    
    string ligne;
    
    //Ouverture rawdata dans reader
    ifstream reader("rawdata.txt");
    
    //Création des variables qui seront utilisés pour l'objet Datapoint
    double lati;
    double lon;
    string notImp;
    double tem;
    string tstamp;
    
    
    while (!reader.eof()){ // Tant quon arrive pas a la fin du fichier rawdata.txt boucle
        
        getline(reader, ligne); // get la premiere ligne de ce qui se trouve dans reader ( qui contient rawdata.txt ) puis le mettre dans le string ligne
        stringstream iss(ligne); // stringstream va prendre la chaine de caractere jusqu'au premier espace blance
        iss >> lati; // iss prendra la chaine de caractere 30.20, converti au type de "lati" soit double puis le met dans "lati"
        iss >> lon;// ici -81.39 sera converti en double puis mis dans "lon"
        iss >> notImp;// notImp pour not Important puisque cette variable ne sera pas mise dans le datapoint. Elle correspond au KHB39.
        iss >> tem;
        iss >> tstamp;
        tem = (tem - 32) * 5/9;
        
        Datapoint datapointInput (tstamp, lati, lon, tem); // l'objet Datapoint est crée avec les données appropriées
        data.insert(datapointInput); // Puis insérer dans le set appelé "data"
        
      //  cout << " Lat: " << lati << endl << " lon: " << lon << endl << " tem: " << tem << endl << " tstamp: " << tstamp << endl; // affiche pour tester le fonctionnement - peut être enlever ou mis en commentaires
        
        if (reader.eof())
            cout << " End of line " << endl;
        
    }
    
    reader.close();
    
    // Ecriture dans candata.txt
    ofstream writer;
    writer.open("candata.txt");
    set<Datapoint>::iterator iterateur;
    
    //for loop pour peupler le fichier candata.txt. Affiche aussi toutes les valeurs dans le set data à des fins de test.
    for (iterateur = data.begin(); iterateur!=data.end(); iterateur++){
        
       iterateur->afficherDataPoint();
        writer << iterateur->getTimestamp() << " " << iterateur->getLatitude() << " "  << iterateur->getLongitude() << " " << iterateur ->getCelsius() << endl;
        
    }
    
    writer.close();
    
}




