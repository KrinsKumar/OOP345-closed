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

            /*for_each(station.begin(), station.end(), [&](Workstation* thisStation) {
                if (thisStation->getStationName() == stationName) {
                    if (more == true) {
                        stationName = ut.extractToken(line, pos, more);
                        for_each(station.begin(), station.end(), [&](Workstation* thatStation) {
                            if (thatStation->getStationName() == stationName) {
                                thisStation->setNextStation(thatStation);
                                m_activeLine.push_back(thisStation);
                            }
                        });
                    }
                    else {
                        m_activeLine.push_back(thisStation);
                    }
                }
            });*/
            for (auto i = 0u; i < station.size(); ++i) {
                if (station[i]->getStationName() == stationName) {
                    if (more == true) {
                        stationName = ut.extractToken(line, pos, more); 
                        for (auto j = 0u; j < station.size(); ++j) {
                            if (station[j]->getStationName() == stationName) {
                                station[i]->setNextStation(station[j]);
                                m_activeLine.push_back(station[i]);
                            }
                        }
                    }
                    else {
                        m_activeLine.push_back(station[i]);
                    }
                }
                }
        }
        m_cntCustomerOrder = g_pending.size();

        //to find the first station
        /*for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* thisStation) {
            bool isStationUsed = true;
            for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* thatStation) {
                if (thisStation != thatStation)
                if (thisStation->getStationName() == thatStation->getNextStation()->getStationName()) {
                    isStationUsed = false;
                }
            });
            if (isStationUsed) {
                m_firstStation = const_cast<Workstation*>(thisStation);
            }
        });*/

        for (auto i = 0u; i < m_activeLine.size(); ++i) {
            bool isStationUsed = true;
            for (auto j = 0u; j < m_activeLine.size(); ++j) {
                
                if (m_activeLine[i] != m_activeLine[j])
                if (m_activeLine[i]->getStationName() == m_activeLine[j]->getNextStation()->getStationName()) {
                    isStationUsed = false;
                }
            }
            
            if (isStationUsed) {
                m_firstStation = const_cast<Workstation*>(m_activeLine[i]);
            }
        }
             
    }

    void LineManager::reorderStations() {
        string thisStation = m_firstStation->getStationName();
        vector<Workstation*> correctOrder;

        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* temp) {
            for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* thatStation) {
                if (thatStation->getStationName() == thisStation) {
                    correctOrder.push_back(const_cast<Workstation*>(thatStation));
                    thisStation = thatStation->getNextStation()->getStationName();
                }
            });
        });
        /*
        for (auto i = 0u; i < m_activeLine.size(); ++i) {
            for (auto j = 0u; j < m_activeLine.size(); ++j) {
                if (thisStation == m_activeLine[j]->getStationName()) {
                    correctOrder.push_back(m_activeLine[j]);
                    thisStation = m_activeLine[j]->getStationName();
                }
            }
        }*/

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
