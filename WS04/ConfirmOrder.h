/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 08 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONFIRMORDER_h
#define SDDS_CONFIRMORDER_h

#include "Toy.h"

namespace sdds {

    class ConfirmOrder {
        private:
            const Toy** m_toys{};
            size_t m_count = 0;
        public:
            ConfirmOrder() = default;
            ConfirmOrder(const ConfirmOrder& order);
            ConfirmOrder(ConfirmOrder&& order) noexcept;
            ConfirmOrder& operator=(const ConfirmOrder& order);
            ConfirmOrder& operator=(ConfirmOrder&& order) noexcept;
            ConfirmOrder& operator+=(const Toy& toy);
            ConfirmOrder& operator-=(const Toy& toy);
            ~ConfirmOrder();
            friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder order);
    };

}

#endif // ! SDDS_CONFIRMORDER_h