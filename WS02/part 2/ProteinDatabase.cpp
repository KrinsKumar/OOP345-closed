/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 24 January, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

namespace sdds {

    ProteinDatabase::ProteinDatabase() {
        m_cnt_str = 0;
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& right_protein) {
        *this = right_protein;
    }

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& right_protein) noexcept {
        *this = move(right_protein);
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& right_protein) {
       
        if (this != &right_protein) {
            delete[] m_str;    // deleting the old memory
            m_cnt_str = right_protein.m_cnt_str;    // shallow copy of static variables

            // deep copy of the dynamic variables
            m_str = new string[m_cnt_str];
            for (auto i = 0u; i < m_cnt_str; ++i) {
                m_str[i] = right_protein.m_str[i];
            }
        }

        return *this;
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& right_protein) noexcept {
        if (this != &right_protein) {
            delete[] m_str;    // deleting the old memory
            m_cnt_str = right_protein.m_cnt_str;    // shallow copy of static variables
    
            m_str = right_protein.m_str;
            right_protein.m_str = nullptr;
            right_protein.m_cnt_str = 0;
        }

        return *this;
    }

    ProteinDatabase::ProteinDatabase(const std::string file_name) {
        ifstream file(file_name);
        m_cnt_str = 0;
        if (file.is_open() != false) {

            string line;
            while (file) {    // to count the number of proteins
                getline(file, line, '\n');
                if (line[0] == '>') ++m_cnt_str;    // if new string is found
            }
            
            file.clear();    
            file.seekg(0);    // returns to the start of the file

            m_str = new string[m_cnt_str + 1];    // allocates the memory for the strings

            auto counter = 0u;
            while (file) {    // untill the end of the file is reached
                getline(file, line);
                if (line[0] != '>') {
                    string templine = "";
                    while (getline(file, templine) && templine[0] != '>') {
                        m_str[counter] = line + templine;
                        line = m_str[counter];
                    } 
                    ++counter;
                }
            }
            file.close();
        }
    }

    size_t ProteinDatabase::size() const {
        return m_cnt_str;
    }

    std::string ProteinDatabase::operator[](size_t index) const {
        string return_string = "";
        if (index < m_cnt_str) {
            return_string = m_str[index];
        }
        return return_string;
    }

    ProteinDatabase::~ProteinDatabase() {
        delete[] m_str;
    }

}