#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <string>
#include <list>
#include <vector>

// count in the bakery class


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
            size_t m_count = 0;
        public:
            Bakery(std::string name);
            void showGoods(std::ostream& os) const;
            void sortBakery(std::string sorts);
            std::vector<BakedGood> combine();
            bool inStock() const;
            std::list<BakedGood> outOfStock(const BakedType& type) const;
    };

}

#endif // !SDDS_BAKERY_H
