#ifndef _ADMINS_H  //include headers
#define _ADMINS_H

#include <string>//Required for string
#include <cstdlib>
#include <array>
#include "fitnessClass.h"
#include "members.h"
#include "admins.h"

//An admin can mainly add/delete fitness classes, and register a member. 
class AdminClass
{
private:
	int Admin_ID;
	std::string firstName;
	std::string lastName;
	std::string username;
	std::string password;
public:
	AdminClass() : Admin_ID(0), firstName(" "), lastName(" "), username(" "), password(" ") {}//default constructor
	AdminClass(int Aid, std::string fname, std::string lname, std::string user, std::string pass)//non-default constructor
		: Admin_ID(Aid), firstName(fname), lastName(lname), username(user), password(pass) {}

	//getter functions of the class
	int getAdminID();
	std::string getFirstName();
	std::string getLastName();
	std::string getUsername();
	std::string getPassword();

	//setter functions of the class
	void setAdminID(int ID);
	void setFirstName(std::string name);
	void setLastName(std::string name);
	void setUsername(std::string user);
	void setPassword(std::string pass);

	void print();//prints the information of the admin
	~AdminClass();//destructor 
};

void registerAdmin(AdminClass* ptr[]);//based on the information provided by the admin, the function creates a admin and points the next available pointer to the new admin
void registerMember(MemberClass* ptr[]);//based on the information provided by the admin, the function creates a member and points the next available pointer to the new member
void addFitnessClass(FitnessClass* ptr[]);//based on the information provided by the admin, the function creates a class and points the next available pointer to the new class
int deleteFitnessClass(FitnessClass* ptr[]);//the function deletes the class by the class id provided by the admin 
int updateClassDetails(FitnessClass* ptr[]);//the function gives different options to the admin to update the class details

#endif