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
