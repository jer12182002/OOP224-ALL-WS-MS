#include "Contact.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace communication {
    int count = 0;

    Contact::Contact() {
        strcpy(m_name, "\0");
        m_phoneNumbers = nullptr;
        m_noOfPhoneNumbers = 0;

    }

    Contact::Contact(const char name[], const long long arr[], int size) {
        // cout << "~~~~~Constructor~~~~~" << endl;
        if (name != nullptr && strlen(name) != 0) {
            int loop = 0;
            for (int i = 0; i < 20; i++) {
                m_name[i] = name[i];
            }
            m_name[20] = '\0';
            if (size != 0) {
                m_phoneNumbers = new long long [size];

                for (int i = 0; i < size; i++) {
                    if (arr[i] >= 10000000000) {
                        if (arr[i] <= 99999999999) {
                            m_phoneNumbers[loop] = arr[i];
                            loop++;
                        } else if (arr[i] <= 999999999999) {
                            m_phoneNumbers[loop] = arr[i];
                            loop++;
                        }
                    }
                }
            }
            this->m_noOfPhoneNumbers = loop;


        } else {
            strcpy(m_name, "\0");
            m_phoneNumbers = nullptr;
            m_noOfPhoneNumbers = 0;
        }

        //  cout << "~~~~end constructor~~~~" << endl << endl;
    }

    Contact::~Contact() {
        delete [] m_phoneNumbers;
        m_phoneNumbers = nullptr;

    }

    void Contact::display() const {

        cout << m_noOfPhoneNumbers << endl;

        if (Contact::isEmpty()) {
            cout << "Empty contact!" << endl; //true
        } else {

            cout << m_name << endl;

            for (int i = 0; i < m_noOfPhoneNumbers; i++) {
                if (m_phoneNumbers[i] / 10000000000 != 0 || m_phoneNumbers[i] / 10000000000 != 00) {
                    cout << "(+" << m_phoneNumbers[i] / 10000000000 << ") ";
                }
                if ((m_phoneNumbers[i] % 10000000000) / 10000000 != 0) {
                    cout << (m_phoneNumbers[i] % 10000000000) / 10000000 << " ";
                }
                cout << ((m_phoneNumbers[i] % 10000000000) % 10000000) / 10000 << "-";
                cout << ((m_phoneNumbers[i] % 10000000000) % 10000000) % 10000 << endl;
            }

        }



    }

    bool Contact::isEmpty() const {

        return (m_name[0] == '\0');

    }

   /* Contact::Contact(const Contact& other) {
        //delete [] m_phoneNumbers;
        cout << "~~~~~!!!!~~~~" << endl;
        strcpy(m_name, other.m_name);
        m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;

        if (other.m_phoneNumbers != nullptr) {
            cout << "~~~new long long~~~" << endl;
            m_phoneNumbers = new long long [other.m_noOfPhoneNumbers];
            cout << "~~~copy phoneNumber~~~" << endl;
            for (int i = 0; i < m_noOfPhoneNumbers; i++) {
                cout << "~~~copy in for loop~~~";
                m_phoneNumbers[i] = other.m_phoneNumbers[i];
            }
        } else {
            m_phoneNumbers = nullptr;
            //*this=Contact::Contact();
        }
    }

    Contact& Contact::operator=(const Contact& other) {
        if (this != &other) {
            strcpy(m_name, other.m_name);
            m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
            delete[]m_phoneNumbers;
            if (other.m_phoneNumbers != nullptr) {
                m_phoneNumbers = new long long [m_noOfPhoneNumbers];
                for (int i = 0; i < m_noOfPhoneNumbers; i++) {
                    m_phoneNumbers[i] = other.m_phoneNumbers[i];
                }
            } else {
                m_phoneNumbers = nullptr;
            }
        }
        return*this;
    }

*/
    Contact::Contact(const Contact& other){
                strcpy(m_name, other.m_name);
		m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;

		if (other.m_phoneNumbers != nullptr){
			m_phoneNumbers = new long long[other.m_noOfPhoneNumbers];		
			for (int i = 0; i < m_noOfPhoneNumbers; i++){
				m_phoneNumbers[i] = other.m_phoneNumbers[i]; 
			}
		}
		else{
			m_phoneNumbers = nullptr;
		}
	}
	Contact& Contact::operator=(const Contact& other) {
		if (this != &other){
                         strcpy(m_name, other.m_name);
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;		
			
			if (other.m_phoneNumbers != nullptr){
				m_phoneNumbers = new long long[other.m_noOfPhoneNumbers];	
				for (int i = 0; i < m_noOfPhoneNumbers; i++)
					m_phoneNumbers[i] = other.m_phoneNumbers[i];
			}
			else
			{
				m_phoneNumbers = nullptr;
			}
		}
		return *this;
	}

	// Add phone number.
	void Contact::addPhoneNumber(long long phoneNumber)
	{
		if (m_phoneNumbers == nullptr)
		{
			m_phoneNumbers = new long long[4];
		}
		if (10000000000 <= phoneNumber && phoneNumber <= 999999999999)
		{
			m_phoneNumbers[count] = phoneNumber;
			count++;
			m_noOfPhoneNumbers=count;
		}

	}
	
}