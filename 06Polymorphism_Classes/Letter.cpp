#include "Letter.h"
#include <iostream>
#include<string>

using namespace std;

Letter::Letter(): Parcel() {

}

Letter::Letter(int tid, std::string from, std::string to, int weight, int distance) :
		Parcel(tid, from, to, weight, distance) {
}

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

double Letter::getCost_Insurance()const {
		double insuranceCharge = 0;
		const double rate = 0.45;

		if (mbIsInsured == true) {
				insuranceCharge = rate;
		}

		return insuranceCharge;
}

double Letter::getCost_Rush()const {
		double rushCharge = 0;
		const double rushRate = 0.1;

		if (mbRush == true) {
				rushCharge = rushRate * getCost_Parcel();
		}

		return rushCharge;
}

double Letter::getCost_Parcel()const {
		const double ratePerOunce = 0.45;
		double cost_Parcel = 0;

		cost_Parcel = mWeight * ratePerOunce;

		return cost_Parcel;
}

double Letter::getCost_Total()const {
		double total = 0;
		total = getCost_Parcel() + getCost_Insurance() + getCost_Rush();
		return total;
}

void Letter::setInsured() {
		mbIsInsured = true;
}

void Letter::setRush() {
		mbRush = true;
}

bool Letter::read(istream& rcIn) {
		bool bRead = Parcel::read(rcIn);

		if (bRead) {
				bRead = true;
		}
		else {
				bRead = false;
		}

		return bRead;

}

void Letter::print(ostream& rcOut)const {
		Parcel::print(rcOut);

		if (mbIsInsured) {
				rcOut << " INSURED  ";
		}
		if (mbRush) {
				rcOut << " RUSH  ";
		}
}