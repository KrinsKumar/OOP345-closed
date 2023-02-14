/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 14 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOKS_H
#define SDDS_BOOKS_H

#include <iostream>
#include <string>

// TODO reflect justification of the types used in the member
// custom members added
// member tpyes used in the movie class for the members

namespace sdds {

    class Book {
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year;
        double m_price;
        std::string m_desc{};
        public:
            Book();
            Book(const std::string& strBook);
            const std::string& title() const;
            const std::string& country() const;
            const size_t& year() const;
            double& price();
            void updatePrice(double newPrice);
            friend std::ostream& operator<<(std::ostream& os, const Book& book);

            template <typename T>
            void fixSpelling(T& spellChecker) {
               spellChecker(m_desc);
            }
    };

}

#endif // !SDDS_BOOKS_H
