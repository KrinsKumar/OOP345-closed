#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds {

    class Station {
        size_t m_id;
        std::string m_name;        
        std::string m_desc;
        size_t m_srlNumber;
        size_t m_cnt;
        public:
            static size_t m_widthField;
            static size_t m_id_generator;
            Station(const std::string str);
            const std::string& getItemName() const;
            size_t getNextSerialNumber();
            size_t getQuantity();
            void updateQuantity();
            void display(std::ostream& os, bool full) const;
    };

}

#endif // !SDDS_STATION_H
