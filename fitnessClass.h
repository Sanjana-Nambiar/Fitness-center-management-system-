#ifndef _FITNESSCLASS_H  //include headers
#define _FITNESSCLASS_H

#include <string>
#include <cstdlib>
#include <ctype.h>

class FitnessClass
{
private://– Class ID, Class Name, Class date, Class time, Maximum capacity, Room number, List of members.
	int Class_ID;
	std :: string ClassName;
	int Class_date;
	int Class_time;
	int maxCapacity;
	int roomNum;
	int* listOfMembers = new int[maxCapacity];
public:
	FitnessClass() : Class_ID(0), ClassName(" "), Class_date(0), Class_time(0), maxCapacity(0), roomNum(0) {listOfMembers = 0;}//default constructor
	FitnessClass(int ID, std :: string Cname, int Cdt, int Ctime, int maxCapa, int roomNo)//non-default constructor
		: Class_ID(ID), ClassName(Cname), Class_date(Cdt), Class_time(Ctime), maxCapacity(maxCapa), roomNum(roomNo) 
		{
			for(int i = 0; i<maxCapacity; i++)
			{listOfMembers[i] = 0;}
		}

	//getter functions of the class
	int getClassID();
	std :: string getClassName();
	int getClassDate();
	int getClassTime();
	int getMaximumCapacity();
	int getRoomNumber();

	//setter functions of the class
	void setClassName(std :: string name);
	void setClassDate(int date);
	void setClassTime(int time);
	void setMaximumCapacity(int max);
	void setRoomNum(int No);

	void addMember(int memberID);//this function takes the member ID and then appends it to the last of the array of members
	void deleteMember(int memberID);//this function takes the member ID nd then deletes the given member Id from the list of members
	bool checkMemberID(int memberID);//this function checks whether the member ID given is there in the list of members or not
	void listOfMemberIDs(int max);//this function resizes the array of list of the member ID according to the max capacity provided
	void printList();//this function prints the list of member IDs
	bool vacancyCheck();//this function checks whether is there any empty space or not

	void print();//prints the information of the admin
	~FitnessClass() { delete[] listOfMembers; }//destructor 
};

#endif