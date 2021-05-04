#include "Letter.h"
#include <iostream>
#include<string>

using namespace std;

//***************************************************************************
// Constructor:	Letter
//
// Description:	Initializes the link between Letter and Parcel classes
//
// Parameters:	None
//
// Returned:		None
//***************************************************************************
Letter::Letter(): Parcel() {
}

//***************************************************************************
// Constructor:	Letter
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
Letter::Letter(int tid, std::string from, std::string to, int weight, 
		int distance) :
		Parcel(tid, from, to, weight, distance) {
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
int Letter::getDeliveryDay()const {
		int day=0;
		const int milesPerDay = 100;
		const int oneDay = 1;
		const int twoDays = 2;
		double dayCalc = mDistance / milesPerDay;
		
		if (mbRush == true) {
				if (((dayCalc) < oneDay)&&(dayCalc<twoDays)) {
						day = oneDay;
				}
		}
		if(mbRush==false) {
				day = (int)dayCalc;
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
// Returned:		Insurance price for a Letter
//***************************************************************************
double Letter::getCost_Insurance() {
		double insuranceCharge = 0;
		const double rate = 0.45;

		if (mbIsInsured == true) {
				insuranceCharge = rate;
		}

		return insuranceCharge;
}

//***************************************************************************
// Function:	  getCost_Rush
//
// Description:	Will calculate how much it would be to rush an letter
//							parcel
// 
// Parameters:	none
//
// Returned:		Rush price for a letter parcel
//***************************************************************************
double Letter::getCost_Rush() {
		double rushCharge = 0;
		const double rushRate = 0.1;

		if (mbRush == true) {
				rushCharge = rushRate * getCost_Parcel();
		}

		return rushCharge;
}

//***************************************************************************
// Function:	  getCost_Parcel
//
// Description:	Will calculate how much it would be to rush an letter
//							parcel
// 
// Parameters:	none
//
// Returned:		Price for a letter parcel
//***************************************************************************
double Letter::getCost_Parcel() {
		const double ratePerOunce = 0.45;
		double cost_Parcel = 0;

		cost_Parcel = mWeight * ratePerOunce;

		return cost_Parcel;
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
double Letter::getCost_Total() {
		double total = 0;
		total = getCost_Parcel() + getCost_Insurance() + getCost_Rush();
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
void Letter::setInsured() {
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
void Letter::setRush() {
		mbRush = true;
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the Letter to the stream
//
// Parameters:	rcIn - the stream to read from
//
// Returned:		None
//***************************************************************************
void Letter::read(istream& rcIn) {

		Parcel::read(rcIn);

}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the Letter parcel to the stream
//
// Parameters:	rcOut - the stream to output to
//
// Returned:		None
//***************************************************************************
void Letter::print(ostream& rcOut)const {
		Parcel::print(rcOut);

		if (mbIsInsured) {
				rcOut << " INSURED  ";
		}
		if (mbRush) {
				rcOut << " RUSH  ";
		}


}