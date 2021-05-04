#include "Overnight.h"
#include <iostream>
#include <string>

using namespace std;

//***************************************************************************
// Constructor:	Overnight
//
// Description:	Initializes the link between Overnight and Parcel classes
//
// Parameters:	None
//
// Returned:		None
//***************************************************************************
Overnight::Overnight():Parcel() {
		const int initilize = 0;
		mVolume = initilize;
}

//***************************************************************************
// Constructor:	Overnight
//
// Description:	Initializes data members.
//
// Parameters:	tid         - the tracking number to store
//							from        - parcel's sender
//              to          - parcel's reciever
//              weight      - parcel's weight in ounces
//              distance    - distance package will travel
//
// Returned:		none
//***************************************************************************
Overnight::Overnight(int tid, std::string from, std::string to, int weight, int distance, int volume) :
		Parcel(tid, from, to, weight, distance) {
		mVolume = volume;
}

//***************************************************************************
// Function:	  getDeliveryDay
//
// Description:	Will calculat the delivery day.
// 
// Parameters:	none
//
// Returned:		The delivery day of the letter Parcel. 
//***************************************************************************
int Overnight::getDeliveryDay()const {
		int day = 0;
		const int milesCovered = 1000;
		const int oneDay = 1;
		const int twoDays = 2;
		double dayCalc = mDistance / milesCovered;

		if (mbRush==true) {
				day = oneDay;
		}
		else {
				if (dayCalc <= milesCovered) {
						day = oneDay;
				}
				else {
						day = twoDays;
				}
		}

		return day;

}

//***************************************************************************
// Function:	  getCost_Insurance
//
// Description:	Will calculate how much insurance will be
// 
// Parameters:	none
//
// Returned:		Insurance price for a Overnight parcel
//***************************************************************************
double Overnight::getCost_Insurance() {
		const double insuranceFlatRate = 1.25;
		double charge = 0;

		if (mbIsInsured == true) {
				charge = insuranceFlatRate;
		}

		return charge;
}

//***************************************************************************
// Function:	  getCost_Rush
//
// Description:	Will calculate how much it would be to rush an overnight
//							parcel
// 
// Parameters:	none
//
// Returned:		Price for anovernight parcel
//***************************************************************************
double Overnight::getCost_Rush() {
		const double rushRate = 0.75;
		double charge=0;

		if (mbRush == true) {
				charge = getCost_Parcel() * rushRate;
		}

		return charge;
}

//***************************************************************************
// Function:	  getCost_Parcel
//
// Description:	Will calculate how much it would be to mail a simple 
//							overngiht parcel.
// 
// Parameters:	none
//
// Returned:		Price to mail a Overnight parcel
//***************************************************************************
double Overnight::getCost_Parcel() {
		const int charge_LowVol = 12;
		const int charge_highVol = 20;
		const int vol_High = 100;

		double charge = 0;

		if (mVolume > vol_High) {
				charge = charge_highVol;
		}
		else {
				charge = charge_LowVol;
		}

		return charge;
}

//***************************************************************************
// Function:	  getCost_Total
//
// Description:	Will calculate total price of insurance+Rush+parcel
// 
// Parameters:	none
//
// Returned:		Total price to mail the parcel
//***************************************************************************
double Overnight::getCost_Total() {
		double total = 0;

		total = getCost_Insurance() + getCost_Parcel() + getCost_Rush();

		return total;
}

//***************************************************************************
// Function:	  setInsurance 
//
// Description:	Will set the parcel to have insurance
//
// Parameters:	none
//
// Returned:		none 
//***************************************************************************
void Overnight::setInsured() {
		mbIsInsured = true;
}

//***************************************************************************
// Function:	  setRush 
//
// Description:	Will set the parcel to be rushed
//
// Parameters:	none
//
// Returned:		none 
//***************************************************************************
void Overnight::setRush() {
		mbRush = true;
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the Overnight to the stream
//
// Parameters:	rcIn - the stream to read from
//
// Returned:		None
//***************************************************************************
void Overnight::read(istream& rcIn) {

		Parcel::read(rcIn);
		rcIn >> mVolume;

}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the Overnight parcel to the stream
//
// Parameters:	rcOut - the stream to output to
//
// Returned:		None
//***************************************************************************
void Overnight::print(ostream& rcOut)const {
		Parcel::print(rcOut);

		if (mbIsInsured) {
				rcOut << " INSURED  ";
		}
		if (mbRush) {
				rcOut << " Rush  ";
		}

		rcOut << " OVERNIGHT!  ";
}