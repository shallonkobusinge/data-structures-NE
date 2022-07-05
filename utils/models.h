//
// Created by B.User on 04/07/2022.
//

#include "headers.h"
class Location{
private:
    int id;
    string name;
public:
    Location(int id, string name){
        this->id = id;
        this->name = name;
    }
    int getId(){
        return this->id;
    }
    string getName(){
        return this->name;
    }
};

class Disease{
private:
    int id;
    string name;
    int locationId;
    int numberOfCases;
public:
    Disease(int id, string name, int locationId, int numberOfCases){
        this->id = id;
        this->name = name;
        this->locationId = locationId;
        this->numberOfCases = numberOfCases;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    int getLocationId(){
        return locationId;
    }
    int getNumberOfCases(){
        return numberOfCases;
    }
};