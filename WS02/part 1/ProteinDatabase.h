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
            ProteinDatabase& operator=(const ProteinDatabase& right_protein);
            size_t size();
            std::string operator[](size_t index);
            ~ProteinDatabase();
    };

}

#endif // !define SDDS_PROTEINDATABASE_H1
