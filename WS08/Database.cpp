#include <iostream>
#include <fstream>
#include "Database.h"

using namespace std;

namespace sdds {

    shared_ptr<Database> Database::m_pDatabase = nullptr;

    Database::Database(const std::string& filename) {
        cout << "[" << this << "] Database(const std::string&)" << endl;

        ifstream file(filename);

        size_t i;

        for (i = 0; file && i < 20; ++i) {
            string temp;

            getline(file, temp, ' ');
            // to replace the _ with ' '
            while (temp.find('_') != string::npos) {
                temp.replace(temp.find('_'), 1, " ");
            }
            m_keys[i] = temp;

            getline(file, temp, '\n');
            // to get rid of the extra ' '
            while (temp[0] == ' ') temp.erase(0, 1);
            m_values[i] = temp;
        }

        m_file = filename;
        m_size = i + 1;
    }



    std::shared_ptr<Database> Database::getInstance(const string& filename) {
        if (m_pDatabase == nullptr) {
            shared_ptr<Database> temp(new Database(filename));
            m_pDatabase = temp;
            return temp;
        } else return m_pDatabase;
    }

    Err_Status Database::GetValue(const std::string& key, std::string& value) {
        for (auto i = 0u; i < m_size; ++i) {
            if (key == m_keys[i]) {
                value = m_values[i];
                return Err_Status::Err_Success;
            }
        }
        return Err_Status::Err_NotFound;
    }

    Err_Status Database::SetValue(const std::string& key, const std::string& value) {
        if (m_size < 20) {
            m_keys[m_size - 1] = key;
            m_values[m_size - 1] = value;
            ++m_size;
            return Err_Status::Err_Success;
        }
        return Err_Status::Err_OutOfMemory;
    }

    Database::~Database() {
        cout << "[" << this << "] ~Database()" << endl;
        ofstream file(m_file + ".bkp.txt");
        for (auto i = 0u; i < m_size; ++i) {
            file.width(25);
            file.fill(' ');
            file.setf(ios::left);
            file << m_keys[i];
            file << m_values[i] << endl;
            file.unsetf(ios::left);
        }
    }
}