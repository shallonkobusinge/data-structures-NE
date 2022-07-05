//
// Created by B.User on 04/07/2022.
//
#include "services.h"

class App{
public:

    static void addLocation(){
        string name;
        cout << "Enter location name: "<<endl;
        cin >> name;
        for_each(name.begin(), name.end(), [](char &c){
            c = toupper(c);
        });
        Location location = Location(name);
        MinistryService::AddLocation(location);
    }
    static void addDisease(){
        string name;
        cout << "Enter disease name: "<<endl;
        cin >> name;
        for_each(name.begin(), name.end(), [](char &c){
            c = toupper(c);
        });
        string locationName;
        cout << "Enter location name: "<<endl;
        cin >> locationName;
        for_each(locationName.begin(), locationName.end(), [](char &c){
            c = toupper(c);
        });
        int numberOfCases;
        cout << "Enter number of cases: "<<endl;
        cin >> numberOfCases;
        Location location = MinistryService::findLocationByName(locationName);
        Disease disease = Disease(name,location.getId(),numberOfCases);
        MinistryService::recordAdiseaseAndItsCase(disease);
    }

    static void showAllLocations(){
        vector<Location> locations = MinistryService::returnAllLocations();

        cout<<endl<<endl;
        cout<<"  \t\t\t LIST OF ALL EXISTING LOCATIONS  \t\t\t"<<endl;
        for(auto & i : locations){
            cout <<"\t\t "<< i.getId() << " \t\t " << i.getName() << endl;
        }
        cout<<endl<<endl;
    }
    static void showAllDisease(){
        vector<Disease> diseases = MinistryService::returnAllDiseases();
        cout<<endl<<endl;
        cout<<"  \t\t\t LIST OF ALL EXISTING DISEASES  \t\t\t"<<endl;
        cout<<"\t\t DISEASE ID \t\t  NAME\t\tLOCATION ID\t\tLOCATION NAME\t\tNUMBER OF CASES  "<<endl;
        for(auto & i : diseases){
            Location location = MinistryService::findLocationById(i.getLocationId());
            cout <<"\t\t "<< i.getId() <<" \t\t  " << i.getName() <<" \t\t         "<<i.getLocationId() <<" \t\t         "<<location.getName() << " \t\t"<<i.getNumberOfCases() << endl;

        }
        cout<<endl<<endl;
    }
    static unsigned get_case_string(char* str, char** _strings, unsigned n){
        while(n)
        {
            n--;
            if(strcmp(str, _strings[n]) == 0) return n;
        }
        return 0;
    }
    static void start(){
        string option;
        char str[100];
        vector<string> tokens;


        do{

            cout<<"======================================================================================================"<<endl;
            cout<<"*                                         HELP MENU                                                  *"<<endl;
            cout<<"======================================================================================================"<<endl;
            cout<<"add <Location>                                    : Add a new location                             "<<endl;
            cout<<"delete <Location>                                 : Delete an existing location                    "<<endl;
            cout<<"record <Location><disease> <cases>                : Delete an existing location                    "<<endl;
            cout<<"list locations                                    : List all existing locations                    "<<endl;
            cout<<"list diseases                                     : List existing Diseases in a locations          "<<endl;
            cout<<"where <disease>                                   : Find where disease exists                      "<<endl;
            cout<<"cases <location><disease>                         : Find cases of a disease in location            "<<endl;
            cout<<"cases <disease>                                   : Find total cases of a given disease            "<<endl;
            cout<<"help (click 9 for help)                           : Prints user manual                             "<<endl;
            cout<<"Exit                                             : Exit the program                               "<<endl;
            cin.getline(str,100);
            char *ptr;
            ptr = strtok(str, " ");
            while(ptr != NULL){
                tokens.push_back(ptr);
                ptr = strtok(NULL, " ");
            }
            for (int i = 0; i < tokens.size(); ++i) {
                cout<<tokens[i]<<endl;
            }
            cout<<"size "<<tokens.size()<<endl;
            if(tokens[0] == "add"){
                addLocation();
            } else if(tokens[0] == "delete"){
                MinistryService::deleteAnExistingLocation();
            }else if(tokens[0] == "record") {
                addDisease();
            }else if((tokens[0] == "list") && (tokens[1].empty())){
                MinistryService::alphabeticallySortLocations();
            }else if(tokens[0] == "where"){
                MinistryService::alphabeticallySortDiseases();
            }else if((tokens[0] == "list"  ) && !(tokens[1].empty())){
                MinistryService::getLocationByDiseaseName();
            }
            else if(tokens.size() == 2 && tokens[0] == "cases" ){
                std::string s;
                std::stringstream ss;
                ss << tokens[1];
                ss >> s;
                MinistryService::totalNumberOfCaseOfAgivenDisease(s);
            }
            else if( tokens.size() == 3 && tokens[0] == "cases" ){
                std::string s;
                std::stringstream ss;
                ss << tokens[2];
                ss >> s;

                std::string id;
                std::stringstream ssid;
                ssid << tokens[1];
                ssid >> id;
                MinistryService::numberOfCasesFoundInALocation(id, s);
            }else if(tokens[0] == "help"){
                MinistryService::userManual();
            }else if(tokens[0] == "Exit"){
                cout<<"\t\t Ministry of Health (MoH) management system has terminated successfully "<<endl;
                    exit(1);
            }else{
            cout << endl;
            cout << endl;
            cout << " \t\t\t INVALID INPUT " << endl;
            cout << endl;
        }}while(tokens[0] != "Exit");

    }
};