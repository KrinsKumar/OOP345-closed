/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 14 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SpellChecker_H
#define SDDS_SpellChecker_H

#include <string>
#include <iostream>

namespace sdds {

    class SpellChecker {
        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        size_t m_count[6]{};
        public:
            SpellChecker(const char* filename);
            void operator()(std::string& text);
            void showStatistics(std::ostream& os) const;
    };

}

#endif // !SDDS_SpellChecker_H
