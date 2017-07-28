#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict {


    //////////////////////////////////////////////////////
    //
    // Default Constructor
    // String::String();
    //
    // initialize the string to ""
    //
    // 

    String::String() {
        // initialize the string to ""
        m_pString[0] = '\0';
        //  cout<<"1"<<endl;
    }


    //////////////////////////////////////////////////////
    //
    // String::String(const char* p);
    //
    // Construct a String from a char array
    // You may assume the input string pSource 
    // has a length of < 50, and the internal buffer has enough
    // space to hold it.
    //
    // 

    String::String(const char* pSource) {
        //if (strlen(pSource) < 50) {

        strcpy(m_pString, pSource);
        //}
        //cout<<"2"<<endl;
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const String &s, int capacity);
    //
    // Copy constructor
    //
    // Construct a String from another String
    //
    // 

    String::String(const String& other) {
        strcpy(m_pString, other.m_pString);
        //cout<<"3"<<endl;
    }




    //////////////////////////////////////////////////////
    //
    // String::operator=(const String& other)
    // 
    // Assignment operator
    // copy string "other" to this object
    //   
    //     

    String& String::operator=(const String& other) {
        strcpy(m_pString, other.m_pString);
        // cout<<"4"<<endl;
        return *this;
    }

    //////////////////////////////////////////////////////
    //
    // String::~String
    // 
    // destructor
    // 
    // clean up the internal string buffer  
    // 

    String::~String() {

    }


    //////////////////////////////////////////////////////
    //
    // String::length()
    // 
    // return the length of the string
    // 
    // 

    int String::length() const {
        //	cout<<"5"<<endl;
        return strlen(m_pString);
    }

    //////////////////////////////////////////////////////
    //
    // String::operator const char*() const
    // 
    // convert the String to a char*
    // 
    // 

    String::operator const char *() const {
        //cout<<"6"<<endl;
        return m_pString;
    }

    //////////////////////////////////////////////////////
    //
    // String::empty()
    // 
    // 
    // returns true if the string is empty
    // i.e. either the first char is \0, or 
    // length is 0.

    bool String::empty() const {
        //cout<<"7"<<endl;
        return (String::length() == 0);
    }

    //////////////////////////////////////////////////////
    //
    // String::operator bool()
    // 
    // same as empty(), just wrapped in an operator
    // 
    //         

    String::operator bool() const {
        // cout<<"8"<<endl;
        return (String::length() != 0);
    }


    //////////////////////////////////////////////////////
    //
    // String::operator==(const String& s2) const
    // 
    // returns true if *this == s2.
    // You can use the strcmp function to check if 
    // two strings are equal, or write your own
    // treating the string as a char-array
    //           

    bool String::operator==(const String& s2) const {
        // cout<<"9"<<endl;
        return (strcmp(s2.m_pString, m_pString) == 0);
    }


    //////////////////////////////////////////////////////
    //
    // String::operator+=(const String& s2)
    // 
    // Concatenates s2 to the end of *this
    //
    // implements *this = (*this + s2)
    // return *this
    // 
    //         

    String& String::operator+=(const String& s2) {
        *this = (*this +s2);
        //cout<<"10"<<endl;

        //cout<<"+="<<m_pString;
        //cout<<"p"<<strlen(m_pString);
        return *this;
    }

    //////////////////////////////////////////////////////
    //
    // String::operator+(const String& s2) const
    // 
    // implements the operator (*this + s2)
    // returns the expression
    // DOES NOT MODIFY *this
    // 
    //     

    String String::operator+(const String& s2) const {
         /*int a =strlen(m_pString);
          int b =strlen(s2.m_pString);
          char temp[50];
          for(int i=0;i<a;i++){
              temp[i]=m_pString[i];
          }
          for(int i=a;i<a+b;i++){
              temp[i]=s2.m_pString[i];
          }
         // cout<<"!!!"<<temp;
          return temp;
         */

        char temp[100];
        strcpy(temp, m_pString);
        strcat(temp, s2.m_pString);
        return temp;
  
    }

    //////////////////////////////////////////////////////
    //
    // String::operator+=(char c)
    // 
    // Adds a single char c to the end of the string in *this
    // 
    //        

    String& String::operator+=(char c) {
        //m_pString[strlen(m_pString)+1]=c;
        //strcat(m_pString,&c);
        // cout<<"+=+=+=~~"<<m_pString;
        // cout<<m_pString<<"!";
        // m_pString[strlen(m_pString)+1]=c;
        // m_pString[strlen(m_pString)+2]='\0';
        // strcat(m_pString,  c+'\0');
        //char temp[2];
      	//memset(temp,' ',1 );  //make the array consisting with c, and index 1 is terminator.
	char temp [100];
	temp[0]=c;
	temp[1]='\0';
	strcat(m_pString,temp);
        

        return *this;
    }






    //////////////////////////////////////////////////////
    //
    // operator<<
    // 
    // Print the string to the output stream
    // 
    // clean up the internal string buffer  
    //     

    std::ostream& operator<<(std::ostream& ostream, const String &s) {
        ostream << (const char *) s;
        //ostream << s;
        // cout<<"13"<<endl;
        return ostream;
    }


    //////////////////////////////////////////////////////
    //
    // operator>>
    // 
    // Input a string from an input stream into the String s
    // 
    // Note: the input can be ANY length in character. You will need to 
    // read it one char at a time. 
    // 

    std::istream& operator>>(std::istream& istream, String &s) {
        s = "";
        char tempC = 0;
        do {
            tempC = istream.get();
            if (tempC != '\n') {
                s += tempC;
            } else
                break;
        } while (1);
        return istream;
    }


}
