#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"

namespace sdds {

    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    //cannot be copied or moved
    class Workstation : public Station {
        private:
            std::deque<CustomerOrder> m_orders;
            Workstation* m_pNextStation{};
        public:
            Workstation(const std::string readString);
            Workstation(const Workstation& copy) = delete;
            Workstation(Workstation&& copy) = delete;
            Workstation& operator=(const Workstation& copy) = delete;
            Workstation& operator=(Workstation&& copy) = delete;

            void fill(std::ostream& os);
            bool attempToMoveOrder();
            void setNextStation(Workstation* station = nullptr);
            Workstation* getNextStation() const;
            void display(std::ostream& os);
            Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif // !SDDS_WORKSTATION_H

