#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include"Perishable.h"
#include<iostream>
#include "Date.h"
#include "Item.h"
#include "Error.h"

using namespace std;
namespace ict {

    char Perishable::signature() const {
        return 'P';
    }

    Perishable::Perishable() : NonPerishable() {
        m_expiry.dateOnly(1);
    }

    fstream& Perishable::save(fstream& file)const {
        NonPerishable::save(file);
        file << "," << m_expiry;
        return file;
    }

    fstream& Perishable::load(fstream& file) {
        NonPerishable::load(file);
        //file.ignore();
        file.ignore() >> m_expiry;
        return file;
    }

    std::ostream & Perishable::write(std::ostream & os, bool linear) {
        NonPerishable::write(os, linear);
        if (NonPerishable::ok() == 1 && linear == 0)os << "Expiry date: " << m_expiry << endl;
        return os;
    }

    istream & Perishable::read(istream & istr) {
        cout << "Perishable ";
        NonPerishable::read(istr);
        if (NonPerishable::ok()) {
            cout << "Expiry date (YYYY/MM/DD): ";
            m_expiry.read(istr);
            if (m_expiry.errCode() == CIN_FAILED)error("Invalid Date Entry");
            if (m_expiry.errCode() == YEAR_ERROR)error("Invalid Year in Date Entry");
            if (m_expiry.errCode() == MON_ERROR)error("Invalid Month in Date Entry");
            if (m_expiry.errCode() == DAY_ERROR)error("Invalid Day in Date Entry");
            if (m_expiry.errCode())istr.setstate(ios::failbit);
        }
        return istr;
    }

}




