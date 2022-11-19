#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include "fitnessClass.h"

using namespace std; 

//=============================================================================================
//getter functions of the class
int FitnessClass :: getClassID() { return(Class_ID); }
string FitnessClass :: getClassName() { return(ClassName); }
int FitnessClass :: getClassDate() {return(Class_date);}
int FitnessClass :: getClassTime() {return(Class_time);}
int FitnessClass :: getMaximumCapacity() { return(maxCapacity); }
int FitnessClass :: getRoomNumber() {return(roomNum);}

//=============================================================================================
//setter functions of the class
void FitnessClass :: setClassName(string name) { ClassName = name; }
void FitnessClass :: setClassDate(int date) { Class_date = date; }
void FitnessClass :: setClassTime(int time) { Class_time = time; }
void FitnessClass :: setMaximumCapacity(int max) { maxCapacity = max; }
void FitnessClass :: setRoomNum(int No) { roomNum = No; }

//=============================================================================================
//this function adds the member id to the list of member id array
void FitnessClass :: addMember(int memberID)
{
	for (int i = 0; i < maxCapacity; i++)
	{
		if (listOfMembers[i] == 0)
		{
			listOfMembers[i] = memberID;
			break;
		}
	}
}
//=============================================================================================
//this function deletes a memeber id from the list of member id array
void FitnessClass :: deleteMember(int memberID)
{
	int sort;
	int i=0;
	for(int i = 0; i<maxCapacity; i++)
	{
		if (listOfMembers[i] == memberID)
		{
			listOfMembers[i] = 0;
			sort = i;
			break;
		}	
	}
	for(int i = sort; i<maxCapacity; i++)
	{
		listOfMembers[i] = listOfMembers[i+1];
	}
	listOfMembers[maxCapacity-1] = 0;
}
//=============================================================================================
//this funcetion returns a bool value if the member id exits in the list of array or not
bool FitnessClass :: checkMemberID(int memberID)
{
	for(int i = 0; i<maxCapacity; i++)
	{
		if(listOfMembers[i] == memberID)
			return(true);
	}
	return(false);
}
//=============================================================================================
//this function resizes the list of member id array to the sixe provided by the user
void FitnessClass :: listOfMemberIDs(int max)
{
	int* newArray = new int[max];
	if (max > maxCapacity)
	{
		for (int i = 0; i < maxCapacity; i++)
		{
		newArray[i] = listOfMembers[i];
		}
	}
	else
	{
		for (int i = 0; i < max; i++)
		{
			newArray[i] = listOfMembers[i];
		}	
	}
	maxCapacity = max;
	delete[] listOfMembers;

	int* lisOfMembers = new int[max];
	for (int i = 0; i < max; i++)
	{
		listOfMembers[i] = newArray[i];
	}
}
//=============================================================================================
//this function returns a bool value is the class is vacant
bool FitnessClass :: vacancyCheck()
{
	for(int i=0; i<maxCapacity; i++)
	{ 
		if(listOfMembers[i] == 0)
		{
			return(true);
		}
	}
	return(false);
}
//=============================================================================================
void FitnessClass :: printList()
{
	for(int i=0; i<maxCapacity; i++)
	{
		cout<<listOfMembers[i]<<endl;
	}
}
//=============================================================================================
void FitnessClass :: print()
{
	cout << "Information of the Fitness Class: \n";
	cout << "\tClass ID         : " << Class_ID << endl;
	cout << "\tClass Name       : " << ClassName << endl;
	cout << "\tClass Date       : " << Class_date << endl;
	cout << "\tClass Time       : " << Class_time << endl;
	cout << "\tMaximum Capacity : " << maxCapacity << endl;
	cout << "\tRoom Number      : " << roomNum << endl;
}
//=============================================================================================