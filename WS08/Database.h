#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
// why unique_ptr is not a good choice for m_pDatabase

namespace sdds {

    enum class Err_Status {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database {
        private:
            static std::shared_ptr<Database<T>> m_pDatabase;
            size_t m_size = 0;
            std::string m_keys[20];
            T m_values[20];
            std::string m_file;
            Database(const std::string& filename);
            void encryptDecrypt(T& value);
        public:
            //Database() = delete;
            static std::shared_ptr<Database<T>> getInstance(const std::string& filename);
            Err_Status GetValue(const std::string& key, T& value);
            Err_Status SetValue(const std::string& key, const T& value);
            ~Database();
    };

    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::m_pDatabase = nullptr;


    template <typename T>
    Database<T>::Database(const std::string& filename) {
        std::cout << "[" << this << "] Database(const std::string&)" << std::endl;

        std::ifstream file(filename);

        size_t i;

        for (i = 0; file && i < 20; ++i) {
            std::string temp;

            getline(file, temp, ' ');
            // to replace the _ with ' '
            while (temp.find('_') != std::string::npos) {
                temp.replace(temp.find('_'), 1, " ");
            }
            m_keys[i] = temp;

            T tempValues;
            file >> tempValues;
            encryptDecrypt(tempValues);
            m_values[i] = tempValues;
            file.ignore();
        }

        m_file = filename;
        m_size = i + 1;
    }

    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string& filename) {
        if (m_pDatabase == nullptr) {
            std::shared_ptr<Database<T>> temp(new Database<T>(filename));
            m_pDatabase = temp;
            return temp;
        }
        else return m_pDatabase;
    }

    template <typename T>
    void Database<T>::encryptDecrypt(T& value) {
        
    }

    template <>
    void Database<std::string>::encryptDecrypt(std::string& value) {
        const char secret[]{ "secret encryption key" };

        for (auto i = 0u; i < value.length(); ++i) {
            for (auto j = 0u; j < strlen(secret); ++j) {
                value[i] = value[i] ^ secret[j];
            }
        }
    }

    template <>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char secret[]{ "super secret encryption key" };

        auto temp = reinterpret_cast<char*>(&value);

        for (auto i = 0u; i < sizeof(long long); ++i) {
            for (auto j = 0u; j < strlen(secret); ++j) {
                temp[i] = temp[i] ^ secret[j];
            }
        }

    }

    template <typename T>
    Err_Status Database<T>::GetValue(const std::string& key, T& value) {
        for (auto i = 0u; i < m_size; ++i) {
            if (key == m_keys[i]) {
                value = m_values[i];
                return Err_Status::Err_Success;
            }
        }
        return Err_Status::Err_NotFound;
    }

    template <typename T>
    Err_Status Database<T>::SetValue(const std::string& key, const T& value) {
        if (m_size < 20) {
            m_keys[m_size - 1] = key;
            m_values[m_size - 1] = value;
            ++m_size;
            return Err_Status::Err_Success;
        }
        return Err_Status::Err_OutOfMemory;
    }

    template <typename T>
    Database<T>::~Database() {
        std::cout << "[" << this << "] ~Database()" << std::endl;
        std::ofstream file(m_file + ".bkp.txt");

        
        for (auto i = 0u; i < m_size - 1; ++i) {
            file.width(25);
            file.fill(' ');
            file.setf(std::ios::left);
            file << m_keys[i];
            file.unsetf(std::ios::left);
            encryptDecrypt(m_values[i]);
            file << " -> " << m_values[i] << std::endl;
        }
    }
}
#endif // !SDDS_DATABASE_H
