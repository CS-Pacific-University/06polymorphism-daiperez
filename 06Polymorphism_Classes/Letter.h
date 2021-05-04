//***************************************************************************
// File name:	 Letter.h
// Author:		 Daisy Perez
// Date:		   5/4/2021
// Class:		   CS 250
// Assignment: Polymorphism 
// Purpose:		 Sub class Letter representing information for a Letter 
//             parcel.
//***************************************************************************

#pragma once

#include "Parcel.h"
#include <iostream>
#include <string>
using namespace std;

class Letter:public Parcel {
public:

		Letter();
		Letter(int tid, string from, string to, int weight, int distance);

		int getDeliveryDay()const;
		double getCost_Insurance();
		double getCost_Rush();
		double getCost_Parcel();
		double getCost_Total();

		void setInsured();
		void setRush();

		void read(istream& rcIn);
		void print(ostream& rcOut)const;

};
