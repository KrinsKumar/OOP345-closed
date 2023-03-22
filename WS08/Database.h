#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <string>
#include <memory>
// why unique_ptr is not a good choice for m_pDatabase

namespace sdds {

    enum class Err_Status {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    class Database {
        private:
            static std::shared_ptr<Database> m_pDatabase;
            size_t m_size;
            std::string m_keys[20];
            std::string m_values[20];
            std::string m_file;
            Database(const std::string& filename);
        public:
            //Database() = delete;
            static std::shared_ptr<Database> getInstance(const std::string& filename);
            Err_Status GetValue(const std::string& key, std::string& value);
            Err_Status SetValue(const std::string& key, const std::string& value);
            ~Database();
    };

}

#endif // !SDDS_DATABASE_H
