/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 08 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CHILD_h
#define SDDS_CHILD_h

#include <string>
#include "Toy.h"

namespace sdds {

    class Child {
        private:
            std::string m_name{};
            int m_age;
            const Toy** m_toys;
            size_t m_count;
        public:
            Child() = default;
            Child(std::string name, int age, const Toy* toys[], size_t count);
            Child(const Child& newChild);
            Child(Child&& newChild) noexcept;
            Child& operator=(const Child& newChild);
            Child& operator=(Child&& newChild) noexcept;
            size_t size() const;
            ~Child();
            friend std::ostream& operator<<(std::ostream& os, const Child printChild);
    };

}

#endif // ! SDDS_CHILD_h