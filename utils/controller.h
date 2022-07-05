//
// Created by B.User on 04/07/2022.
//
#include "services.h"

class App{
public:

    static void header(){
        cout<<"======================================================================================================"<<endl;
        cout<<"*       Welcome to Disease Cases Reporting System!                                                   *"<<endl;
        cout<<"======================================================================================================"<<endl;
        cout<<"*                                                                                                    *"<<endl;
        cout<<"*        It is developed by Shallon Kobusinge as practical                                           *"<<endl;
        cout<<"*       evaluation for the end of Year 3                                                             *"<<endl;
        cout<<"======================================================================================================"<<endl;
        cout<<"Starting Time: Thu Apr 05 23:59:08 CAT 2022                                                           "<<endl;
        cout<<"Need a help Type 'help' then press Enter Key.                                                         "<<endl;


    }
    static void start(){
        char option;
        do{
            header();
            cout<<"======================================================================================================"<<endl;
            cout<<"*                        HELP MENU                                                  *"<<endl;
            cout<<"======================================================================================================"<<endl;
            cout<<"1. add <Location>                                    : Add a new location                             "<<endl;
            cout<<"2. delete <Location>                                 : Delete an existing location                    "<<endl;
            cout<<"3. record <Location><disease> <cases>                : Delete an existing location                    "<<endl;
            cout<<"4. list locations                                    : List all existing locations                    "<<endl;
            cout<<"5. list diseases                                     : List existing Diseases in a locations          "<<endl;
            cout<<"6. where <disease>                                   : Find where disease exists                      "<<endl;
            cout<<"7. cases <location><disease>                         : Find cases of a disease in location            "<<endl;
            cout<<"8. cases <disease>                                   : Find total cases of a give disease             "<<endl;
            cout<<"9. help                                              : Prints user manual                             "<<endl;
            cout<<"10. Exit                                             : Exit the program                               "<<endl;
            cin>>option;
            switch (option) {
                case '1':
                    cout<<" Add location "<<endl;
                    break;
                case '2':
                    cout<<" delete location "<<endl;
                    break;
                case '3':
                    cout<<" Add location "<<endl;
                    break;
                case '4':
                    cout<<" Add location "<<endl;
                    break;
                case '5':
                    cout<<" Add location "<<endl;
                    break;
                case '6':
                    cout<<" Add location "<<endl;
                    break;
                case '7':
                    cout<<" Add location "<<endl;
                    break;
                case '8':
                    cout<<" Add location "<<endl;
                    break;
                case '9':
                    cout<<" Add location "<<endl;
                    break;
                case '10':
                    exit(1);
                default:
                    cout<<" Invalid input "<<endl;
                    break;
                                }


        }while(option != '9');

    }
};