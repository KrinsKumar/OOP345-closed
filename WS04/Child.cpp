/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 08 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <utility>
#include "Child.h"
using namespace std;

namespace sdds {

    Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
        m_name = name;
        m_age = age;
        m_count = count;
        m_toys = new const Toy * [m_count + 1];
        for (auto i = 0u; i < m_count; ++i) {
            m_toys[i] = new Toy(*toys[i]);
        }
    }

    Child::Child(const Child& newChild) {
        m_toys = nullptr;
        *this = newChild;
    }

    Child::Child(Child&& newChild) noexcept {
        m_toys = nullptr;
        *this = move(newChild);
    }

    Child& Child::operator=(const Child& newChild) {

        if (this != &newChild) {
            if (m_toys != nullptr) {
                for (auto i = 0u; i < m_count; ++i) {
                    delete m_toys[i];
                }
                delete[] m_toys;
            }
            m_name = newChild.m_name;
            m_age = newChild.m_age;
            m_count = newChild.m_count;
            m_toys = new const Toy * [m_count + 1];
            for (auto i = 0u; i < newChild.m_count; ++i) {
                m_toys[i] = new Toy(*newChild.m_toys[i]);
            }
        }

        return *this;
    }

    Child& Child::operator=(Child&& newChild) noexcept {

        if (this != &newChild) {

            if (m_toys != nullptr) {
                for (auto i = 0u; i < m_count; ++i) {
                    delete m_toys[i];
                }
                delete[] m_toys;
            }
            m_name = newChild.m_name;
            m_age = newChild.m_age;
            m_count = newChild.m_count;
            m_toys = newChild.m_toys;
            newChild.m_toys = nullptr;
            newChild.m_count = 0;
            newChild.m_age = 0;
            newChild.m_name = "";
        }

        return *this;
    }

    size_t Child::size() const {
        return m_count;
    }

    Child::~Child() {
        for (auto i = 0u; i < m_count; ++i) {
            delete m_toys[i];
        }
        delete[] m_toys;
    }

    std::ostream& operator<<(std::ostream& os, const Child printChild) {
        static int count = 1;
        os << "--------------------------" << endl;
        os << "Child " << count << ": " << printChild.m_name << " " << printChild.m_age << " years old:" << endl;
        os << "--------------------------" << endl;

        if (printChild.size() == 0) {
            os << "This child has no toys!" << endl;
        }
        else {
            for (auto i = 0u; i < printChild.size(); ++i) {
                os << *printChild.m_toys[i];
            }
        }

        os << "--------------------------" << endl;

        ++count;
        return os;
    }

}