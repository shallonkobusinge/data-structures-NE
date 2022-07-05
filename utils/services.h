//
// Created by B.User on 04/07/2022.
//
#include "models.h"
class MinistryService{

public:
    static bool compare(string a, string b){
        return a<b;
    }

    static vector<Location> returnAllLocations(){
        vector<Location> locations;
        ifstream file;
        file.open("locations.txt", ios::app);
        if(!file.is_open()){
            cout<<"File not found"<<endl;
            exit(1);
        }
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
    static vector<string> returnAllLocationNames(){
        vector<string> locationNames;
        ifstream file;
        file.open("locations.txt", ios::app);
        if(!file.is_open()){
            cout<<"File not found"<<endl;
            exit(1);
        }
        string line;
        string storedLine;
        while(getline(file, line)){
            stringstream ss(line);
            string token;
            Location location =  returnSingleLocation(line);
            locationNames.push_back(location.getName());
        }
        file.close();
        return locationNames;
    }
    static vector<string> returnAllDiseaseNames(){
        vector<string> diseaseNames;
        ifstream file;
        file.open("diseases.txt", ios::app);
        if(!file.is_open()){
            cout<<"File not found"<<endl;
            exit(1);
        }
        string line;
        string storedLine;
        while(getline(file, line)){
            stringstream ss(line);
            string token;
            Disease disease =  returnSingleDisease(line);
            diseaseNames.push_back(disease.getName());
        }
        file.close();
        return diseaseNames;
    }
    static vector<string> returnAllDiseaseNamesSortedWithAnInput(const int& name){
        vector<string> diseaseNames;
        ifstream file;
        file.open("locations.txt", ios::app);
        if(!file.is_open()){
            cout<<"File not found"<<endl;
            exit(1);
        }
        string line;
        string storedLine;
        while(getline(file, line)){
            if(line.find(to_string(name)) != string::npos){
                cout<<" line found "<<line<<endl;
                stringstream ss(line);
                string token;
                Location disease =  returnSingleLocation(line);
                diseaseNames.push_back(disease.getName());
            }
        }
        file.close();
        return diseaseNames;
    }
    static void alphabeticallySortLocations(){
        vector<string> locations = returnAllLocationNames();
        std::sort(locations.begin(), locations.end(), compare);
        cout<<endl<<endl;
        cout<<"  \t\t\t LIST OF ALL EXISTING LOCATIONS  \t\t\t"<<endl;
       for(int i=0; i<locations.size(); i++) {
           cout << " \t\t " << locations[i] << endl;

       }
        cout << endl << endl;
    }
    static void alphabeticallySortDiseases(){
        vector<string> diseases = returnAllDiseaseNames();
        std::sort(diseases.begin(), diseases.end(), compare);
        cout<<endl<<endl;
        cout<<"  \t\t\t LIST OF ALL EXISTING DISEASES  \t\t\t"<<endl;
        cout<<"\t\t  NAMES"<<endl;
        cout<<"----------------------------------------------"<<endl;
        for(auto & disease : diseases) {
            cout << " \t\t " << disease << endl;
        }
        cout<<endl<<endl;
    }

    static void alphabeticallySortDiseasesWithAnDiseaseNameInput(string name){
        for_each(name.begin(), name.end(), [](char &c){
            c = toupper(c);
        });
        Disease existingDisease = findDiseaseByName(name);
        vector<string> diseases = returnAllDiseaseNamesSortedWithAnInput(existingDisease.getLocationId());
        std::sort(diseases.begin(), diseases.end(), compare);
        cout<<endl<<endl;
        cout<<"  \t\t\t LIST OF ALL SORTED EXISTING DISEASES  \t\t\t"<<endl;
        cout<<"\t\t  NAMES"<<endl;
        cout<<"----------------------------------------------"<<endl;
        for(auto & disease : diseases) {
            cout << " \t\t " << disease << endl;
        }
        cout<<endl<<endl;
    }


    static vector<Disease> returnAllDiseases(){
        vector<Disease> diseases;
        ifstream file;
        file.open("diseases.txt", ios::app);
        if(!file.is_open()){
            cout<<"File not found"<<endl;
            exit(1);
        }
        string line;
        string storedLine;
        while(getline(file, line)){
            stringstream ss(line);
            string token;
            Disease disease =  returnSingleDisease(line);
            diseases.push_back(disease);
        }
        file.close();
        return diseases;
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

    static int returnLastIdFromDiseaseFile(){
        vector<Disease> all = returnAllDiseases();
        int lastId = 0;
        for(auto & i : all){
            if(i.getId() > lastId){
                lastId = i.getId();
            }
        }
        return lastId;
    }
    // add a new location to the file
    static void AddLocation(Location location) {
        ofstream file;
        file.open("locations.txt", ios::app);
        if(!file.is_open()){
            cout<<"File not found"<<endl;
            exit(1);
        }
        if(file.is_open()){
            bool locationExists = locationExistsByName(location.getName());
            if (locationExists) {
                cout<<endl;
                cout << "\t\t Location already exists" << endl;
                cout<<endl;
                exit(0);
            }
            int lastId = returnLastId();
            location.setId(lastId + 1);
            file << location.getId() << "  " << location.getName() << "  " << endl;
            cout<<endl;
            cout << "\t\t\t Location "<<location.getName()<<" is successfully added!" << endl;
            cout<<endl;
            file.close();
        }else{
            cout<<endl;
            cout << "\t\t Error: File could not be opened" << endl;
            cout<<endl;
            exit(0);
        }

    }
    static bool locationExistsByName(string location){
        vector<Location> locations = returnAllLocations();
        bool exists = false;
        for(auto & i : locations){
            if(i.getName() == location){
                exists = true;
                return exists;
            }

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
    static Disease returnSingleDisease(const string &line){
        stringstream ss(line);
        Disease disease;
        string item;
        int i=0;
        for(string rowElement; ss >> rowElement;) {

            if (reinterpret_cast<const char *>(rowElement[rowElement.length() - 1] ) == " ")
                rowElement.pop_back();

            if (i == 0) disease.setId(stoi(rowElement));
            else if(i == 1) disease.setName(rowElement);
            else if(i == 2) disease.setLocationId(stoi(rowElement));
            else if(i == 3) disease.setNumberOfCases(stoi(rowElement));
            i++;
        }
        return disease;
    }
    static void deleteAnExistingLocation(string name) {
        vector<Location> locations = returnAllLocations();
        cout<<endl<<endl;
        cout<<"  \t\t\t LIST OF LOCATIONS WE HAVE "<<endl;
        for(int i = 0; i < locations.size(); i++){
            cout<<" \t\t\t Location "<<i+1<<" "<<locations[i].getName()<<endl;
        }
        for_each(name.begin(), name.end(), [](char &c){
            c = toupper(c);
        });
        bool locationExists = locationExistsByName(name);
        if(!locationExists){
            cout << "Location does not exist" << endl;
            cout<<endl;
            exit(0);
        }

        ifstream file("locations.txt");
        ofstream tempFile("temp.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            if (line.find(name) != string::npos) {
                cout<<" You are going to delete "<<line<<endl;
            }else{
                tempFile << line << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("locations.txt");
        rename("temp.txt", "locations.txt");
        cout<<endl;
        cout<<" "<<name<<" deleted successfully"<<endl;
        cout<<endl;
        cout<<endl;
    }
    static bool checkIfAlocationExistsById(int id){
        bool exists = false;
        vector<Location> locations = returnAllLocations();
        for(auto & i : locations){
            if(i.getId() == id){
                exists = true;
                return exists;
            }
        }
        return exists;
    }
    static bool checkIfADiseaseExistsByName(string name){
        bool exists = false;
        vector<Disease> diseases = returnAllDiseases();
        for(auto & i : diseases){
            if(i.getName() == name){
                exists = true;
                return exists;
            }
        }
        return exists;
    }
    static Location getLocationByName(int id){
        vector<Location> locations = returnAllLocations();
        Location location;
        for(auto & i : locations){
            if(i.getId() == id){
                location = i;
                return location;
            }
        }
        return location;
    }
    // add a new disease to the file
    static void recordAdiseaseAndItsCase(Disease disease){
        ofstream file;
        file.open("diseases.txt", ios::app);
        if(!file.is_open()){
            cout<<"File not found"<<endl;
            exit(1);
        }

        if(file.is_open()){
            int lastId = returnLastIdFromDiseaseFile()+1;
            bool locationExists = checkIfAlocationExistsById(disease.getLocationId());
            if (!locationExists) {
                cout<<endl;
                cout << "\t\t Location you are trying to add does not exist" << endl;
                cout<<endl;
                exit(0);
            }
            if(disease.getNumberOfCases() <= 0){
                cout<<endl;
                cout << "\t Number of cases should be greater than 0" << endl;
                cout<<endl;
                exit(0);
            }
            Location location = getLocationByName(disease.getLocationId());
            Disease addDisease = Disease(lastId,disease.getName(), disease.getLocationId(), disease.getNumberOfCases());
            file << addDisease.getId() << "  " << addDisease.getName() << "  " << addDisease.getLocationId() << "  " << addDisease.getNumberOfCases() << endl;
            cout<<"\t\t "<<addDisease.getName()<<" has be added to "<<location.getName()<<" with "<<addDisease.getNumberOfCases()<<" cases successfully "<<endl;
            file.close();
        }else{
            cout<<endl;
            cout << "\t\t File is not open" << endl;
            cout<<endl;
            exit(0);
        }

    }
    static Location findLocationById(int id){
        vector<Location> locations = returnAllLocations();
        Location location;
        for(auto & i : locations){
            if(i.getId() == id){
                location = i;
                return location;
            }
        }
        return location;
    }
    static Location findLocationByName(string name){
        vector<Location> locations = returnAllLocations();
        Location location;
        for(auto & i : locations){
            if(i.getName() == name){
                location = i;
                return location;
            }
        }
        return location;
    }
    static Disease findDiseaseByName(string name){
        vector<Disease> diseases = returnAllDiseases();
        Disease disease;
        for(auto & i : diseases){
            if(i.getName() == name){
                disease = i;
                return disease;
            }
        }
        return disease;
    }

      static vector<Location> findAListOfLocationGivenDiseaseName(string name) {
        vector<Location> locations = returnAllLocations();
        vector<Disease> diseases = returnAllDiseases();
        vector<Location> locationsByDiseaseName;
        for (int i = 0; i < diseases.size(); i++) {
            if (diseases[i].getName() == name) {
                for (int j = 0; j < locations.size(); j++) {
                    if (locations[j].getId() == diseases[i].getLocationId()) {
                        locationsByDiseaseName.push_back(locations[j]);
                    }
                }
            }

        }
        return locationsByDiseaseName;
    }
        static vector<Location> findLocationByDiseaseLocationId(string name) {
        Disease disease = findDiseaseByName(name);
        Location location = findLocationById(disease.getLocationId());
        vector<Location> locations;
        cout<<" Location found "<<location.getName()<<endl;
        locations.push_back(location);
        return locations;

    }
    // get location by disease name
        static void getLocationByDiseaseName(string diseaseName){
        cout<<"\t\t "<<diseaseName<<" is spread in "<<endl;

       for_each(diseaseName.begin(), diseaseName.end(), [](char &c){
           c = toupper(c);
       });

        bool diseaseExists = checkIfADiseaseExistsByName(diseaseName);
        if(!diseaseExists){
            cout<<endl;
            cout << "\t\t Disease you are trying to find with does not exist" << endl;
            cout<<endl;
            exit(0);
        }
        Disease disease = findDiseaseByName(diseaseName);
        Location location = findLocationById(disease.getLocationId());

        vector<Location> locationsByDiseaseName = findAListOfLocationGivenDiseaseName(disease.getName());
        if(locationsByDiseaseName.size() == 0){
            cout<<endl;
            cout << "\t\t No locations found for this disease" << endl;
            cout<<endl;
            cout<<endl;
        }

        cout<<" "<<diseaseName<<" is found in "<<endl;
        for(int i=0; i<locationsByDiseaseName.size(); i++){

            cout<<" \t\t [ "<<locationsByDiseaseName[i].getName()<<"] \t\t"<<endl;
        }
       cout<<endl<<endl;
    }
    static Disease getDiseaseByLocationId(int id){
        vector<Disease> diseases = returnAllDiseases();
        Disease disease;
        for(auto & i : diseases){
            if(i.getLocationId() == id){
                disease = i;
                return disease;
            }
        }
        return disease;
    }
    static Disease findDiseaseByLocationIdAndName(int locationId, string name){
        vector<Disease> diseases = returnAllDiseases();
        Disease disease;
        for(auto & i : diseases){
            if(i.getLocationId() == locationId && i.getName() == name){
                disease = i;
                return disease;
            }
        }
        return disease;
    }
    static void numberOfCasesFoundInALocation(string locationName, string diseaseName){
        for_each(locationName.begin(), locationName.end(), [](char &c){
            c = toupper(c);
        });
        for_each(diseaseName.begin(), diseaseName.end(), [](char &c){
            c = toupper(c);
        });
        bool locationExists = locationExistsByName(locationName);
        cout<<" check "<<locationExists<<" name "<<locationName<<endl;
        if(!locationExists){
            cout<<endl;
            cout << "\t\t Location you are trying to find with does not exist" << endl;
            cout<<endl;
            exit(0);
        }
        bool diseaseExists = checkIfADiseaseExistsByName(diseaseName);
        if(!diseaseExists){
            cout<<endl;
            cout << "\t\t Disease you are trying to find with does not exist" << endl;
            cout<<"ahhaha "<<diseaseName<<endl;
            cout<<endl;
            exit(0);
        }
        Location location = findLocationByName(locationName);
        Disease disease = findDiseaseByLocationIdAndName(location.getId(),diseaseName);
        if(disease.getNumberOfCases() == 0){
            cout<<endl;
            cout << "\t\t There are no cases of "<<diseaseName<<" in "<<locationName<<endl;
            cout<<endl;
            exit(0);
        }
        cout<<endl;
        cout<<" \t\t\t Cases of "<<disease.getName()<<" at "<<location.getName()<<" are: "<<disease.getNumberOfCases()<<endl;
        cout<<endl;
        cout<<endl;

    }
    static vector<Disease> displayLocationsOfAgiveDisease(string diseaseName){
        for_each(diseaseName.begin(), diseaseName.end(), [](char &c){
            c = toupper(c);
        });
        bool diseaseExists = checkIfADiseaseExistsByName(diseaseName);
        if(!diseaseExists){
            cout<<endl;
            cout << "\t\t Disease you are trying to find with does not exist" << endl;
            cout<<endl;
            exit(0);
        }
        Disease disease = findDiseaseByName(diseaseName);
        vector<Disease> allDiseases;
        vector<Disease> diseases = returnAllDiseases();
        for(auto & i : diseases){
            if(i.getName() == diseaseName){
                allDiseases.push_back(i);
            }
        }
        return allDiseases;
    }
    // total cases of a given disease
    static void totalNumberOfCaseOfAgivenDisease(string diseaseName){
        for_each(diseaseName.begin(), diseaseName.end(), [](char &c){
            c = toupper(c);
        });
        bool diseaseExists = checkIfADiseaseExistsByName(diseaseName);
        if(!diseaseExists){
            cout<<endl;
            cout << "\t\t Disease you are trying to find with does not exist" << endl;
            cout<<endl;
            exit(0);
        }
        Disease disease = findDiseaseByName(diseaseName);
        int totalNumberOfCases = 0;
        vector<Disease> diseases = returnAllDiseases();
        for(auto & i : diseases){
            if(i.getName() == diseaseName){
                totalNumberOfCases += i.getNumberOfCases();
            }
        }
        cout<<endl;
        cout<<" \t\t\t Total number of cases of "<<disease.getName()<<" is: "<<totalNumberOfCases<<endl;
        cout<<endl;
        cout<<endl;
    }
    // user report manual
    static void userManual(){
        cout<<endl;
        cout<<"======================================================================================================================"<<endl;
        cout<<"\t\t WELCOME TO THE USER GUIDE OF OUR SYSTEM                                                                                                                                        "<<endl;
        cout<<"======================================================================================================================"<<endl;
        cout<<endl;
        cout<<"Follow the steps below to use the system                                                                                                                                              "<<endl;
        cout<<"Step 1:  To get started you have to run the app in your console application                                                                                                           "<<endl;
        cout<<"Step 2:  Run the application to see the welcome page                                                                                                                                   "<<endl;
        cout<<"Step 3: Type "<<"{ add + name of the location }"<<" To add a new location then enter the name of the location                                                                                                 "<<endl;
        cout<<"Step 4: Type "<<"{ delete + name of the location  }"<<" To delete an existing location then enter the name of the location you want to delete                                                                   "<<endl;
        cout<<"Step 5: Type "<<"{ record + (location name,disease name and number of case) }"<<" To record a disease and it cases where you will enter the name of the disease and number of cases in a given location name"<<endl;
        cout<<"Step 6: Type "<<"{ list locations }"<<"  To List all existing locations                                                                                                                            "<<endl;
        cout<<"Step 7: Type "<<"{ list diseases }"<<"  To List existing Diseases in a locations                                                                                                                 "<<endl;
        cout<<"Step 8: Type "<<"{ where + (name of the disease)"<<"  To Find where disease exists                                                                                                                       "<<endl;
        cout<<"Step 9: Type "<<"{ cases + (location name + disease name) } }"<<"  To Find cases of a disease in location                                                                                                                   "<<endl;
        cout<<"Step 10: Type "<<"{ cases + (disease name) }"<<" To Find total cases of a given disease                                                                                                                    "<<endl;
        cout<<"Step 11: Type "<<"{ help }"<<" To Print user manual                                                                                                                                       "<<endl;
        cout<<"Step 12: Type "<<"{ Exit }"<<" To Exit the application                                                                                                                                    "<<endl;

    }

};