#pragma once

#include <iostream>
using namespace std;

class Parcel {

public:
		Parcel();
		Parcel(int tid, string from, string to, int weight, int distance);

		
		virtual int getDeliveryDay()const = 0;
		virtual double getCost_Insurance() = 0;
		virtual void setInsured() = 0;
		virtual double getCost_Rush() = 0;
		virtual void setRush() = 0;
		virtual	double getCost_Total() = 0;
		virtual double getCost_Parcel() = 0;

		bool  getInsured();
		bool getRush();
		int getTID();

		virtual bool read(istream& rcIn);
		virtual void print(std:: ostream& rcOut)const;

		

protected:
		int mWeight;
		int mDistance;
		bool mbIsInsured;
		bool mbRush;
		bool mbDelivered;

private:

		int mTrackingID;
		string mTo;
		string mFrom;
		double mCost;

};