/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 11 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>
#include <iostream>

namespace sdds {

    class Station {
        size_t m_id;
        std::string m_name;        
        std::string m_desc;
        size_t m_srlNumber;
        size_t m_cnt;
        static size_t m_widthField;
        static size_t m_id_generator;
        public:
            Station(const std::string str);
            const std::string& getItemName() const;
            size_t getNextSerialNumber();
            size_t getQuantity() const;
            void updateQuantity();
            void display(std::ostream& os, bool full) const;
            std::string getStationName() const;
    };

}

#endif // !SDDS_STATION_H
