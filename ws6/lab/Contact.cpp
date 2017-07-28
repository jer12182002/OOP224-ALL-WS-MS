#include "Contact.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace communication {

    Contact::Contact() {
        strcpy(m_name, "\0");
        m_phoneNumbers = nullptr;
        m_noOfPhoneNumbers = 0;

    }

    Contact::Contact(const char name[], const long long arr[], int size) {
        if (name != nullptr && strlen(name) != 0) {
            int loop = 0;
          
            for (int i=0;i<20;i++){
                m_name[i]=name[i];
            }m_name[21]='\0';
	   
            
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
            m_noOfPhoneNumbers = loop;

        } else {
            strcpy(m_name, "\0");
            m_phoneNumbers = nullptr;
            m_noOfPhoneNumbers = 0;
        }
    }
    Contact::~Contact(){
        delete [] m_phoneNumbers;
        m_phoneNumbers=nullptr;
        
    }
    void Contact::display() const {
        if (Contact::isEmpty()) {
            cout << "Empty contact!" << endl; //true
        } else {
            
            cout << m_name << endl;
            for (int i = 0; i < m_noOfPhoneNumbers; i++) {
                if(m_phoneNumbers[i]/10000000000!=0||m_phoneNumbers[i]/10000000000!=00){
                cout<<"(+"<<m_phoneNumbers[i]/10000000000<<") ";
                }
                if((m_phoneNumbers[i]%10000000000)/10000000!=0){
                cout<<(m_phoneNumbers[i]%10000000000)/10000000<<" ";
                }
                cout<<((m_phoneNumbers[i]%10000000000)%10000000)/10000<<"-";
                cout<<((m_phoneNumbers[i]%10000000000)%10000000)%10000<<endl;
            }

        }
    }

    bool Contact::isEmpty() const {
        return (m_name[0] == '\0');

    }

}
