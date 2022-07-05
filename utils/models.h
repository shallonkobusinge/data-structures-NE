//
// Created by B.User on 04/07/2022.
//

#include "headers.h"
class Location{
private:
    int id;
    string name;
public:
    Location(){}
    Location(string name){
        this->name = name;
    }
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
    void setId(int id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
};

class Disease{
private:
    int id;
    string name;
    int locationId;
    int numberOfCases;
public:
    Disease(){}
    Disease(int id, string name, int locationId, int numberOfCases){
        this->id = id;
        this->name = name;
        this->locationId = locationId;
        this->numberOfCases = numberOfCases;
    }
    Disease(string name, int locationId, int numberOfCases){
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
    void setId(int id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
    void setLocationId(int id){
        this->locationId = id;
    }
    void setNumberOfCases(int caseNumber){
        this->numberOfCases = caseNumber;
    }
};