/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 08 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <utility>
#include "ConfirmOrder.h"

using namespace std;

namespace sdds {

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& order) {
        *this = order;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& order) noexcept {
        *this = move(order);
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& order) {
        if (this != &order) {
            m_count = order.m_count;
            delete[] m_toys;
            m_toys = new const Toy*[m_count + 1];
            for (auto i = 0u; i < m_count; ++i) {
                m_toys[i] = order.m_toys[i];
            }
        }
        
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& order) noexcept {
        if (this != &order) {
            m_count = order.m_count;
            delete[] m_toys;
            m_toys = order.m_toys;
            order.m_toys = nullptr;
            order.m_count = 0;
        }
       
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        bool flag = true;
        for (auto i = 0u; i < m_count && flag; ++i) {
            if (m_toys[i] == &toy) flag = false;
        }
        if (flag == true) {
            const Toy** temp = m_toys;
            m_toys = new const Toy*[m_count + 1];
            for (auto i = 0u; i < m_count; ++i) {
                m_toys[i] = temp[i];
            }
            m_toys[m_count] = &toy;
            ++m_count;
            delete[] temp;
        }

        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        bool flag = true;
        auto i = 0u;
        for (i = 0; i < (m_count + 1) && flag; ++i) {
            if (m_toys[i] == &toy) {
                flag = false;
                m_toys[i] = nullptr;
                --m_count;
            }
        }
        /*
        if (flag == false) {
            for (auto j = i; i < m_count; i++)
        }*/

        return *this;
    }

    ConfirmOrder::~ConfirmOrder() {
        delete[] m_toys;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmOrder order) {
        os << "--------------------------" << endl;
        os << "Confirmations to Send" << endl;
        os << "--------------------------" << endl;

        if (order.m_count == 0) {
            os << "There are no confirmations to send!" << endl;
        }
        else {
            for (auto i = 0u; i < order.m_count; ++i) {
                os <<  *order.m_toys[i];
            }
        }

        os << "--------------------------" << endl;

        return os;
    }

}