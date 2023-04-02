/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 1 April, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include "Workstation.h"

namespace sdds {

    class LineManager {
        private:
            std::vector<sdds::Workstation*> m_activeLine;
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

