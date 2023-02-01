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
        if (Collection<T, 100>::size() < 100) {
            bool matchNotFound = true;
            for (auto i = 0u; i < Collection<T, 100>::size() && matchNotFound; ++i) {
                if (Collection<T, 100>::operator[](i) == item) matchNotFound = false;
            }
            if (matchNotFound == true) {
                returnBool = Collection<T, 100>::add(item);
            }
        }
        return returnBool;
    }

    template<>
    bool Set<double>::add(const double& item) {
        bool returnBool = false;
        if (Collection<double, 100>::size() < 100) {
            bool matchNotFound = true;
            for (auto i = 0u; i < Collection<double, 100>::size() && matchNotFound; ++i) {
                if (std::fabs(Collection<double, 100>::operator[](i) - item) <= 0.01) {
                    matchNotFound = false;
                }
            }
            if (matchNotFound == true) {
                returnBool = Collection<double, 100>::add(item);
            }
        }
        return returnBool;
    }

}

#endif // !SDDS_SET_H
