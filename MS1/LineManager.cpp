#include <fstream>
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
            tempName = "";
            getline(filee, tempName, '\n');
            if (tempName != "") {
                Workstation nextStation(tempName);
                tempStation.setNextStation(&nextStation);
                m_activeLine.push_back(&tempStation);
            }
            else {
                // final station
                m_activeLine.push_back(&tempStation);
            }
        }
        m_cntCustomerOrder = g_pending.size();



        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
            if (!any_of(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* cmpStation) {
                return station->getStationName() == cmpStation->getStationName();
            })) {
                m_firstStation = const_cast<Workstation*>(station);
            }
        });

    }

    void LineManager::reorderStations() {
        Workstation* thisStation = m_firstStation;
        vector<string> newOrder;
        newOrder.push_back(thisStation->getStationName());
        vector<Workstation*> correctOrder;


        for (auto i = 0u; i < m_cntCustomerOrder; ++i) {
            for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
                if (station->getStationName() == thisStation->getStationName()) {
                    thisStation = station->getNextStation();
                    correctOrder.push_back(const_cast<Workstation*>(station));
                }
            });
        }

        m_activeLine = correctOrder;
    }

    bool LineManager::run(std::ostream& os) {
        static size_t f_count = 1;
        os << "Line Manager Iteration: " << f_count << endl;

        //g_pending[0];

        ++f_count;
        return false;
    }

    void LineManager::display(std::ostream& os) const {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
            os << station;
        });
    }


}