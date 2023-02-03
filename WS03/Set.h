/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 1st Feb, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <cmath>
#include "Collection.h"

namespace sdds {

    template<typename T>
    class Set : public Collection<T, 100> {
        public:
            bool add(const T& item);
    };

    template<typename T>
    bool Set<T>::add(const T& item) {
        bool returnBool = false;
        if ((*this).size() < 100) {
            bool matchNotFound = true;
            for (auto i = 0u; i < (*this).size() && matchNotFound; ++i) {
                if ((*this)[i] == item) matchNotFound = false;
            }
            if (matchNotFound == true) {
                returnBool = (*this).add(item);
            }
        }
        return returnBool;
    }

    template<>
    bool Set<double>::add(const double& item) {
        bool returnBool = false;
        if ((*this).size() < 100) {
            bool matchNotFound = true;
            for (auto i = 0u; i < (*this).size() && matchNotFound; ++i) {
                if (std::fabs((*this)[i] - item) <= 0.01) {
                    matchNotFound = false;
                }
            }
            if (matchNotFound == true) {
                returnBool = (*this).add(item);
            }
        }
        return returnBool;
    }

}

#endif // !SDDS_SET_H
