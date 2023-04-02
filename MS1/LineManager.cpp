/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 1 April, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
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

            for_each(station.begin(), station.end(), [&](Workstation* thisStation) {
                if (thisStation->getStationName() == stationName) {
                    if (more == true) {
                        stationName = ut.extractToken(line, pos, more);
                        for_each(station.begin(), station.end(), [&](Workstation* thatStation) {
                            if (thatStation->getStationName() == stationName) {
                                thisStation->setNextStation(thatStation);
                                m_activeLine.push_back(thisStation);
                                stationName = "";
                            }
                        });
                    }
                    else {
                        m_activeLine.push_back(thisStation);
                    }
                }
            });
        }
        m_cntCustomerOrder = g_pending.size();

        //to find the first station
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* thisStation) {
            bool isStationUsed = true;
            for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* thatStation) {
                if (thisStation != thatStation) {
                    auto tempStation = thatStation->getNextStation();
                    if (tempStation != nullptr)
                        if (thisStation->getStationName() == tempStation->getStationName()) {
                            isStationUsed = false;
                        }
                }
            });
            if (isStationUsed) {
                m_firstStation = const_cast<Workstation*>(thisStation);
            }
        });
    }

    void LineManager::reorderStations() {
        string thisStation = "";
        string newStation = m_firstStation->getStationName();
        vector<Workstation*> correctOrder;

        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* temp) {
            thisStation = newStation;
            for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* thatStation) {
                if (thatStation->getStationName() == thisStation) {
                    correctOrder.push_back(const_cast<Workstation*>(thatStation));
                    auto nextStation = thatStation->getNextStation();
                    if (nextStation != nullptr) 
                        newStation = thatStation->getNextStation()->getStationName();
                }
            });
        });

        m_activeLine = correctOrder;
    }

    bool LineManager::run(std::ostream& os) {
        static size_t f_count = 1;
        static size_t totalSize = g_pending.size();
        os << "Line Manager Iteration: " << f_count << endl;

        if (g_pending.size() > 0) {
            *(m_activeLine[0]) += move(g_pending[0]);
            g_pending.pop_front();
        }
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
            station->fill(os);
        });
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
            station->attempToMoveOrder();
        });
        // first loop for if the servi;ce is required, if the serivice is required then fill on of the order
        // the second loop takes an order to another department if there is no work to be done in that station

        //pop from the front of pending and push it to the bed that is the first of the line 
        //using the += operator 
        //next we go over the stations and filll if the item is in the order. If all the orders were fullfiled 
        //second iteration moves the order if service is required

        ++f_count;
        if (g_completed.size() + g_incomplete.size() == totalSize) {
            return true;
        }
        return false;
    }

    void LineManager::display(std::ostream& os) const {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station) {
            station->display(os);
        });
    }


}
