#include "Pair.h"

using namespace std;

namespace sdds {
    Pair::Pair() {
        m_key = "No Key";
        m_value = "No Value";
    }
    
    Pair& sdds::Pair::operator=(const Pair& rightPair) {
        this->m_key = rightPair.m_key;
        this->m_value = rightPair.m_value;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Pair& rightPair) {
        os.width(20);
        os.fill(' ');
        os.setf(ios::right);
        os << rightPair.getKey();
        os.unsetf(ios::right);
        os << ": " << rightPair.getValue();
        return os;
    }

}