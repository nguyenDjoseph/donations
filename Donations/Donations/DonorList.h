#ifndef DONORLIST_H
#define DONORLIST_H

#include "DonorType.h"

#include <iostream>
#include <string>		
#include <iomanip>
#include <list>

using namespace std;

class DonorList
{
public:
	//default constructor
	DonorList();

	//copy constructor
	DonorList(const DonorList& otherList);

	// assignment operator
	DonorList& operator=(const DonorList& otherList);

	//addDonor
	void addDonor(const string& firstName, const string& lastName, int memberNum, double donatedAmount) const;

	//getNumberOfDonors
	int getNumberOfDonors() const;

	//searchID
	bool searchID(int memberNum) const;

	//getTotalDonations
	double getTotalDonations() const;

	//deleteDonor
	void deleteDonor(int memberNum) const;

	//destroyList
	void destroyList() const;

	//destructor
	~DonorList();

	// searchDonorByMemberNo (win form)
	bool searchDonorByMemberNo(string& donorName, double& donatedAmount, int idNo) const;

	// highestDonation (win form)
	double highestDonation(string& firstName, string& lastName, int& idNo) const;

	// printAllDonors (win form)
	void printAllDonors(string& donor) const;


private:
	list<DonorType> *donors;
	bool searchDonorLocation(int idNo, list<DonorType>::iterator& iterator) const;
};

#endif

