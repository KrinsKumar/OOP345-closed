/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 14 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {

    Book::Book() {
        m_year = 0;
        m_price = 0;
    }

    Book::Book(const string& strBook) {
        std::string temp = strBook;    // to store the temp string
        std::string temp2 = strBook;    // to store the temp string
        string::size_type index;    // to store the position of the comma
        m_year = 0;
        m_price = 0;

        index = temp.find(',');
        if (index != string::npos) {
            m_author = temp.substr(0, index);
            temp2 = temp.erase(0, index + 1);

            index = temp2.find(',');
            if (index != string::npos) {
                m_title = temp2.substr(0, index);
                while(m_title[0] == ' ') m_title.erase(0, 1);
                while(m_title[m_title.length() - 1] == ' ') m_title.erase(m_title.length() - 1, 1);
                temp = temp2.erase(0, index + 1);
                
                index = temp.find(',');
                if (index != string::npos) {
                    m_country = temp.substr(0, index);
                    while (m_country[0] == ' ') m_country.erase(0, 1);
                    while (m_country[m_country.length() - 1] == ' ') m_country.erase(m_country.length() - 1, 1);
                }
                temp2 = temp.erase(0, index + 1);

                index = temp2.find(',');
                if (index != string::npos) {
                    temp = temp2.substr(0, index);
                    while (temp[0] == ' ') temp.erase(0, 1);
                    while (temp[temp.length() - 1] == ' ') temp.erase(temp.length() - 1, 1);
                    m_price = stod(temp);

                    temp = temp2.erase(0, index + 1); 
                    index = temp.find(',');
                    if (index != string::npos) {
                        temp2 = temp.substr(0, index);
                        while (temp2[0] == ' ') temp2.erase(0, 1);
                        while (temp2[temp2.length() - 1] == ' ') temp2.erase(temp2.length() - 1, 1);
                        m_year = stoi(temp2);
                    }

                    m_desc = temp.erase(0, index + 1);
                    while (m_desc[0] == ' ') m_desc.erase(0, 1);
                    while (m_desc[m_desc.length() - 1] == ' ') m_desc.erase(m_desc.length() - 1, 1);
                }
            }
        }
    }

    const std::string& Book::title() const {
        return m_title;
    }

    const std::string& Book::country() const {
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        return m_price;
    }

    void Book::updatePrice(double newPrice) {
        m_price = newPrice;
    }

    ostream& operator<<(ostream& os, const Book& book) {
        os.width(20);
        os.fill(' ');
        os << book.m_author << " | ";
        os.width(22);
        os << book.m_title << " | ";
        os.width(5);
        os << book.m_country << " | ";
        os.width(4);
        os << book.m_year << " | ";
        os.width(6);
        os << fixed;
        os << setprecision(2);
        os << book.m_price << " | ";
        os << book.m_desc;

        os << endl;
        return os;
    }

}