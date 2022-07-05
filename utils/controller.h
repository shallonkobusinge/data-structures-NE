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


        do{

            cout<<"======================================================================================================"<<endl;
            cout<<"*                                         HELP MENU                                                  *"<<endl;
            cout<<"======================================================================================================"<<endl;
            cout<<"1. add <Location>                                    : Add a new location                             "<<endl;
            cout<<"2. delete <Location>                                 : Delete an existing location                    "<<endl;
            cout<<"3. record <Location><disease> <cases>                : Delete an existing location                    "<<endl;
            cout<<"4. list locations                                    : List all existing locations                    "<<endl;
            cout<<"5. list diseases                                     : List existing Diseases in a locations          "<<endl;
            cout<<"6. where <disease>                                   : Find where disease exists                      "<<endl;
            cout<<"7. cases <location><disease>                         : Find cases of a disease in location            "<<endl;
            cout<<"8. cases <disease>                                   : Find total cases of a given disease            "<<endl;
            cout<<"9. help (click 9 for help)                           : Prints user manual                             "<<endl;
            cout<<"10. Exit                                             : Exit the program                               "<<endl;
            cin>>option;
            if(option == "add"){
                addLocation();
            } else if(option == "delete"){
                MinistryService::deleteAnExistingLocation();
            }else if(option == "record") {
                addDisease();
            }else if(option == "list"){
                MinistryService::alphabeticallySortLocations();
            }else if(option == "where"){
                MinistryService::alphabeticallySortDiseases();
            }else if(option == "wheresecond"){
                MinistryService::getLocationByDiseaseName();
            }else if(option == "cases"){
                MinistryService::numberOfCasesFoundInALocation();
            }else if(option == "total"){
                MinistryService::totalNumberOfCaseOfAgivenDisease();
            }else if(option == "help"){
                MinistryService::userManual();
            }else if(option == "exit"){
                cout<<"\t\t Ministry of Health (MoH) management system has terminated successfully "<<endl;
                    exit(1);
            }else{
            cout << endl;
            cout << endl;
            cout << " \t\t\t INVALID INPUT " << endl;
            cout << endl;
        }}while(option != "exit");

    }
};