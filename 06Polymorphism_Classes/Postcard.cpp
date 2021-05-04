#include "Postcard.h"
#include <iostream>
#include<string>

using namespace std;

Postcard::Postcard() : Parcel(){
		string initializeString = " ";

		mMessage = initializeString;
}

Postcard::Postcard(int tid, std::string from, std::string to, int weight, int distance, std::string message) :
		Parcel(tid, from, to, weight, distance) {
		mMessage = message;
}

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

double Postcard::getCost_Insurance()const {
		double insuranceCharge = 0;
		const double flatRate = 0.15;

		if (mbIsInsured == true) {
				insuranceCharge = flatRate;
		}

		return insuranceCharge;
}

double Postcard::getCost_Rush()const {
		const double rushCharge = 0.25;
		double charge = 0.0;

		if (mbRush == true) {
				charge = rushCharge;
		}

		return charge;
}

double Postcard::getCost_Parcel()const {
		const double parcelCost = 0.15;
		return parcelCost;
}

double Postcard::getCost_Total()const {
		double total = 0;
		total = getCost_Insurance() + getCost_Parcel() + getCost_Rush();

		return total;
}

void Postcard::setRush() {
		mbRush = true;
}

void Postcard::setInsured() {

		mbIsInsured = true;
}

bool Postcard::read(istream& rcIn) {
		bool bRead = Parcel::read(rcIn);

		if (rcIn >> mMessage) {
				bRead = true;
		}
		else {
				bRead = false;
		}

		return bRead;
}

void Postcard::print(ostream& rcOut) {
		Parcel::print(rcOut);

		if (mbIsInsured) {
				rcOut << "INSURED" << "  ";
		}
		if (mbRush) {
				rcOut << "RUSH" << "  ";
		}

		rcOut << mMessage << "  ";
}