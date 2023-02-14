#ifndef SDDS_SPEELCHECKER_H
#define SDDS_SPEELCHECKER_H

#include <string>
#include <iostream>

namespace sdds {

    class SpeelChecker {
        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        size_t m_count[6]{};
        public:
            SpeelChecker(const char* filename);
            void operator()(std::string& text);
            void showStatistics(std::ostream os) const;
    };

}

#endif // !SDDS_SPEELCHECKER_H
