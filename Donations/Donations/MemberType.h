/*
Nguyen, Joseph
CS A250
September 16, 2016

Project 1A: MemberType Class
*/

#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <iostream>
#include <string>

using namespace std;

class MemberType {

public:

	MemberType();
	MemberType(const string& firstName, const string& lastName, int membershipNumber);

	void setMemberInfo(const string& firstName, const string& lastName, int membershipNumber);

	string getFirstName() const;
	string getLastName() const;
	int getMembershipNo() const;

	void printName() const;
	void printMemberInfo() const;

	~MemberType();

private:
	string firstName;
	string lastName;
	int membershipNumber;
};

#endif