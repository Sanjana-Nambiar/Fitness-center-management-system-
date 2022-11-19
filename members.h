#ifndef _MEMBERS_H  //include headers
#define _MEMBERS_H

#include <string>//Required for string
#include <cstdlib>
#include <array>
#include <ctype.h>
#include "fitnessClass.h"

// A member can mainly book a spot in a class, and cancel a booking.
class MemberClass
{
private:
	int Member_ID;
	std::string firstName;
	std::string lastName;
	std::string username;
	std::string password;
public:
	MemberClass() : Member_ID(0), firstName(" "), lastName(" "), username(" "), password(" ") {}//default constructor
	MemberClass(int Mid, std::string fname, std::string lname, std::string user, std::string pass)//non-default constructor
		: Member_ID(Mid), firstName(fname), lastName(lname), username(user), password(pass) {}

	//getter functions of the class
	int getMemberID();
	std::string getFirstName();
	std::string getLastName();
	std::string getUsername();
	std::string getPassword();

	//setter functions of the class
	void setMemberID(int ID);
	void setFirstName(std::string name);
	void setLastName(std::string name);
	void setUsername(std::string user);
	void setPassword(std::string pass);
	
	void print();//prints the information of the admin
	~MemberClass();//destructor 
};

//this function takes the class ID and then adds the Member Id to the list of Members array of a class after checking whether the class is free or not
void bookAClass(FitnessClass* Fptr[], MemberClass* Mptr[], int num);
//this function take the class ID and then checks whether the member ID is there or not, if its there then it deletes it
void cancelBooking(FitnessClass* ptr[], MemberClass* Mptr[], int num);

#endif
