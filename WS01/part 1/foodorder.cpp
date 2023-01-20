#include  <iostream>
#include <string>
#include <iomanip>
#include "foodorder.h"

using namespace std;


double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

namespace sdds {

    FoodOrder::FoodOrder() {
        m_price = 0;
        m_isDailySpecial = false;
    }

    FoodOrder::FoodOrder(const FoodOrder& other) {
        *this = other;
    }

    FoodOrder& FoodOrder::operator=(const FoodOrder& other) {
        // shallow copy of static variables
        m_price = other.m_price;
        m_isDailySpecial = other.m_isDailySpecial;

        // deep copy for dynamic variables
        delete[] m_desc;
        auto length = char_traits<char>::length(m_desc);
        m_desc = new char[length];

        for (auto i = 0u; i < length; ++i) {
            m_desc[i] = other.m_desc[i];
        }

        return *this;
    }

    void FoodOrder::read(std::istream& is) {
        if (!is.fail()) {
            is.getline(m_name, 8, ',');

            string temp_desc;
            getline(is, temp_desc, ',');
            const char* temp_cstring = temp_desc.c_str();
            int length = temp_desc.length();

            m_desc = new char[length + 1];
            for (auto i = 0u; i < length; ++i) {
                m_desc[i] = temp_desc[i];
            }

            is >> m_price;
            is.ignore();

            char temp = 'N';
            is >> temp;
            if (temp == 'N') {
                m_isDailySpecial = false;
            }
            else m_isDailySpecial = true;
            is.ignore(1000, '\n');
        }
    }

    void FoodOrder::display(std::ostream& os) {
        static int counter = 1;

        os.width(2);
        os.fill(' ');
        os.setf(ios::left);
        if (m_name[0] == '\0') {
            os << counter << ". No Order";
            os.unsetf(ios::left);
        }
        else {
            os << counter << ". ";

            os.width(10);
            os << m_name << "|";
            os.width(25);
            os << m_desc << "|";
            os.width(12);

            os << std::setprecision(2) << fixed;
            double temp = (m_price + m_price * g_taxrate);
            double temp2 = temp - g_dailydiscount;
            os << temp << "|";
            os.unsetf(ios::left);

            if (m_isDailySpecial == true) {
                os.setf(ios::right);
                os.width(13);
                os << temp2;
                os.unsetf(ios::right);
            }
        }
        os << '\n';
        ++counter;
    }

    FoodOrder::~FoodOrder() {
        delete[] m_desc;
    }

}