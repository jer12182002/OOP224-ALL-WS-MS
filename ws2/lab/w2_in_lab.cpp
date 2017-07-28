// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////

#include <iostream>
#include "kingdom.h"

using namespace std;
using namespace westeros;

int main(void)
{
	int count = 0; // the number of kingdoms in the array
	
	// TODO: declare the kingdoms pointer here (don't forget to initialize it)
	kingdom *pKingdoms = nullptr;
	cout << "==========" << endl
		 << "Input data" << endl
		 << "==========" << endl
		 << "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();

	// TODO: allocate dynamic memory here for the kingdoms pointer
	pKingdoms = new kingdom[count];
	for (int i = 0; i < count; ++i)
	{
		// TODO: add code to accept user input for the kingdoms array
		cout << "Enter the name for kingdom #"<<i+1<<": ";
		cin >> pKingdoms[i].m_name;
		cout << "Enter the number people living in "<<pKingdoms[i].m_name<<": ";
		cin >> pKingdoms[i].m_population;
	}
		cout << "==========" << endl << endl;


	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The first kingdom of Westeros" << endl
		<< "------------------------------" << endl;
       westeros::display(pKingdoms[0]);
	cout << "------------------------------" << endl << endl;

	// TODO: deallocate the dynamic memory here
	delete[]pKingdoms;
	pKingdoms = nullptr;
	return 0;
}
