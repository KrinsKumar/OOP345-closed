/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 1st Feb, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include "Pair.h"

namespace sdds {

    template<typename T, size_t SIZE>
        class Collection {
            T m_data[SIZE]{};
            size_t m_currentCnt = 0;
            public:
                size_t size() const;
                std::ostream& display(std::ostream& os = std::cout) const;
                virtual bool add(const T& item);
                T operator[](size_t index) const;
                virtual ~Collection(){};
        };

    template<typename T, size_t SIZE>
    size_t Collection<T, SIZE>::size() const {
        return m_currentCnt;
    }

    template<typename T, size_t SIZE> 
    std::ostream& Collection<T, SIZE>::display(std::ostream& os) const {
        os << "----------------------" << std::endl;
        os << "| Collection Content |" << std::endl;
        os << "----------------------" << std::endl;
        for (auto i = 0u; i < m_currentCnt; ++i) {
            os << m_data[i] << std::endl;
        }
        os << "----------------------" << std::endl;
        return os;
    }

    template<typename T, size_t SIZE>
    bool Collection<T, SIZE>::add(const T& item) {
        bool returnBool = false;

        if (m_currentCnt < SIZE) {
            m_data[m_currentCnt] = item;
            ++m_currentCnt;
            returnBool = true;
        }

        return returnBool;
    }

    template<typename T, size_t SIZE>
    T Collection<T, SIZE>::operator[](size_t index) const {
        T returnCollection{};
        if (m_currentCnt > index) {
            returnCollection = m_data[index];
        }
        return returnCollection;
    }

    template<>
    Pair Collection<Pair, 100>::operator[](size_t index) const {
        Pair returnPair("No Key", "No Value");

        if (m_currentCnt > index) {
            returnPair = m_data[index];
        }

        return returnPair;
    }
}

#endif // !SDDS_COLLECTION_H
