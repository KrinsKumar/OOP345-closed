/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 24 January, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H

#include <string>

namespace sdds {

    class ProteinDatabase {
        private:
            std::string* m_str{};
            size_t m_cnt_str;
        public:
            ProteinDatabase();
            ProteinDatabase(const std::string file_name);
            ProteinDatabase(const ProteinDatabase& right_protein);
            ProteinDatabase(ProteinDatabase&& right_protein) noexcept;
            ProteinDatabase& operator=(const ProteinDatabase& right_protein);
            ProteinDatabase& operator=(ProteinDatabase&& right_protein) noexcept;
            size_t size() const;
            std::string operator[](size_t index) const;
            ~ProteinDatabase();
    };

}

#endif // !define SDDS_PROTEINDATABASE_H1
