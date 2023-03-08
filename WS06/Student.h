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
            std::vector<std::string*> m_courses;
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
