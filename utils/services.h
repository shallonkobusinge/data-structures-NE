//
// Created by B.User on 04/07/2022.
//
#include "models.h"
class MinistryService{

public:
    static vector<Location> returnAllLocations(){
        vector<Location> locations;
        ifstream file;
        file.open("locations.txt", ios::app);
        string line;
        string storedLine;
        while(getline(file, line)){
            stringstream ss(line);
            string token;
            Location location =  returnSingleLocation(line);
            locations.push_back(location);
        }
        file.close();
        return locations;
    }
    static int returnLastId(){
        vector<Location> all = returnAllLocations();
        int lastId = 0;
        for(auto & i : all){
            if(i.getId() > lastId){
                lastId = i.getId();
            }
        }
        return lastId;
    }
    static Location AddLocation(Location location) {
        ofstream file;
        file.open("locations.txt", ios::app);
        bool locationExists = locationExistsByName(location.getName());
        if (locationExists) {
            cout << "Location already exists" << endl;
            return location;
        }
        int lastId = returnLastId();
        location.setId(lastId + 1);
        file << location.getId() << "  " << location.getName() << "  " << endl;
        file.close();
    }
    static bool locationExistsByName(string location){
        vector<Location> locations = returnAllLocations();
        bool exists = false;
        for(auto & i : locations){
            if(i.getName() == location){
                exists = true;
            }
            return exists;
            }
        return exists;
    }



    static Location returnSingleLocation(const string &line){
        stringstream ss(line);
        Location location;
        string item;
        int i=0;
        for(string rowElement; ss >> rowElement;) {

            if (reinterpret_cast<const char *>(rowElement[rowElement.length() - 1] ) == " ")
                rowElement.pop_back();

            if (i == 0) location.setId(stoi(rowElement));
            else if(i == 1) location.setName(rowElement);
            i++;
        }
        return location;
    }

};