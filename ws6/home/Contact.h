// TODO: add header guard
#ifndef CONTACT_H
#define CONTACT_H
// TODO: add namespace here
namespace communication{
	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
	public:
		// TODO: add the default constructor here
                Contact();
		// TODO: add the constructor with parameters here
                Contact(const char[],const long long[],int);
    		// TODO: add the destructor here
                ~Contact();
		// TODO: add the display function here
                void display()const;
		// TODO: add the isEmpty function here
                bool isEmpty() const;

        
		Contact(const Contact& );
               
		Contact& operator=(const Contact& );
                 void addPhoneNumber(long long);
                 
	};
}
#endif
