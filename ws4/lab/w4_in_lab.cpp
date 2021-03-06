//name:HUNG-CHE,CHEN
//seneca email: hchen224@mysenecac.ca
//Student No.:115472169
// TODO: add your headers here
#include "passenger.h"
#include <iostream>
#include <cstring>
// TODO: add the namespaces that you will be using here

using namespace std;
// TODO: holiday namespace here
namespace holiday {
    // TODO: add the default constructor here

    Passenger::Passenger() {
        strcpy(m_name,"\0");
        strcpy(m_destination,"\0");
        m_departureYear = 0, m_departureMonth = 0, m_departureDay = 0;
    }
    // TODO: add the constructor with 2 parameters here

    Passenger::Passenger(const char name[],const char destination[]) {
        
        if((name != nullptr&&strlen(name)!=0)&&(destination!=nullptr&&strlen(destination)!=0)){
           
        strcpy(m_name,name);
        strcpy(m_destination,destination);
        m_departureYear = 2017;
        m_departureMonth = 7;
        m_departureDay = 1;
        
        }else{
        strcpy(m_name,"\0");
        strcpy(m_destination,"\0");}
    }

    // TODO: add the canTravelWith(...) function here

    bool Passenger::canTravelWith(const Passenger& traveler) const {
        return traveler.m_destination==m_destination&&
                traveler.m_departureYear==m_departureYear&&
                traveler.m_departureMonth==m_departureMonth&&
                traveler.m_departureDay==m_departureDay;
        
    }
    // TODO: add the isEmpty() function here

    bool Passenger::isEmpty() const {
        
            return (strlen(m_name)==0 );
        
        
    }
    // below is the member function already provided
    // TODO: read it and understand how it accomplishes its task

    void Passenger::display(bool nameOnly) const {
        if (false == this->isEmpty()) {
            cout << this->m_name;
            if (false == nameOnly) {
                cout << " will travel to " << this->m_destination << ". "
                        << "The journey will start on "
                        << this->m_departureYear << "-"
                        << this->m_departureMonth << "-"
                        << this->m_departureDay
                        << "." << endl;
            }
        } else {
            cout << "Invalid passenger!" << endl;
        }
    }

};
