#include "MemberType.h"

MemberType::MemberType() {
	membershipNumber = 0;
}
MemberType::MemberType(const string& newFirstName, const string& newLastName, int newMembershipNo) {
	firstName = newFirstName;
	lastName = newLastName;
	membershipNumber = newMembershipNo;
}

void MemberType::setMemberInfo(const string& newFirstName, const string& newLastName, int newMembershipNo) {
	firstName = newFirstName;
	lastName = newLastName;
	membershipNumber = newMembershipNo;
}

string MemberType::getFirstName() const {
	return firstName;
}
string MemberType::getLastName() const {
	return lastName;
}
int MemberType::getMembershipNo() const {
	return membershipNumber;
}

void MemberType::printName() const {
	cout << lastName << ", " << firstName << endl;
}
void MemberType::printMemberInfo() const {
	cout << membershipNumber << " - " << firstName << " " << lastName << endl;
}

MemberType::~MemberType() {}