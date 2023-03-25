#include <iostream>
#include "Workstation.h"
#include "Station.h"

using namespace std;

namespace sdds {

    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string readString) : Station(readString) {
    }

    void Workstation::fill(std::ostream& os) {
        if (m_orders.size() > 0) {
            m_orders.front().fillItem(*this, os);
        }
    }

    bool Workstation::attempToMoveOrder() {
        bool returnBool = false;
        if (getQuantity() == 0 || m_orders.front().isItemFilled(getItemName())) {
            returnBool = true;
            if (m_pNextStation == nullptr) {
                if (m_orders.front().isItemFilled(getItemName())) {
                    g_completed.push_back(m_orders.front());
                    m_orders.pop_front();
                }
                else {
                    g_incomplete.push_back(m_orders.front());
                    m_orders.pop_front();
                }
            }
            else {
                m_pNextStation->m_orders.push_back(m_orders.front());
                m_orders.pop_front();
            }
        }

        return returnBool;
    }

    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) {
        os << getItemName();
        os << " --> " << m_pNextStation->getItemName();
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(newOrder);
        return *this;
    }
}