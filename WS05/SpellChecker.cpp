/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 14 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <fstream>
#include "SpellChecker.h"
using namespace std;

namespace sdds {

    SpellChecker::SpellChecker(const char* filename) {
        ifstream ifs(filename);
        if (ifs.is_open() == true) {
            std::string temp;    // to store the temp string
            string::size_type index;    // to store the position of the space
            size_t count = 0;

            while (getline(ifs, temp)) {
                index = temp.find(' ');
                m_badWords[count] = temp.substr(0, index);
                temp.erase(0, index + 1);
                while (temp[0] == ' ') temp.erase(0, 1);

                m_goodWords[count] = temp;
                ++count;
            }
        }
        else {
            const char* message{"Bad file name!"};
            throw(message);
        }

    }

    void SpellChecker::operator()(std::string& text) {
        for (auto i = 0u; i < 6; ++i) {
            while (text.find(m_badWords[i]) != string::npos) {
                text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
                ++m_count[i];
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& os) const {
    os << "Spellchecker Statistics" << endl;
        for (auto i = 0u; i < 6; ++i) {
            os.width(15);
            os.fill(' ');
            os.setf(ios::right);
            os << m_badWords[i] << ": " << m_count[i] << " replacements" << endl;
            os.unsetf(ios::right);
        }
    }

}