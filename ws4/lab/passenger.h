//name:HUNG-CHE,CHEN
//seneca email: hchen224@mysenecac.ca
//Student No.:115472169
//TODO: add header guards here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: holiday namespace here
using namespace std;
namespace holiday {
    // TODO: declare the class Passenger here

    class Passenger {
        // TODO: add the class the attributes,
        char m_name[32];
        char m_destination[32];
        int m_departureYear, m_departureMonth, m_departureDay;
    public:
        Passenger();
        Passenger(const char[] ,const char[] );
        
        //       the member function already provided,
        void display(bool=false) const;
        //       and the member functions that you must implement
        bool isEmpty() const;
        bool canTravelWith(const Passenger&) const;
    };
}
#endif
