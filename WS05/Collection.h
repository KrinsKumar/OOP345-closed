/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 14 February, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds {

    template <typename T>
    class Collection {
        std::string m_name{};
        T* m_arr{};
        size_t m_count = 0;
        void (*m_func)(const Collection<T>& collection, const T&){};
        public:
            Collection(const std::string& name) {
                m_name = name;
            }

            Collection(const Collection<T>& collection) = delete;
            Collection& operator=(const Collection<T>& collection) = delete;

            const std::string& name() const {
                return m_name;
            }

            size_t size() const {
                return m_count;
            }

            void setObserver(void (*observer)(const Collection<T>&, const T&)) {
                m_func = observer;
            }

            Collection<T>& operator+=(const T& item) {
                bool flag = true;
                for (auto i = 0u; i < m_count && flag; ++i) {
                    if(m_arr[i].title() == item.title()) flag = false;
                }

                if (flag == true) {
                    T* temp = new T[m_count + 2];
                    for (auto i = 0u; i < m_count; ++i) {
                        temp[i] = m_arr[i];
                    }

                    delete[] m_arr;
                    temp[m_count] = item;
                    m_arr = temp;
                    ++m_count;
                    if (m_func != nullptr) {
                        m_func(*this, item);
                    }
                }

                return *this;
            }

            T& operator[](size_t index) const {
                if (index < m_count) {
                    return m_arr[index];
                }
                else {
                    std::string returnString = "Bad index [iindex]. Collection has [count] items.";
                    returnString.replace(returnString.find("iindex"), 6, std::to_string(index));
                    returnString.replace(returnString.find("count"), 5, std::to_string(m_count));
                    throw std::out_of_range(returnString);
                }
            }

            ~Collection() {
                delete[] m_arr;
            }

            T* operator[](const std::string& title) const {
                for (auto i = 0u; i < m_count; ++i) {
                    if(title == m_arr[i].title()) return &(m_arr[i]);
                }
                return nullptr;
            }

            friend std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
                for (auto i = 0u; i < collection.m_count; ++i) {
                    os << collection.m_arr[i];
                }
                return os;
            }
    };

}

#endif // !SDDS_SpellChecker_H
