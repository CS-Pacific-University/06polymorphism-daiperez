#include "Parcel.h"
#include <iostream>
#include <string>

Parcel::Parcel() {
		mTrackingID = 0;
		mTo = " ";
		mFrom = " ";
		mCost = 0.0;
}

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


bool Parcel::getInsured() {
		return mbIsInsured;
}

bool Parcel::getRush() {
		return mbRush;
}

int Parcel::getTID()  {
		return mTrackingID;
}


bool Parcel::read(istream& rcIn) {
		string parcelType;
		bool bAbleToRead = false;

		if (!(rcIn >> parcelType >> mTrackingID >> mTo >> mFrom >> mWeight >> mDistance)) {
		}
		else {
				bAbleToRead = true;
		}

		return (bAbleToRead);
}

void Parcel::print(ostream& rcOut)const {
		rcOut << "TID: " << mTrackingID << " From: " << mFrom << " To: " << mTo << " ";
}
