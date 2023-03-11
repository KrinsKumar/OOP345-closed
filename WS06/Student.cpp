/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Student.h"

using namespace std;

namespace sdds {

    Student::Student(std::istream& is) {
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
        getline(is, m_id, ',');
        while (m_id[0] == ' ') m_id.erase(0, 1);
        if (m_id[0] != 'S') {
            string message = m_name;
            is.ignore(1000, '\n');
            message.append("++Invalid record!");
            throw(message);
        }
        while (m_id[m_id.length() - 1] == ' ') m_id.erase(m_id.length() - 1, 1);

        //to get the number of courses 
        getline(is, temp, ',');
        try {
            m_count = stoi(temp);
        }
        catch (std::invalid_argument const& ex) {
            string message = m_name;
            message.append("++Invalid record!");
            throw(message);
        }

        //to get the courses
        for (auto i = 0u; i < m_count; ++i) {
            if (i == m_count - 1) getline(is, temp, '\n');
            else getline(is, temp, ',');
        
            while (temp[0] == ' ') temp.erase(0, 1);
            while (temp[temp.length() - 1] == ' ') temp.erase(temp.length() - 1, 1);
            string* dynaString = new string;
            *dynaString = temp;
            m_courses.push_back(dynaString);
        }

    }

    std::string Student::status() const {
        return "Student";
    }

    std::string Student::name() const {
        return m_name;
    }

    std::string Student::id() const {
        return m_id;
    }

    std::string Student::age() const {
        return to_string(m_age);
    }

    Student* Student::newStu() const {
        Student* returnStudent = new Student;
        returnStudent->m_age = m_age;
        returnStudent->m_name = m_name;
        returnStudent->m_id = m_id;
        returnStudent->m_count = m_count;
        for (auto it = m_courses.begin(); it != m_courses.end(); ++it) {
            string* course = new string;
            *course = **it;
            returnStudent->m_courses.push_back(course);
        }
        
        return returnStudent;
    }

    void Student::display(std::ostream& out) const {
        out << "| ";
        out.setf(ios::left);
        out.fill(' ');
        out.width(10);
        out << this->status() << "| ";
        out.width(10);
        out << m_id << "| ";
        out.width(20);
        out << m_name << " | ";
        out.width(3);
        out << m_age << " |";
        out.unsetf(ios::left);
        for (auto i = 0u; i < m_count; ++i) {
           out << *m_courses[i];
           if (i != m_count - 1) out << ", ";
        }
    }
    
    Student::~Student() {
        for (auto it = m_courses.begin(); it != m_courses.end(); ++it) {
           delete *it;
        }
    }

}