#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& station) {
        Utilities ut;
        ut.setDelimiter('|');
        ifstream filee(file);
        string line;
        while (filee && getline(filee, line)) {
            bool more = true;
            size_t pos = 0u;
            string stationName = ut.extractToken(line, pos, more);

            for_each(station.begin(), station.end(), [&](const Workstation* ) {
                
            });

        }
        m_cntCustomerOrder = g_pending.size();


        /*
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
            if (!any_of(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* cmpStation) {
                return station->getStationName() == cmpStation->getStationName();
            })) {
                m_firstStation = const_cast<Workstation*>(station);
            }
        });
        */
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

        // first loop for if the service is required, if the serivice is required then fill on of the order
        // the second loop takes an order to another department if there is no work to be done in that station

        //pop from the front of pending and push it to the bed that is the first of the line 
        //using the += operator 
        //next we go over the stations and filll if the item is in the order. If all the orders were fullfiled 
        //second iteration moves the order if service is required

        ++f_count;
        //if the sum of completed of incomplete is the same then the work was done 
        // remove the -1 after the length in the in the extract token function
        return false;
    }

    void LineManager::display(std::ostream& os) const {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
            os << station;
        });
    }


}
