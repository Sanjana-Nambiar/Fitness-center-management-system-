#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include "admins.h"
#include "members.h"
#include "fitnessClass.h"

using namespace std;

//=============================================================================================
//getter functions of the class
int AdminClass :: getAdminID() { return(Admin_ID); }
string AdminClass :: getFirstName() {return(firstName);}
string AdminClass :: getLastName() {return(lastName);}
string AdminClass :: getUsername() { return(username); }
string AdminClass :: getPassword() { return(password); }

//=============================================================================================
//setter functions of the class
void AdminClass :: setAdminID(int ID) { Admin_ID = ID; }
void AdminClass :: setFirstName(string name) { firstName = name; }
void AdminClass :: setLastName(string name) { lastName = name; }
void AdminClass :: setUsername(string user) { username = user; }
void AdminClass :: setPassword(string pass) { password = pass; }

//=============================================================================================
//This function prints the information of the admin
void AdminClass :: print()	
{
	cout << "Information of the Admin: \n";
	cout << "\tAdmin ID   : " << Admin_ID << endl;
	cout << "\tFirst Name : " << firstName << endl;
	cout << "\tLast Name  : " << lastName << endl;
}
//=============================================================================================
//this function adds an admin to the array of pointers
void registerAdmin(AdminClass* ptr[])
{
	string first;
	string last;
	string user;
	string pass;

	cout << "Please enter the first name of the new Admin\n"; cin >> first;
	cout << "Please enter the last name of the new Admin\n"; cin >> last;

	int ctr=0;
	for (int i = 0; i < 100; i++)
	{
		if (ptr[i] == NULL)
		{
			ptr[i] = new AdminClass();//creates a new admin 
			ctr=i;
			break;
		}
	}

	ptr[ctr]->setFirstName(first);//setting the first name
	ptr[ctr]->setLastName(last);//setting the last name 

	srand(time(NULL));//setting the seed to null
	int random = rand() % 9000 + 1000;//getting a random four digit number 
	ptr[ctr]->setAdminID(random);//setting the ID

	//using predefined functions :
	//length() to tokensize the string and get the length
	//tolower() to covert all the capital letters to small letters
	//to_string() to convert an integer to char so that we could concatenate

	for (int i = 0; i < first.length(); i++) { first[i] = tolower(first[i]); }
	user = first + std::to_string(random);
	ptr[ctr]->setUsername(user);

	for (int i = 0; i < last.length(); i++) { last[i] = tolower(last[i]); }
	pass = last + std::to_string(random);
	ptr[ctr]->setPassword(pass);
}
//=============================================================================================
//this function adds a member to the array of pointers
void registerMember(MemberClass* ptr[])
{
	string first;
	string last;
	string user;
	string pass;

	cout << "Please enter the first name of the new Member\n"; cin >> first;
	cout << "Please enter the last name of the new Member\n"; cin >> last;

	int ctr=0;
	for (int i = 0; i < 100; i++)
	{
		if (ptr[i] == NULL)
		{
			ptr[i] = new MemberClass();
			ctr=i;
			break;
		}
	}

	ptr[ctr]->setFirstName(first);
	ptr[ctr]->setLastName(last);

	srand(time(NULL));
	int random = rand() % 9000 + 1000;
	ptr[ctr]->setMemberID(random);

	//using predefined functions :
	//length() to tokensize the string and get the length
	//tolower() to covert all the capital letters to small letters
	//to_string() to convert an integer to char so that we could concatenate

	for (int i = 0; i < first.length(); i++) { first[i] = tolower(first[i]); }
	user = first + std::to_string(random);
	ptr[ctr]->setUsername(user);

	for (int i = 0; i < last.length(); i++) { last[i] = tolower(last[i]); }
	pass = last + std::to_string(random);
	ptr[ctr]->setPassword(pass);

}
//=============================================================================================
//this function adds a fitness class to the array of pointers by pointing to it
void addFitnessClass(FitnessClass* ptr[])
{//– Class ID, Class Name, Class date, Class time, Maximum ca"pacity, Room number, List of members.

	int ID;
	string Class_Name;
	int date;
	int time;
	int max_capacity;
	int room_no;

	cout <<"Please enter the Class ID of the new class\n"; cin >> ID;
	cout <<"Please enter the name of the new Class\n"; cin >> Class_Name;
	cout <<"Please enter the date of the new class\n"; cin >> date;
	cout <<"Please enter the time of the new class\n"; cin >> time;
	cout <<"Please enter the maximum capacity of the new class\n"; cin >> max_capacity;
	cout <<"Please enter the room number of the new class\n"; cin >> room_no;

	for (int i = 0; i < 100; i++)
	{
		if (ptr[i] == NULL)
		{
			ptr[i] = new FitnessClass(ID, Class_Name, date, time, max_capacity, room_no);
			break;
		}
	}
}
//=============================================================================================
//this function deletes the class which the user wants to delete using the classID
int deleteFitnessClass(FitnessClass* ptr[])
{
	int ID;
	cout <<"Please enter the class ID of the class to delete\n"; 
	cin >> ID;

	int num = -1;
	for(int i = 0; i < 100; i++)
	{
		if (ptr[i]->getClassID() == ID)
		{
			num = i;
			break;
		}
	}
	if(num == -1){cout <<"Wrong Class ID\n"; return 0;}
	
	while(ptr[num] != NULL)
	{
		ptr[num] = ptr[num+1];
		num++;
	}
	ptr[num+1]=NULL;
	return 0;
}
//=============================================================================================
//this function asks the user for the class ID and provides the user options to update the information of a particular class
int updateClassDetails(FitnessClass* ptr[])
{
	int ID;
	string Class_Name;
	int date;
	int time;
	int max_capacity;
	int room_no;

	int options;
	cout <<"Please enter the Class ID to update\n"; cin >> ID;

	int num=0;
	for(int i=0; i<100; i++)
	{
		if(ptr[i]->getClassID() == ID)
		{
			num=i;
			break;
		}
		else
		{
			cout<<"Wrong Class ID\n";
			return 0;
		}
	}
	cout <<"Please enter from options [1-5] to update\n"
		<<"1) Class name\n"
		<<"2) Class Capacity\n"
		<<"3) Room number of the Class\n"
		<<"4) Class date\n"
		<<"5) Class time\n";
	cin >> options;
	switch(options)
	{
	case 1:			
		cout<<"Please enter the class name to update\n"; cin >> Class_Name;
		ptr[num]->setClassName(Class_Name);
		break;
	case 2:
		cout<<"Please enter the class capacity to update\n"; cin >> max_capacity;
		ptr[num]->setMaximumCapacity(max_capacity);
		ptr[num]->listOfMemberIDs(max_capacity);
		break;
	case 3:
		cout<<"Please enter the class room number to update\n"; cin >> room_no;
		ptr[num]->setRoomNum(room_no);
		break;
	case 4:
		cout<<"Please enter the class date to update\n"; cin >> date;
		ptr[num]->setClassDate(date);
		break;
	case 5:
		cout<<"Please enter the class time to update\n"; cin >> time;
		ptr[num]->setClassTime(time);
		break;
	default:
		cout <<"wrong option\n";
		break;
	}
	return 0;
}
//=============================================================================================