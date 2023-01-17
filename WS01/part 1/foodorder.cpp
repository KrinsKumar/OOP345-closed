#include  <iostream>
#include "foodorder.h"

using namespace std;


double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

namespace sdds {

    FoodOrder::FoodOrder() {
        m_price = 0;
        m_isDailySpecial = false;
    }

    void FoodOrder::read(std::istream& is) {
        if (!is.fail()) {
            is.getline(m_name, ',');
            is.ignore();
            
            is.getline(m_desc, ',');
            is.ignore();

            is >> m_price;
            is.ignore();

            char temp;
            is >> temp;
            if (temp == 'N') {
                m_isDailySpecial = false;
            } else m_isDailySpecial = true;
            is.ignore();
        }
    }
    
    void FoodOrder::display(std::ostream& os) {
        static int counter = 0;
        os.width(2);
        os.fill(' ');
        os.setf(ios::left);
        if (m_price == 0) {
            os << counter <<". No Order";
            os.unsetf(ios::left);
        }
        else {
            os << counter << ". ";
            os.unsetf(ios::left);
        }


        ++counter;
    }

}