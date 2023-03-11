/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "College.h"

using namespace std;

namespace sdds {

    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& out) const {

        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #1 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            (*it)->display(out);
            out << endl;
        };
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #2 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            out << "| ";
            out.setf(ios::left);
            out.fill(' ');
            out.width(10);
            out << (*it)->status() << "| ";
            out.width(10);
            out << (*it)->id() << "| ";
            out.width(20);
            out << (*it)->name() << " | ";
            out.width(3);
            out << (*it)->age() << " |";
            out << endl;
            out.unsetf(ios::left);
        };
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    College::~College() {
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            delete (*it);
        }
    }


}