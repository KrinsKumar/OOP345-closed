/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include <string>
#include "Person.h"

namespace sdds {

    class Employee : public Person {
        private:
            std::string m_name{};
            size_t m_age = 0;
            std::string m_id{};
        public:
            Employee() = default;
            Employee(std::istream& is);
            std::string status() const;
            std::string name() const;
            std::string id() const;
            std::string age() const;
            Employee& operator=(const Employee& emp);
            void display(std::ostream& out) const;
    };  

}

#endif // !SDDS_EMPLOYEE_H

