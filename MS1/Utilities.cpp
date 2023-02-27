#include <algorithm>
#include "Utilities.h"

using namespace std;

namespace sdds {

    char Utilities::m_delimiter = ',';

    void Utilities::setFileWidth(size_t newWidth) {
            m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        
        if (str[next_pos] == m_delimiter) {
            more = false;
            throw("next_pos is equal to the delimiter");    // If delimiter was found at next_npos
        }

        string returnString = "";
        auto position = str.find(m_delimiter, next_pos);    // To get the position of the next delimiter in the strin

        if (position != string::npos) {
            returnString = str.substr(next_pos, position - next_pos);
            // trims the returnString
            while(returnString[0] == ' ') returnString.erase(0, 1);
            while(returnString[returnString.length() - 1] == ' ') returnString.erase(returnString.length() - 1, 1);

            more = true;

            next_pos = position + 1;
        }
        else {
            if (str.length() > 1) returnString = str.substr(next_pos, str.length() - 1);
            else returnString = str;

            while (returnString[0] == ' ') returnString.erase(0, 1);
            while (returnString[returnString.length() - 1] == ' ') returnString.erase(returnString.length() - 1, 1);
            more = false;
        }
        if(returnString.length() > m_widthField) m_widthField = returnString.length();

        return returnString;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}