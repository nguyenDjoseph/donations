/*
Nguyen, Joseph
*/

#include "DonorList.h"

//default constructor
DonorList::DonorList() 
{
	donors = new list<DonorType>;
}

//copy constructor
DonorList::DonorList(const DonorList& otherList)
{
	donors = new list<DonorType>(*otherList.donors);
}

// overloaded assignment operator
DonorList& DonorList::operator=(const DonorList& otherList) 
{
	if (&otherList != this)
		*donors = *(otherList.donors);
	return *this;
}

//addDonor
void DonorList::addDonor(const string& firstName, const string& lastName, int memberNum, double donatedAmount) const
{
	donors->push_back(DonorType(firstName, lastName, memberNum, donatedAmount));
}

//getNumberOfDonors
int DonorList::getNumberOfDonors() const 
{
	return static_cast<int>(donors->size());
}

//searchID
bool DonorList::searchID(int memberNum) const 
{
	list<DonorType>::iterator iter;
	return searchDonorLocation(memberNum, iter);
}

//getTotalDonations
double DonorList::getTotalDonations() const 
{
	double sum = 0;
	list<DonorType>::const_iterator iter = donors->cbegin();
	while (iter != donors->cend()) 
	{
		sum += iter->getAmountDonated();
		iter++;
	}
	return sum;
}

//deleteDonor
void DonorList::deleteDonor(int memberNum) const
{
	list<DonorType>::iterator iter;
	if (searchDonorLocation(memberNum, iter))
		donors->erase(iter);
}

//destroyList
void DonorList::destroyList() const
{
	donors->clear();
}

//destructor
DonorList::~DonorList() 
{
	destroyList();
	delete donors;
	donors = nullptr;
}

// searchDonorByMemNo
bool DonorList::searchDonorByMemberNo(string& donorName, double& donatedAmount, int idNo) const
{
	list<DonorType>::iterator iter;
	
	if (searchDonorLocation(idNo, iter))
	{
		donorName = iter->getLastName() + ", " + iter->getFirstName();
		donatedAmount = iter->getAmountDonated();
		return true;
	}
	else
		return false;
}

//highest donation
double DonorList::highestDonation(string& firstName, string& lastName, int& idNo) const 
{
	if (!donors->empty()) 
	{
		list<DonorType>::const_iterator iter = donors->cbegin();
		double max = -1.0; // first one in list is highest donor

		while (iter != donors->cend()) 
		{
			if (iter->getAmountDonated() > max) 
			{
				max = iter->getAmountDonated();
				firstName = iter->getFirstName();
				lastName = iter->getLastName();
				idNo = iter->getMembershipNo();
			}
			iter++;
		}
		return max;
	}
	return 0.0;
}

//printAllDonors
void DonorList::printAllDonors(string& donor) const 
{
	donor = ""; // reset donor string
	if (!donors->empty()) 
	{
		list<DonorType>::const_iterator iter = donors->cbegin();
		while (iter != donors->cend()) 
		{
			donor += to_string(iter->getMembershipNo()) + " - " + iter->getLastName() + ", " + iter->getFirstName() + "\n";
			iter++;
		}
	}
	else
		donor = "No donors to print.";
}

bool DonorList::searchDonorLocation(int idNo, list<DonorType>::iterator& iter) const
{
	iter = donors->begin();
	while (iter != donors->end())
	{
		if (iter->getMembershipNo() == idNo)
			return true;
		iter++;
	}
	return false;
}