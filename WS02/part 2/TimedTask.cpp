#include "TimedTask.h"
#include <iostream>

using namespace std;

namespace sdds {

    TimedTask::TimedTask() {
        
    }

    void TimedTask::startClock() {
        m_startTime = chrono::steady_clock::now();
    }

    void TimedTask::stopClock() {
        m_endTime = chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char* taskName) {
        m_taskArray[m_cntValue].s_taskName = taskName;
        m_taskArray[m_cntValue].s_time_units = "nanoseconds";
        m_taskArray[m_cntValue].s_durationTime =
            chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);
        ++m_cntValue;
    }

    ostream& operator<<(ostream& out, const TimedTask right_Timedtask) {
        out << "--------------------------" << endl;
        out << "Execution Times:" << endl;
        out << "--------------------------" << endl;

        for (auto i = 0u; i < right_Timedtask.m_cntValue; ++i) {
            out.fill(' ');
            out.width(21);
            out.setf(ios::left);
            out << right_Timedtask.m_taskArray[i].s_taskName;
            out.setf(ios::right);
            out.width(13);
            out << right_Timedtask.m_taskArray[i].s_durationTime.count();
            out.unsetf(ios::right);
            out << ' ' << right_Timedtask.m_taskArray[i].s_time_units << endl;
        }

        out << "--------------------------" << endl;
        return out;
    }

}
