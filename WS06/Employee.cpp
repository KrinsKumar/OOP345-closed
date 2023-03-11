/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Employee.h"

using namespace std;

namespace sdds {

    Employee::Employee(std::istream& is) {
        string temp;

        //to get the name
        getline(is, m_name, ',');
        while (m_name[0] == ' ') m_name.erase(0, 1);
        while (m_name[m_name.length() - 1] == ' ') m_name.erase(m_name.length() - 1, 1);
        
        //to get the age 
        getline(is, temp, ',');
        try {
            m_age = stoi(temp);
        }
        catch (std::invalid_argument const& ex) {
            string message = m_name;
            is.ignore(1000, '\n');
            message.append("++Invalid record!");
            throw(message);
        }

        //to get the id
        char tempChar;
        temp = "";
        bool flag = true;
        do {
            //is >> tempChar;
            is.get(tempChar);
            if (tempChar == ',') {
                flag = false;
            }
            else if (tempChar == '\n') {
                flag = false;
            }
            else {
                temp += tempChar;
            }
        } while (flag);

        m_id = temp;
        while (m_id[0] == ' ') m_id.erase(0, 1);
        if (m_id[0] != 'E') {
            string message = m_name;
            message.append("++Invalid record!");
            throw(message);
        }
        while (m_id[m_id.length() - 1] == ' ') m_id.erase(m_id.length() - 1, 1);
    }

    std::string Employee::status() const {
        return "Employee";
    }

    std::string Employee::name() const {
        return m_name;
    }

    std::string Employee::id() const {
        return m_id;
    }

    std::string Employee::age() const {
        return to_string(m_age);
    }


    Employee& Employee::operator=(const Employee& emp) {
        m_name = emp.m_name;
        m_age = emp.m_age;
        m_id = emp.m_id;
        return *this;
    }

    void Employee::display(std::ostream& out) const {
        out << "| ";
        out.setf(ios::left);
        out.fill(' ');
        out.width(10);
        out << Employee::status() << "| ";
        out.width(10);
        out << m_id << "| ";
        out.width(20);
        out << m_name << " | ";
        out.width(3);
        out << m_age << " |";
        out.unsetf(ios::left);
    }

}