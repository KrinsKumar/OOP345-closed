/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 1st Feb, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <string>
#include <list>
#include <vector>


namespace sdds {

    enum BakedType {
        BREAD, PASTERY
    };

    struct BakedGood {
        BakedType m_type;
        std::string m_desc;
        size_t m_life;
        size_t m_stock;
        double m_price;
        friend std::ostream& operator<<(std::ostream& out, const BakedGood& b);
    };

    class Bakery {
        private:
            std::vector<BakedGood> m_goods;
        public:
            Bakery() = default;
            Bakery(std::string name);
            void showGoods(std::ostream& os) const;
            void sortBakery(const std::string& sorts);
            std::vector<BakedGood> combine(const Bakery& bake);
            bool inStock(const std::string desc, const BakedType& type) const;
            std::list<BakedGood> outOfStock(const BakedType& type) const;
    };

}

#endif // !SDDS_BAKERY_H
