/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Utilities.h"
#include "Station.h"

using namespace std;

namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::m_id_generator = 1;

    Station::Station(const string str) {
        Utilities ut;
        size_t pos = 0u;
        bool more = true;
        try {
            m_name = ut.extractToken(str, pos, more);
            if (more == true) m_srlNumber = stoi(ut.extractToken(str, pos, more));
            if (more == true) m_cnt = stoi(ut.extractToken(str, pos, more));
               
            if (this->m_widthField < ut.getFieldWidth()) this->m_widthField = ut.getFieldWidth();
            
            m_desc = ut.extractToken(str, pos, more);
            m_id = m_id_generator;
            ++m_id_generator;
        }
        catch (const char* err) {
            cout << err;
        }
    }

    const std::string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
        auto returnNumber = m_srlNumber;
        ++m_srlNumber;
        return returnNumber;
    }

    size_t Station::getQuantity() {
        return m_cnt;
    }

    void Station::updateQuantity() {
        --m_cnt;
    }


    void Station::display(std::ostream& os, bool full) const {
        os.fill('0');
        os.width(3);
        os << m_id << " | ";
        os.fill(' ');
        os.setf(ios::left);
        os.width(m_widthField);
        os.unsetf(ios::left);
        os.setf(ios::left);
        os << m_name << "  | " ;
        os.unsetf(ios::left);
        os.width(6);
        os.fill('0');
        os << m_srlNumber << " | ";
        if (full != false) {
            os.fill(' ');
            os.width(4);
            os << m_cnt << " | " << m_desc;
        }
        os << endl;
    }


}