/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 14 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds {

    class Movie {
        std::string m_title{};
        size_t m_year;
        std::string m_desc{};
        public:
            Movie();
            Movie(const std::string& strMovie);
            const std::string& title() const;
            friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
            
            template <typename T>
            void fixSpelling(T& spellChecker) {
                spellChecker(m_desc);
                spellChecker(m_title);
            }
    };

}

#endif // !SDDS_SpellChecker_H
