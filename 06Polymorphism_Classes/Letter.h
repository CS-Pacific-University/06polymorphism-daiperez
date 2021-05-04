#pragma once

#include "Parcel.h"
#include <iostream>
#include <string>
using namespace std;

class Letter:public Parcel {
public:

		Letter();
		Letter(int tid, string from, string to, int weight, int distance);

		virtual int getDeliveryDay()const;
		virtual double getCost_Insurance()const;
		virtual double getCost_Rush()const;
		virtual double getCost_Parcel()const;
		virtual double getCost_Total()const;

		virtual void setInsured();
		virtual void setRush();

		virtual bool read(istream& rcIn);
		virtual void print(ostream& rcOut)const;

};
