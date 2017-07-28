#include <iostream>
using namespace std;

namespace sict{
	class aaa{
		void print()const{
		cout<<"this is a test";
		}
	public:	
		void callprint()const{
		print();
	}
};
}
int main (void){
class sict::aaa a;

a.callprint();
return 0;
}
