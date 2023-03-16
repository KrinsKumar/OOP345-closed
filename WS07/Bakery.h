#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <string>
#include <list>
#include <vector>

// count in the bakery class, default constructor and compare friend 


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
        friend bool compare(const BakedGood& good1, const BakedGood& good2, const std::string& sorts);
    };

    class Bakery {
        private:
            std::vector<BakedGood> m_goods;
            size_t m_count = 0;
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
