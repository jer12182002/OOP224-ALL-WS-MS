// OOP244 Workshop 2: home
// File kingdom.cpp
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


// TODO: include the necessary headers
#include "kingdom.h"
#include <iostream>
#include <cstring>
// TODO: the westeros namespace

// TODO:definition for display(...) 

using namespace std;
namespace westeros {

    void display(kingdom&pkingdom) {
        cout << pkingdom.m_name << ", population " << pkingdom.m_population << endl;
    }
    void display (kingdom kingdom[],int count){
        int total=0;
        cout<<"------------------------------"<<endl;
        cout<<"Kingdoms of Westeros"<<endl<<"------------------------------"<<endl;
        for (int i=0;i<count;i++){
            cout<<i+1<<". "<<kingdom[i].m_name<<", population "<<kingdom[i].m_population<<endl;
            total+=kingdom[i].m_population;
        }
        cout<<"------------------------------"<<endl;
        cout<<"Total population of Westeros: "<<total<<endl;
        cout<<"------------------------------"<<endl;
        
    }
     void display (kingdom kingdom[],int count,int minimum){
        cout<<"------------------------------"<<endl;
        cout<<"Kingdoms of Westeros with more than "<<minimum<<" people"<<endl;
        cout<<"------------------------------"<<endl;
        for (int i=0;i<count;i++){
            if (kingdom[i].m_population>=minimum){
                cout<<kingdom[i].m_name<<", population "<<kingdom[i].m_population<<endl;
            }
        }
        cout<<"------------------------------"<<endl;
        
    }
      void display (kingdom kingdom[],int count,const char nameOfKingdom[]){
          int flag=0;
          cout<<"------------------------------"<<endl;
          cout<<"Searching for kingdom "<<nameOfKingdom<<" in Westeros"<<endl;
          cout<<"------------------------------"<<endl;
          for (int i=0;i<count;i++){
              if(strcmp(kingdom[i].m_name,nameOfKingdom)==0){
                  cout<<kingdom[i].m_name<<", population "<<kingdom[i].m_population<<endl;
                  flag=1;
              }
              
          }
          if (flag==0){
                  cout<<nameOfKingdom<<" is not part of Westeros."<<endl;
              }
          cout<<"------------------------------"<<endl;
          cout<<endl;
      }
}

