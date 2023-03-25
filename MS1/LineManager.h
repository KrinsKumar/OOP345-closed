#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include <string>
#include "Workstation.h"

namespace sdds {

    class LineManager {
        private:
            std::vector<Workstation*> m_activeLine;
            size_t m_cntCustomerOrder;
            Workstation* m_firstStation{};
        public:
            LineManager(const std::string& file, const std::vector<Workstation*>& station);
            void reorderStations();
            bool run(std::ostream& os);
            void display(std::ostream& os) const;
    };

}

#endif // !SDDS_LINEMANAGER_H

