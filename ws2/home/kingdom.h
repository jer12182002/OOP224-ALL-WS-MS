// OOP244 Workshop 2: home
// File kingdom.ch
// Version 1.0
// Date jan.28.2017
// Author hung-che,chen
// Description
// kingdom.cpp includes cstring to use string 
// function strcmp in forth display function.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H
#include <iostream>
#include <cstring>

namespace westeros {
	class kingdom {
	public:
		char m_name[33];
		int m_population;

	};

	// TODO: westeros namespace

	// TODO: define the class Kingdom in the westeros namespace

	// TODO: add the declaration for the function display(...),
	//         also in the westeros namespace
	void display(kingdom&pkingdom);
	void display (kingdom kingdom[],int count);
        void display (kingdom kingdom[],int count,int minimum);
        void display (kingdom kingdom[],int count,const char nameOfKingdom[]);
}
#endif // !KINGDOM_H
