/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 14 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Movie.h"

using namespace std;

namespace sdds {

    Movie::Movie() {
        m_year = 0;
    }

    Movie::Movie(const std::string& strMovie) {
        m_year = 0;
        std::string temp = strMovie;    // to store the temp string
        std::string temp2;   // to store the temp string
        string::size_type index;    // to store the position of the comma

        index = temp.find(',');
        if (index != string::npos) {
            m_title = temp.substr(0, index);
            while (m_title[0] == ' ') m_title.erase(0, 1);
            while (m_title[m_title.length() - 1] == ' ') m_title.erase(m_title.length() - 1, 1);
            temp2 = temp.erase(0, index + 1);
            
            index = temp.find(',');
            if (index != string::npos) {
                temp = temp2.substr(0, index); 
                while (temp[0] == ' ') temp.erase(0, 1);
                while (temp[temp.length() - 1] == ' ') temp.erase(temp.length() - 1, 1);
                m_year = stoi(temp);

                m_desc = temp2.erase(0, index + 1);
                while (m_desc[0] == ' ') m_desc.erase(0, 1);
            }
        }
    }

    const std::string& Movie::title() const {
        return m_title;
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os.width(40);
        os.fill(' ');
        os << movie.m_title << " | ";
        os.width(4);
        os << movie.m_year << " | ";
        os << movie.m_desc << endl;
        return os;
    }

}