#include "Postcard.h"
#include <iostream>
#include<string>

using namespace std;

//***************************************************************************
// Constructor:	Postcard
//
// Description:	Initializes the link between Postcard and Parcel classes
//
// Parameters:	None
//
// Returned:		None
//***************************************************************************
Postcard::Postcard() : Parcel(){
		string initializeString = " ";

		mMessage = initializeString;
}

//***************************************************************************
// Constructor:	Postcard
//
// Description:	Initializes data members
//
// Parameters:	tid         - the tracking number to store
//							from        - parcel's sender
//              to          - parcel's reciever
//              weight      - parcel's weight in ounces
//              distance    - distance package will travel
//
// Returned:		none
//***************************************************************************
Postcard::Postcard(int tid, std::string from, std::string to, int weight,
		int distance, std::string message) :
		Parcel(tid, from, to, weight, distance) {
		mMessage = message;
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
int Postcard::getDeliveryDay()const {
		int day=0;
		const int milesPerDay = 10;
		const int oneDay = 1;
		const int twoDays = 2;
		double dayCalc = mDistance / milesPerDay;

		if (mbRush == true) {
				if (((dayCalc) < oneDay) && (dayCalc < twoDays)) {
						day = oneDay;
				}
		}
		if (mbRush == false) {
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
// Returned:		Insurance price for a Postcard
//***************************************************************************
double Postcard::getCost_Insurance() {
		double insuranceCharge = 0;
		const double flatRate = 0.15;

		if (mbIsInsured == true) {
				insuranceCharge = flatRate;
		}

		return insuranceCharge;
}

//***************************************************************************
// Function:	  getCost_Rush
//
// Description:	Will calculate how much it would be to rush an Postcard
//							parcel
// 
// Parameters:	none
//
// Returned:		Rush price for a postcard parcel
//***************************************************************************
double Postcard::getCost_Rush() {
		const double rushCharge = 0.25;
		double charge = 0.0;

		if (mbRush == true) {
				charge = rushCharge;
		}

		return charge;
}

//***************************************************************************
// Function:	  getCost_Parcel
//
// Description:	Will calculate how much it would be to mail a simple postcard
//							parcel.
// 
// Parameters:	none
//
// Returned:		Price to mail a Postcard parcel
//***************************************************************************
double Postcard::getCost_Parcel() {
		const double parcelCost = 0.15;
		return parcelCost;
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
double Postcard::getCost_Total() {
		double total = 0;
		total = getCost_Insurance() + getCost_Parcel() + getCost_Rush();

		return total;
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
void Postcard::setRush() {
		mbRush = true;
}

//***************************************************************************
// Function:	  setInsurance 
//
// Description:	Will determine if parcel has insurance
//
// Parameters:	none
//
// Returned:		none 
//***************************************************************************
void Postcard::setInsured() {

		mbIsInsured = true;
}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the Postcard to the stream
//
// Parameters:	rcIn - the stream to read from
//
// Returned:		None
//***************************************************************************
void Postcard::read(istream& rcIn) {

		Parcel::read(rcIn);
		rcIn >> mMessage;

}

//***************************************************************************
// Function:	  read
//
// Description:	Inputs the Postcard parcel to the stream
//
// Parameters:	rcOut - the stream to output to
//
// Returned:		None
//***************************************************************************
void Postcard::print(ostream& rcOut)const {
		Parcel::print(rcOut);

		if (mbIsInsured) {
				rcOut << "INSURED" << "  ";
		}
		if (mbRush) {
				rcOut << "RUSH" << "  ";
		}

		rcOut << mMessage << "  ";
}