#include <fstream>
#include "SpellChecker.h"
using namespace std;

namespace sdds {

    SpeelChecker::SpeelChecker(const char* filename) {
        ifstream ifs(filename);
        if (ifs.is_open() == true) {
            std::string temp;    // to store the temp string
            string::size_type index;    // to store the position of the space
            size_t count = 0;

            while (getline(ifs, temp)) {
                index = temp.find(' ');
                m_badWords[count] = temp.substr(0, index);
                m_goodWords[count] = temp.substr(index, temp.length());
                ++count;
            }
        }
        else {
            const char* message{"Bad file name!"};
            throw(message);
        }

    }

    void SpeelChecker::operator()(std::string& text) {
        for (auto i = 0; i < 6; ++i) {
            while (text.find(m_badWords[i]) != string::npos) {
                text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
                ++m_count[i];
            }
        }
    }

    void SpeelChecker::showStatistics(std::ostream os) const {
        for (auto i = 0; i < 6; ++i) {
            os.width(15);
            os.fill(' ');
            os.setf(ios::right);
            os << m_badWords[i] << ": " << m_count[i] << "replacements" << endl;
            os.unsetf(ios::right);
        }
    }

}