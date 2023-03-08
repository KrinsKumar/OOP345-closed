#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H

#include <vector>
#include <list>
#include "Person.h"

namespace sdds {

    class College {
        private:
            std::vector<Person*> m_persons{};
        public:
            College(const College& newCollege) = delete;
            College(College&& newCollege) = delete;
            College& operator=(const College& newCollege) = delete;
            College& operator=(College&& newCollege) = delete;

            College() = default;
            College& operator+=(Person* thePerson);
            void display(std::ostream& out) const;
            ~College();

            template <typename T>
            void select(const T& test, std::list<const Person*>& persons) {
                for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
                    if (test(*it)) {
                        persons.insert(persons.end(), * it);
                    }
                }
            }

    };

}

#endif // !SDDS_COLLEGE_H
