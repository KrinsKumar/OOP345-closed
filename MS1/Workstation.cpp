/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 1 April, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <utility>
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

        if (m_orders.size() > 0) {
            if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
                if (m_pNextStation == nullptr) {
                    if (m_orders.front().isOrderFilled()) 
                        g_completed.push_back(move(m_orders.front()));
                    else 
                        g_incomplete.push_back(move(m_orders.front()));
                    m_orders.pop_front();
                }
                else {
                    m_pNextStation->m_orders.push_back(move(m_orders.front()));
                    m_orders.pop_front();
                }
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

    void Workstation::display(std::ostream& os) const {
        os << getItemName();
        if (m_pNextStation == nullptr)
            os << " --> " << "End of Line";
        else os << " --> " << m_pNextStation->getItemName();
        os << endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(move(newOrder));
        return *this;
    }
}