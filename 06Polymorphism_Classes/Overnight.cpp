#include "Overnight.h"
#include <iostream>
#include <string>

using namespace std;

Overnight::Overnight():Parcel() {
		const int initilize = 0;
		mVolume = initilize;
}

Overnight::Overnight(int tid, std::string from, std::string to, int weight, int distance, int volume) :
		Parcel(tid, from, to, weight, distance) {
		mVolume = volume;
}

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

double Overnight::getCost_Insurance()const {
		const double insuranceFlatRate = 1.25;
		double charge = 0;

		if (mbIsInsured == true) {
				charge = insuranceFlatRate;
		}

		return charge;
}

double Overnight::getCost_Rush()const {
		const double rushRate = 0.75;
		double charge=0;

		if (mbRush == true) {
				charge = getCost_Parcel() * rushRate;
		}

		return charge;
}

double Overnight::getCost_Parcel()const {
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

double Overnight::getCost_Total()const {
		double total = 0;

		total = getCost_Insurance() + getCost_Parcel() + getCost_Rush();

		return total;
}

void Overnight::setInsured() {
		mbIsInsured = true;
}

void Overnight::setRush() {
		mbRush = true;
}

bool Overnight::read(istream& rcIn) {
		bool bRead = Parcel::read(rcIn);

		if (rcIn >> mVolume) {
				bRead = true;
		}
		else {
				bRead = false;
		}

		return bRead;
}

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