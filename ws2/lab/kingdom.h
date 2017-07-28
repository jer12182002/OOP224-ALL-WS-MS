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


// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H
#include <iostream>

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
	
}
#endif // !KINGDOM_H