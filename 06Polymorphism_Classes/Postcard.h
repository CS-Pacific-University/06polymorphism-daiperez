#pragma once

#include "Parcel.h"
#include <iostream>
#include <string>
using namespace std;

class Postcard: public Parcel{
public:
		Postcard();
		Postcard(int tid, string from, string to, int weight, int distance, string message);

		int getDeliveryDay()const;
		double getCost_Insurance()const;
		double getCost_Rush()const;
		double getCost_Parcel()const;
		double getCost_Total()const;

		void setInsured();
		void setRush();

		bool read(istream& rcIn);
		void print(ostream& rcOut);

private:
		string mMessage;
};