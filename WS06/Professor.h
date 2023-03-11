/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

#include <string>
#include "Employee.h"

namespace sdds {

    class Professor : public Employee {
        private:
            std::string m_department;
        public:
            Professor() = default;
            Professor(std::istream& in);
            void display(std::ostream& out) const;
            std::string status() const;
            std::string department() const;
    };

}

#endif // !SDDS_PROFESSOR_H
