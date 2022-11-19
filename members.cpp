#include <iostream>
#include <string>
#include <cstdlib>
#include "members.h"
#include "fitnessClass.h"

using namespace std;

//=============================================================================================
//getter functions of the class
int MemberClass :: getMemberID() { return(Member_ID); }
string MemberClass :: getFirstName() {return(firstName);}
string MemberClass :: getLastName() {return(lastName);}
string MemberClass :: getUsername() { return(username); }
string MemberClass :: getPassword() { return(password); }

//=============================================================================================
//setter functions of the class
void MemberClass :: setMemberID(int ID) { Member_ID = ID; }
void MemberClass :: setFirstName(string name) { firstName = name; }
void MemberClass :: setLastName(string name) { lastName = name; }
void MemberClass :: setUsername(string user) { username = user; }
void MemberClass :: setPassword(string pass) { password = pass; }

//=============================================================================================
void MemberClass :: print()
{
	cout << "Information of the member: \n";
	cout << "\tMember ID  : " << Member_ID << endl;
	cout << "\tFirst Name : " << firstName << endl;
	cout << "\tLast Name  : " << lastName << endl;
}
//=============================================================================================
//this function enters the member id of the member to the list of members of the class they want to enter in
void bookAClass(FitnessClass* Fptr[], MemberClass* Mptr[], int num)
{
	int ClassID;
	int MemberID;
	int error = -1;

	MemberID = Mptr[num]->getMemberID();
	cout <<"Please enter the class ID of the class you want to enroll in\n"; cin >> ClassID;
	
	int i = 0;
	while(Fptr[i] != NULL)
	{
		error = 0;
		if(Fptr[i]->getClassID() == ClassID && Fptr[i]->vacancyCheck())//checks whether the class exits or not & checks whether class is vacant or not
		{
			Fptr[i]->addMember(MemberID);//adds the member to the list of member
			error = 1;
			break;
		}
		i++;
	}
	if(error==0){cout<<"Error! Either the you have entered the wrong Class ID or the class is full\n";}
	else {cout<<"You are successfully enrolled in the class\n";}	
}
//=============================================================================================
//this function removes the member id from the list of members of the class that the user wnat to cancel booking in
void  cancelBooking(FitnessClass* Fptr[],  MemberClass* Mptr[], int num)
{
	int ClassID;
	int MemberID;
	int error = -1;

	MemberID = Mptr[num]->getMemberID();
	cout <<"Please enter the class ID you want to cancel booking for\n"; cin >> ClassID;

	int i = 0;
	while(Fptr[i] != NULL)
	{
		error = 0;
		if(Fptr[i]->checkMemberID(MemberID))//checks whether the member ius enrolled in the class or not
		{
			Fptr[i]->deleteMember(MemberID);//deletes the member id from the list
			error = 1;
			break;
		}
		i++;
	}
	if(error==0){cout<<"Error! Either the you have entered the wrong Class ID or you are not enrolled in the list\n";}
	else {cout<<"You have successfully cancelled your booking to the class\n";}	
}
//=============================================================================================
