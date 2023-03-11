/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Professor.h"

using namespace std;

namespace sdds {

    Professor::Professor(std::istream& in) : Employee(in) {
        getline(in, m_department, '\n');
        while (m_department[0] == ' ') m_department.erase(0, 1);
        while (m_department[m_department.length() - 1] == ' ') m_department.erase(m_department.length() - 1, 1);
    }

    void Professor::display(std::ostream& out) const {
        Employee::display(out);
        out << m_department << "| Professor";
    }

    std::string Professor::status() const {
        return "Professor";
    }

    std::string Professor::department() const {
        return m_department;
    }

}