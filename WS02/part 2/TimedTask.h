#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H

#include <chrono>
#include <string>

namespace sdds {

    struct Task {
        std::string s_taskName;
        std::string s_time_units;
        std::chrono::steady_clock::duration s_durationTime;
    };

    class TimedTask {
        private:
            size_t m_cntValue = 0;
            std::chrono::steady_clock::time_point m_startTime;
            std::chrono::steady_clock::time_point m_endTime;
            Task m_taskArray[10]{};
        public:
            TimedTask();
            void startClock();
            void stopClock();
            void addTask(const char* taskName);
            friend std::ostream& operator<<(std::ostream& cout, const TimedTask right_Timedtask);
   };
    
}

#endif // !define SDDS_TIMEDTASK_H

