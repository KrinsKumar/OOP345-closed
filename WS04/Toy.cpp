#include <utility>
#include <iomanip>
#include "Toy.h"

using namespace std;

namespace sdds {
    Toy::Toy() {
        m_orderId = 0;
        m_count = 0;
        m_price = 0;
        m_tax = 0;
    }

    void Toy::update(int numItems) {
        m_count = numItems;
    }

    Toy::Toy(const std::string& toy) {

        string temp1 = toy;
        size_t index = toy.find(":");    //helps to track the indexes of ":"
        
        string temp2 = toy.substr(0, index + 1);
        while(temp2.find(' ') != string::npos) temp2.erase(temp2.find(' '), 1);
        m_orderId = stoi(temp2);

        temp1.erase(0, index + 1);
        while(temp1[0] == ' ') temp1.erase(temp1.find(' '), 1);
        index = temp1.find(":");
        temp2 = temp1.substr(0, index + 1);
        while (temp2[temp2.find(":") - 1] == ' ') temp2.erase(temp2.find(":") - 1, 1);
        temp2.erase(temp2.length() - 1, 1);
        m_name = temp2;

        temp1.erase(0, index + 1);
        while (temp1[0] == ' ') temp1.erase(temp1.find(' '), 1);
        index = temp1.find(":");
        temp2 = temp1.substr(0, index + 1);
        while (temp2[temp2.find(":") - 1] == ' ') temp2.erase(temp2.find(":") - 1, 1);
        m_count = stoi(temp2);

        temp1.erase(0, index + 1);
        while (temp1[0] == ' ') temp1.erase(temp1.find(' '), 1);
        m_price = stod(temp1);
    }

    std::ostream& operator<<(std::ostream& os, const Toy& toy) {
        
        os << "Toy";
        
        os.width(8);
        os << toy.m_orderId << ":";

        os.width(18);
        os.setf(ios::right);
        os << toy.m_name;
        os.unsetf(ios::right);

        os.width(3);
        os << toy.m_count << " items";

        os.width(8);
        os << toy.m_price << "/item  subtotal:";

        os.width(7);
        os << toy.m_count * toy.m_price << " tax:";

        os.width(6);
        os << fixed;
        os << setprecision(2);
        os << toy.m_count * toy.m_price * 0.13 << " total:";

        os.width(7);
        os << fixed;
        os << setprecision(2);
        os << toy.m_count * toy.m_price * 1.13 << endl;
        return os;
    }
}
