#ifndef FOODORDER_H
#define FOODORDER_H
#include <iostream>
    
extern double  g_dailydiscount;

extern double g_taxrate;

namespace sdds {

    class FoodOrder {
        private:
            char m_name[10]{};
            char m_desc[25]{};
            double m_price;
            bool m_isDailySpecial;
        public:
            FoodOrder();
            void read(std::istream& is = std::cin);
            void display(std::ostream& os = std::cout);
    };
}

#endif // !FOODORDER_H
