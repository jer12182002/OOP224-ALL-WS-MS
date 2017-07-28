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
        strcpy(m_name, "\0");
        strcpy(m_destination, "\0");
        m_departureYear = 0, m_departureMonth = 0, m_departureDay = 0;
    }
    // TODO: add the constructor with 2 parameters here

    Passenger::Passenger(const char name[], const char destination[]) {
        //or Passenger::Passenger (const char *name,const char *destination)
        if ((name != nullptr && strlen(name) != 0)&&(destination != nullptr && strlen(destination) != 0)) {

            strcpy(m_name, name);
            strcpy(m_destination, destination);
            m_departureYear = 2017;
            m_departureMonth = 7;
            m_departureDay = 1;

        } else {
            strcpy(m_name, "\0");
            strcpy(m_destination, "\0");

        }
    }

    Passenger::Passenger(const char *name, const char *destination, int years, int months, int days) {
        // Passenger(name,destination); why can i not use this to check ???
/*        Passenger::Passenger(name, destination);
        if (years <= 2020 && years >= 2017 && months >= 1 && months <= 12 && days >= 1 && days <= 31) {
            m_departureYear = years;
            m_departureMonth = months;
            m_departureDay = days;
        }

        */
        if (years <= 2020 && years >= 2017 && months >= 1 && months <= 12 && days >= 1 && days <= 31 &&
                (name != nullptr && strlen(name) != 0)&&(destination != nullptr &&
                strlen(destination) != 0)) {
            strcpy(m_name, name);
            strcpy(m_destination, destination);
            m_departureYear = years;
            m_departureMonth = months;
            m_departureDay = days;
        } else {
            strcpy(m_name, "\0");
            strcpy(m_destination, "\0");

        }
    }
    // TODO: add the canTravelWith(...) function here

    bool Passenger::canTravelWith(const Passenger& traveler) const {
        return strcmp(traveler.m_destination, m_destination) == 0 &&
                traveler.m_departureYear == m_departureYear &&
                traveler.m_departureMonth == m_departureMonth &&
                traveler.m_departureDay == m_departureDay;

    }

    void Passenger::travelWith(const Passenger* arrPassengers, int size) {
        int flag = 0, mark = 0;
        for (int i = 0; i < size; i++) {
            if (arrPassengers->canTravelWith(arrPassengers[i]) == 1) {
                flag++;
                //can go three people can go flag=3;
            } else {
                mark = i;
            }
        }
        if (flag == 0) {
            cout << "Nobody can join " << m_name << " on vacation!" << endl;
        } else {//flag is more than zero
            if (flag == size) {
                cout << "Everybody can join " << m_name << " on vacation!" << endl;
                cout << m_name << " will be accompanied by ";
                for (int i = 0; i < size - 1; i++) {
                    arrPassengers[i].display(1);
                    cout << ", ";
                }
                arrPassengers[size - 1].display(1);
                cout << "." << endl;
            } else if (mark != 0) {
                cout << m_name << " will be accompanied by ";
                for (int i = 0; i < mark; i++) {
                    arrPassengers[i].display(1);
                    cout << ", ";
                }
                for (int i = mark + 1; i < size - 1; i++) {
                    arrPassengers[i].display(1);
                    cout << ", ";
                }
                arrPassengers[size - 1].display(1);
                cout << "." << endl;
            }

        }



        /*    
            if (size == 0) {
                cout << "Nobody can join " << m_name << " on vacation!" << endl;
        
            } else {
                if(size==7){
                cout << "Everybody can join " << m_name << " on vacation!" << endl;
                }
            
                cout <<m_name<<" will be accompanied by ";
                for (int i = 0; i < size - 1; i++) {
                    if (arrPassengers->canTravelWith(arrPassengers[i])) {
                        arrPassengers[i].display(1);
                        cout << ", ";
                    }
                }
                if (arrPassengers->canTravelWith(arrPassengers[size - 1])) {
                    arrPassengers[size - 1].display(1);
                    cout << "." << endl;
                }

            }*/

    }
    // TODO: add the isEmpty() function here

    bool Passenger::isEmpty() const {
        //should return true to get not valid!!!!
        if (strlen(m_name) == 0 && strlen(m_destination) == 0) {
            return true;
        }
        return (strlen(m_name) == 0 && m_departureYear == 0 && m_departureMonth == 0 && m_departureDay == 0);


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
