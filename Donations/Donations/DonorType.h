/*
NguyenNguyenSituation
Nguyen, Joseph
Nguyen, Lily
CS A250
September 24, 2025

Project 1
*/

#ifndef DONORTYPE_H
#define DONORTYPE_H

#include "MemberType.h"

class DonorType : public MemberType {

public:

	DonorType();
	DonorType(const string& firstName, const string& lastName, int membershipNumber, double newDonationAmount);

	void setDonorInfo(const string& firstName, const string& lastName, int membershipNumber, double newDonationAmount);
	void setAmountDonated(double newAmountDonated);

	double getAmountDonated() const;

	void printDonor() const;
	void printDonation() const;

	~DonorType();

private:

	double donationAmount;

};

#endif