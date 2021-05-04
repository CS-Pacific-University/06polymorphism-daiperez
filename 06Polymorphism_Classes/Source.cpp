#include <iostream>
#include <string>
#include<fstream>
#include<iomanip>
#include "Parcel.h"
#include "Postcard.h"
#include "Letter.h"
#include "Overnight.h"

using namespace std;

void printMenu();
void insurance(Parcel* apcParcel[], int& countParcels);
void rush(Parcel* apcParcel[], int& countParcels);
void deliver(Parcel* apcParcel[], int& countParcels);

//****************************************************************************
//Function:		  main
//Description:	Driver for Parcel using Classes for the user to choose between
//              5 different options
//Parameters:		none
//Returned:			exit status
//****************************************************************************/
int main() {
  
    const int OPT1_PRINTALL = 1;
    const int OPT2_ADDINSUR = 2;
    const int OPT3_ADDRUSH = 3;
    const int OPT4_DELIVER = 4;
    const int OPT5_QUIT = 5;
    const int MAXPARCELS = 25;

    const char LETTER = 'L';
    const char POSTCARD = 'P';
    const char OVERNIGHT = 'O';

    const string Input_File = "parcels.txt";
    ifstream inFile;

    Parcel *apcParcel[MAXPARCELS] = { nullptr };

    int countParcels = 0;
    char parcelType;
    int choice;

    inFile.open(Input_File);

    if (!inFile.is_open()) {
        cout << "Couldn't open file.";
        return EXIT_FAILURE;
    }

    cout << "Mail Simulator!" << endl;

    while ((!(inFile.eof())) && countParcels < MAXPARCELS) {
        inFile >> parcelType;

        if (parcelType == LETTER) {
            apcParcel[countParcels] = new Letter;
            apcParcel[countParcels]->read(inFile);
            countParcels++;
        }
        if (parcelType == POSTCARD) {
            apcParcel[countParcels] = new Postcard;
            apcParcel[countParcels]->read(inFile);
            countParcels++;
        }
        if (parcelType == OVERNIGHT) {
            apcParcel[countParcels] = new Overnight;
            apcParcel[countParcels]->read(inFile);
            countParcels++;
        }
    }

    do {
        do {
            printMenu();
            cout << "\nChoice> ";
            cin >> choice;
        } while (!(choice == OPT1_PRINTALL || choice == OPT2_ADDINSUR || choice == OPT3_ADDRUSH || choice == OPT4_DELIVER || choice == OPT5_QUIT));

        switch (choice) {
        case OPT1_PRINTALL:
            for (int counter = 0; counter < countParcels; counter++) {
                if (apcParcel[counter] != nullptr) {
                    apcParcel[counter]->print(cout);

                }
            }
            cout << endl;
            break;
        case OPT2_ADDINSUR:
            insurance(apcParcel, countParcels);
            break;
        case OPT3_ADDRUSH:
            rush(apcParcel, countParcels);
            break;

        case OPT4_DELIVER:
            deliver(apcParcel, countParcels);
            break;
        }
    } while (choice != OPT5_QUIT);

    inFile.close();

    delete[] *apcParcel;

  return EXIT_SUCCESS;
}

//****************************************************************************
//Function:    printMenu
//
//Description: Prints Menu to screen
//
//Parameters:  none
//
//Returned:		 none
//****************************************************************************/
void printMenu() {
    const string OPT1 = "1. Print All";
    const string OPT2 = "2. Add Insurance";
    const string OPT3 = "3. Add Rush";
    const string OPT4 = "4. Deliver";
    const string OPT5 = "5. Quit";

    cout << endl << OPT1 << endl << OPT2 << endl
        << OPT3 << endl << OPT4 << endl << OPT5
        << endl;
}

//****************************************************************************
//Function:    insurance
//
///Description: Adds insurance and cost to parcel and implements functions
//
//Parameters:  apcParcel  - an array of pointers to Parcel
//             numParcels - the number of parcels
//
//Returned:		 none
//****************************************************************************/
void insurance(Parcel *apcParcel[], int &numParcels) {
    const int index = 1;

    int tid;

    cout << "\nTID> ";
    cin >> tid;

    if (apcParcel[tid - index] != nullptr) {
        apcParcel[tid - index]->setInsured();
        cout << "\nAdd Insurance for $" <<
            apcParcel[tid - index]->getCost_Insurance();
        apcParcel[tid - index]->print(cout);
        cout << endl;

    }
}

//****************************************************************************
//Function:    rush
//
//Description: Adds rush and cost to parcel and implements functions
//
//Parameters:  apcParcel  - an array of pointers to Parcel
//             numParcels - the number of parcels
//
//Returned:		 none
//****************************************************************************
void rush(Parcel* apcParcel[], int& countParcels) {
    const int index = 1;

    int tid;

    cout << "\nTID> ";
    cin >> tid;

    if (apcParcel[tid - index] != nullptr) {
        apcParcel[tid - index]->setRush();
        cout << "\n$" <<
            apcParcel[tid - index]->getCost_Rush();
        apcParcel[tid - index]->print(cout);
        cout << endl;
    }
}

//****************************************************************************
//Function:    deliver
//
//Description: will output the cos to deliver the parcel as well as the number
//              it will take to deliver the parcel             
//Parameters:  apcParcel    - an array of pointers to Parcel
//             numParcels   - the number of parcels
//
//Returned:		 none
//****************************************************************************
void deliver(Parcel* apcParcel[], int& countParcels) {
    const int index = 1;
    int tid;

    cout << "\nTID> ";
    cin >> tid;

    if (apcParcel[tid - index] != nullptr) {
        apcParcel[tid - index]->getDeliveryDay();
        cout << "Delivered!" << endl <<
            apcParcel[tid - index]->getDeliveryDay() <<
            " Day, $" << fixed << setprecision(2)
            << apcParcel[tid - index]->getCost_Total();
            apcParcel[tid - index]->print(cout);
            cout << endl;
            delete apcParcel[tid - index];
            apcParcel[tid - index] = nullptr;
    }
}