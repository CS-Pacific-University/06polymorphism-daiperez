//***************************************************************************
// File name:	 Parcel.cpp
// Author:		 Daisy Perez
// Date:		   5/4/2021
// Class:		   CS 250
// Assignment: Polymorphism 
// Purpose:		 Ustilizes the declared functions in Parcel.h
//***************************************************************************

#include "Parcel.h"
#include <iostream>
#include <string>

//***************************************************************************
// Constructor:	Parcel
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
Parcel::Parcel(int tid, std::string from, std::string to, int weight, int distance){

		mTrackingID = tid;
		mWeight = weight;
		mDistance = distance;
		mTo = to;
		mFrom = from;
		mbIsInsured = false;
		mbRush = false;
		mbDelivered = false;

}

//*****************************************************************************
// Function:    getInsured
//
// Description: Determines if parcel's mInsured is true or false.
//
// Parameters:  None
//
// Returned:    mInsured
//*****************************************************************************
bool Parcel::getInsured() {
		return mbIsInsured;
}

//*****************************************************************************
// Function:    getRush 
//
// Description:TDetermines if parcel's mRush is true or false.
//
// Parameters:  None
//
// Returned:    mRush
//*****************************************************************************
bool Parcel::getRush() {
		return mbRush;
}

//*****************************************************************************
// Function:    getTID
//
// Description: Will access the Tracking ID number
//
// Parameters:  None
//
// Returned:    mTrackingID
//*****************************************************************************
int Parcel::getTID()  {
		return mTrackingID;
}

//*****************************************************************************
// Function:    read
//
// Description: will read in data from the input stream
//
// Parameters:	rcIn		-Input stream
//
// Returned:    None
//*****************************************************************************
void Parcel::read(istream& rcIn) {
		rcIn >> mTrackingID >> mTo >> mFrom >> mWeight >> mDistance;
}

//*****************************************************************************
// Function:    print
//
// Description: will display data to the screen
//
// Parameters:	rcOut		-Output stream
//
// Returned:    None
//*****************************************************************************
void Parcel::print(ostream& rcOut)const {
		rcOut << endl<< "TID: " << mTrackingID << " From: " << mFrom << " To: " << mTo << " ";
}
