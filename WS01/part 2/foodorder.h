/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 20th January, 2023
*/
#ifndef FOODORDER_H
#define FOODORDER_H
#include <iostream>
    
extern double g_taxrate;

extern double g_dailydiscount;

namespace sdds {

    class FoodOrder {
        private:
            char m_name[10]{};
            char* m_desc{};
            double m_price;
            bool m_isDailySpecial;
        public:
            FoodOrder();
            FoodOrder(const FoodOrder& other);

            FoodOrder& operator=(const FoodOrder& other);
            void read(std::istream& is = std::cin);
            void display(std::ostream& os = std::cout);

            ~FoodOrder();
    };
}

#endif // !FOODORDER_H
