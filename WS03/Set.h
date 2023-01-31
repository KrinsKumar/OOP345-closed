#ifndef SDDS_SET_H
#define SDDS_SET_H
#include "Collection.h"

namespace sdds {

    template<typename T>
    class Set : public Collection<typename T, 100> {
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

}

#endif // !SDDS_SET_H
