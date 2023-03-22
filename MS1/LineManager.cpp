#include <fstream>z
#include <algorithm>
#include "LineManager.h"

using namespace std;

namespace sdds {

    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& station) {
        ifstream filee(file);
        while (filee) {
            string tempName;
            getline(filee, tempName, '|');
            Workstation tempStation(tempName);
            getline(filee, tempName, '\n');
            Workstation nextStation(tempName);
            tempStation.setNextStation(&nextStation);
            m_activeLine.push_back(&tempStation);
        }
        m_cntCustomerOrder = g_pending.size();



        for_each(m_activeLine.begin(), m_activeLine.end(), [](const Workstation& station) {
            if (any_of(m_activeLine.begin(), m_activeLine.end(), [](const Workstation& cmpStation) {

                 })
        });

    }


}