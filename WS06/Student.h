/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

#include <string>
#include <vector>
#include "Person.h"

namespace sdds {

    class Student : public Person {
        private:
            std::string m_name;
            size_t m_age;
            std::string m_id;
            std::string *m_courses;
            size_t m_count;
        public:
            Student() = default;
            Student(std::istream& is);
            std::string status() const;
            std::string name() const;
            std::string id() const;
            std::string age() const;
            void display(std::ostream& os) const;
            Student* newStu() const;
            ~Student();
    };

}

#endif // !SDDS_STUDENT_H
