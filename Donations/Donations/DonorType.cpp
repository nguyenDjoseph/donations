#include "DonorType.h"
#include <iomanip>

DonorType::DonorType() : MemberType() {
	donationAmount = 0;
}

DonorType::DonorType(const string& firstName, const string& lastName, int membershipNumber, double newDonationAmount) : MemberType(firstName, lastName, membershipNumber) {
	donationAmount = newDonationAmount;
}

void DonorType::setDonorInfo(const string& firstName, const string& lastName, int membershipNumber, double newDonationAmount) {
	setMemberInfo(firstName, lastName, membershipNumber);
	donationAmount = newDonationAmount;
}

void DonorType::setAmountDonated(double newAmountDonated) {
	donationAmount = newAmountDonated;
}

double DonorType::getAmountDonated() const {
	return donationAmount;
}

void DonorType::printDonor() const {
	printMemberInfo();
}

void DonorType::printDonation() const {
	cout << getLastName() << ", " << getFirstName() << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "    Donation amount: $" << donationAmount;
}

DonorType::~DonorType() {}

