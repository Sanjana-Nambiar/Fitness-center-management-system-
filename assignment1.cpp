#include <iostream>
#include <iomanip>//Required for setw()
#include <fstream>//Required for ifstream, ofstream
#include <string>//Required for string
#include <cstdlib>
#include <array>
#include <ctype.h>
#include "fitnessClass.h"
#include "members.h"
#include "admins.h"

using namespace std;

void ListAdminOptions();
void ListMemberOptions();

template <typename C>
bool login(C* ptr[], int& num);//Login function to enter the system by any existing user
int viewClassesWithVacancies(FitnessClass* ptr[]);//shows vacant fitness class for the member to enroll
void quitProgram(FitnessClass* Fitptr[], MemberClass* Memptr[], AdminClass* Adptr[]);//this function quits the program and stores the information in respective folders

//=============================================================================================
int main()
{
	//declaring big static arrays of pointers to point to respective objects
	AdminClass* Admins[100] = {NULL};
	MemberClass* Members[100] = {NULL};
	FitnessClass* Classes[100] = {NULL};

	Admins[0] = new AdminClass(1, "admin", "admin", "admin1", "admin1");//default admin

	bool restart = true;
	while(restart)//main loop that restarts the whole system
	{
		string category;
		cout << "Welcome to the fitness management system!\n";
		int num = -1;
		bool log = true;
		while (log)//login loop to repeat the login process untill correct details are provided
		{
			cout << "Please enter the category of your account before logging in: [admin/member]\n";
			cin >> category;
			if (category == "admin")
			{
				log = login<AdminClass>(Admins, num);//login template function for admins
			}
			else if (category == "member")
			{
				log = login<MemberClass>(Members, num);//login template function for admins
			}
			else
			{
				cout << "Wrong category\n";
				log = true;
			}
		}

		int options;
		if (category == "admin")//if the user is a admin then run the following commands
		{
			ListAdminOptions();//lists the operations for admins
			bool cont = true; 
			while(cont)//loop for continuing doing operations till the user wants to exit or log out
			{
				cout << "Please enter a value from [1-8]\n";
				cin >> options;
				switch (options)
				{
				case 1:
					registerAdmin(Admins);
					for (int i = 0; i<100; i++)
					{
						if(Admins[i]==NULL)
							break;
						Admins[i]->print();
					}
					break;
				case 2:
					registerMember(Members);
					for (int i = 0; i<100; i++)
					{
						if(Members[i]==NULL)
							break;
						Members[i]->print();
					}
					break;
				case 3:
					addFitnessClass(Classes);
					for (int i = 0; i<100; i++)
					{
						if(Classes[i]==NULL)
							break;
						Classes[i]->print();
					}
					break;
				case 4:
					deleteFitnessClass(Classes);
					break;
				case 5:
					updateClassDetails(Classes);
					break;
				case 6:
					viewClassesWithVacancies(Classes);
			 		break;
				case 7:
					quitProgram(Classes, Members, Admins);
					break;
				case 8:
					cont = false;
					break;
				default:
					cout <<"You have entered a wrong option\n";
					break;
				}
			}
		}
		else if (category == "member")//if the user is a member then run the following commands
		{
			ListMemberOptions();//list of operations for a member
			bool cont = true; 
			while(cont)//loop for continuing doing operations till the user wants to exit or log out
			{
				cout << "Please enter a value from [1-5]\n";
				cin >> options;
				switch(options)
				{
				case 1:
					bookAClass(Classes, Members, num);
					break;
				case 2:
					cancelBooking(Classes, Members, num);
					break;
				case 3:
					viewClassesWithVacancies(Classes);
					break;
				case 4:
					quitProgram(Classes, Members, Admins);
					break;
				case 5:
					cont = false; 
					break;
				default:
					cout <<"You have entered a wrong option\n";
					break;
				}
			}
		}
	}
	return 0;
}
//=============================================================================================
//list of all the options availale to a admin 
void ListAdminOptions()
{
	cout << "List of available Operations for Admins:" << endl
		<< "1) Register a new Admin" << endl
		<< "2) Register a new member" << endl
		<< "3) Add a fitness class" << endl
		<< "4) Delete a fitness class" << endl
		<< "5) Update the details of a fitness class" << endl
		<< "6) Display Classes with Vacancies" << endl
		<< "7) Quit the program" << endl
		<< "8) Log out" << endl;
}
//=============================================================================================
//list of all the options available to a member
void ListMemberOptions()
{
	cout << "List of available Operations for Admins:" << endl
		<< "1) Book a class" << endl
		<< "2) Cancel a Class" << endl
		<< "3) Display Classes with Vacancies" << endl
		<< "4) Quit the program" << endl
		<< "5) Log out" << endl;
}
//=============================================================================================
//a template function that can be used by any user to login into the system if and only if they are added to the system
template <typename C>
bool login(C* ptr[], int& num)
{
	//asking user for details 
	string category, user, pass;
	cout << "Please enter your username:\n";
	cin >> user;
	cout << "Please enter your password:\n";
	cin >> pass;
	int i = 0;
	//iterates over the array of pointers and compares the username and password to check whether the user exits 
	do
	{
		if (ptr[i]->getUsername() == user)//checking whether the username is valid or not
		{
			if (ptr[i]->getPassword() == pass)//checking whether the password is valid or not
			{
				num = i;
				cout << "You have logged in successfully" << endl;
				return(false);
			}
			else
			{
				cout << "You have entered the wrong password" << endl;
				return(true);
			}
		}
		i++;
	}
	while(ptr[i] != NULL);//loops till the next availale pointer in the array points to NULL

	cout << "You have entered the wrong credentials - no such user exists" << endl;
	return(true);
}
//=============================================================================================
//This function prints out all the classes that are available 
int viewClassesWithVacancies(FitnessClass* ptr[])
{
	int error =-1;//declaring a variable to keep track of the possible error messages
	int i = 0;
	while(ptr[i] != NULL)//iterates over the whole array of pointers till the next availale pointer in the array points to NULL
	{
		if(ptr[i]->vacancyCheck() == true)//calls the function vacancyCheck to confirm whether the class is vacant or not
		{
			ptr[i]->print();//prints the information of the vacant class
			error=0;
		}	
		i++;
	}
	if(error == -1){cout <<"No classes are vacant\n";}//for error message
	return 0;		
}
//=============================================================================================
//this function quites the programs entirely and saves all the information of the admins, members and the classess into their respective folders 
void quitProgram(FitnessClass* Fitptr[], MemberClass* Memptr[], AdminClass* Adptr[])
{
	ofstream foutFit("FitnessClassesTable.txt", ios::out);//declaring a ofstream file foutFit
    if(foutFit)
    {
    	int i = 0;
    	while(Fitptr[i] != NULL)
    	{
    		foutFit << Fitptr[i]->getClassID()<<", "<<Fitptr[i]->getClassName()<<", "<<Fitptr[i]->getClassDate()<<", "
    		<<Fitptr[i]->getClassTime()<<":00, "<<Fitptr[i]->getMaximumCapacity()<<", "<<Fitptr[i]->getRoomNumber()<<endl;
    		i++;
    	}
    	foutFit.close();
    }
    else
    {
       perror("Error::");//for printing error
	   exit(-1);
	}
	ofstream foutMem("MembersTable.txt", ios::out);//declaring a ofstream file foutMem
    if(foutMem)
    {
    	int i = 0;
    	while(Memptr[i] != NULL)
    	{
    		foutMem << Memptr[i]->getMemberID()<<", "<<Memptr[i]->getFirstName()<<", "<<Memptr[i]->getLastName()
    		<<", "<<Memptr[i]->getUsername()<<", "<<Memptr[i]->getPassword()<<endl;
    		i++;
    	}
    	foutMem.close();
    }
    else
    {
       perror("Error::");//for printing error
	   exit(-1);
	}
	ofstream foutAd("AdminsTable.txt", ios::out);//declaring a ofstream file foutAd
    if(foutAd)
    {
    	int i = 0;
    	while(Adptr[i] != NULL)
    	{
    		foutAd << Adptr[i]->getAdminID()<<", "<<Adptr[i]->getFirstName()<<", "<<Adptr[i]->getLastName()
    		<<", "<<Adptr[i]->getUsername()<<", "<<Adptr[i]->getPassword()<<endl;
    		i++; 
    	}
    	foutAd.close();
    }
    else
    {
       perror("Error::");//for printing error
	   exit(-1);
	}
	cout <<"All data entered have been saved in respective files\n";
	cout <<"Thank you for using the system!\n";
	exit(-1);
}
//=============================================================================================
