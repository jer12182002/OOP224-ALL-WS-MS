
#include "Fraction.h"

using namespace std;

namespace sict {

    Fraction::Fraction() {
        denom = -1; // safe empty state
    }

    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    {
        if (n >= 0 && d > 0) {
            num = n;
            denom = d;
            reduce();
        } else
            denom = -1; // set to safe empty state
    }

    int Fraction::gcd() // returns the greatest common divisor of num and denom 
    {
        int mn = min(); // min of num and denom
        int mx = max(); // mX of num and denom

        for (int x = mn; x > 0; x--) // find the greatest common divisor
            if (mx % x == 0 && mn % x == 0)
                return x;
        return 1;

    }

    void Fraction::reduce() // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max() {
        return (num >= denom) ? num : denom;
    }

    int Fraction::min() {
        return (num >= denom) ? denom : num;
    }

    // in_lab

    // TODO: write the implementation of display function HERE

    void Fraction::display(void) const {
        // cout<<Fraction::isEmpty(num,denom);
        if (Fraction::isEmpty(num, denom)) {
            cout << "Invalid Fraction Object!" ;
        } else {
            if ((num % denom) == 0) {
                cout << num / denom;
            }else{
             cout << num  << "/" << denom;
            }
        }

    }

    // TODO: write the implementation of isEmpty function HERE

    bool Fraction::isEmpty(int num, int denom) const {
        return (num == -1 || denom == -1); //retrun true==invalid,  false==valid;
    }

    // TODO: write the implementation of member operator+= function HERE
    Fraction& Fraction::operator+=(Fraction& a){
        num=num*a.denom+denom*a.num;
        denom=denom*a.denom;
       return *this;
    }
    
    // TODO: write the implementation of member operator+ function HERE
    Fraction Fraction::operator+(Fraction& a) const{
       
        return Fraction(num*a.denom+denom*a.num,denom*a.denom);
    }                   
    Fraction Fraction :: operator+(int a)const{
        
        
        return Fraction(a*denom+num,denom);
        
    }
    // TODO: write the implementation of member operator* function HERE
    Fraction Fraction::operator*(Fraction& a)const{
        
        return Fraction(num*a.num,denom*a.denom);
    }
}