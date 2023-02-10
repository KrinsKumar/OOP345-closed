/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 08 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TOYS_h
#define SDDS_TOYS_h

#include <string>
#include <iostream>

namespace sdds {

    class Toy {
        private:
            size_t m_orderId;
            std::string m_name;
            size_t m_count;
            double m_price;
            double m_tax;
        public:
            Toy();
            void update(int numItems);
            Toy(const std::string& toy);
            friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
    };

}

#endif // ! SDDS_TOYS_h

