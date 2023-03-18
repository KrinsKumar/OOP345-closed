#include <fstream>
#include <iomanip>
#include <algorithm>
#include "Bakery.h"

using namespace std;

// catch (const string& err)

namespace sdds {

    Bakery::Bakery(string name) {
        ifstream file(name);
        if (!file) {
            throw string("unable to open [") + name + "] file";
        }

        string temp1;
        string temp2;
        BakedGood good;

        while (!file.eof()) {
            //to get the line
            getline(file, temp1);

            if(temp1 != "") {
                temp2 = temp1.substr(0, 8);
                while(temp2[0] == ' ') temp2.erase(0, 1);
                while (temp2[temp2.length() - 1] == ' ') temp2.erase(temp2.length() - 1, 1);
                if (temp2 == "Bread") good.m_type = BakedType::BREAD;
                else good.m_type = BakedType::PASTERY;
            
                temp1 = temp1.erase(0, 8);
                temp2 = temp1.substr(0, 20);
                while(temp2[0] == ' ') temp2.erase(0, 1);
                while (temp2[temp2.length() - 1] == ' ') temp2.erase(temp2.length() - 1, 1);
                good.m_desc = temp2;

                temp1 = temp1.erase(0, 20);
                temp2 = temp1.substr(0,14);
                good.m_life = stoi(temp2);

                temp1 = temp1.erase(0, 14);
                temp2 = temp1.substr(0, 8);
                good.m_stock = stoi(temp2);

                temp1 = temp1.erase(0, 8);
                temp2 = temp1.substr(0, 6);
                good.m_price = stod(temp2);

                m_goods.push_back(good);
                ++m_count;
            }
        }
    }

    bool compare(const BakedGood& good1, const BakedGood& good2,const string& sorts) {
        if (sorts == "Description") return good1.m_desc < good2.m_desc;
        else if (sorts == "Shelf") return good1.m_life < good2.m_life;
        else if (sorts == "Stock") return good1.m_stock < good2.m_stock;
        else if (sorts == "Price") return good1.m_price < good2.m_price;
        else return "Invalid String";
    }

    void Bakery::showGoods(ostream& os) const {
        size_t totalStock = 0;
        double totalPrice = 0;
        for_each(m_goods.begin(), m_goods.end(), [&totalStock, &totalPrice](const BakedGood& good){
           totalStock += good.m_stock;  
           totalPrice += good.m_price;  
        });
        for_each(m_goods.begin(), m_goods.end(), [&os, totalStock](const BakedGood& good) {
            os << good << endl;
        });
        os << "Total Stock: " << totalStock << endl;
        os << "Total Price: " << totalPrice << endl;
    }

    ostream& operator<<(ostream& out, const BakedGood& b) {
        out << "* ";
        out.fill(' ');
        out.width(10);
        out << left;
        if (b.m_type == 1) out << "Pastry";
        else out << "Bread";
        out << " * ";
        out.width(20);
        out << b.m_desc;
        out << " * ";
        out.width(5);
        out << b.m_life;
        out << " * ";
        out.width(5);
        out << b.m_stock;
        out << " * ";
        out.width(8);
        out << fixed;
        out << setprecision(2);
        out << right;
        out << b.m_price;
        out << left;
        out << " * ";

        return out;
    }


    void Bakery::sortBakery(const string& sorts) {
        sort(m_goods.begin(), m_goods.end(), [sorts](const BakedGood& good1, const BakedGood& good2){
            return compare(good1, good2, sorts);
        });
    }

    std::vector<BakedGood> Bakery::combine(const Bakery& bake) {
        vector<BakedGood> returnCollection;
        Bakery anotherBakery;
        for_each(m_goods.begin(), m_goods.end(), [&returnCollection](const BakedGood& good) {
            returnCollection.push_back(good);
        });
        for_each(bake.m_goods.begin(), bake.m_goods.end(), [&returnCollection](const BakedGood& good) {
            returnCollection.push_back(good);
        });
        anotherBakery.m_goods = returnCollection;
        anotherBakery.sortBakery("Price");
        return anotherBakery.m_goods;
    }

    bool Bakery::inStock(const string desc, const BakedType& type) const {
        bool returnBool = false;
        for_each(m_goods.begin(), m_goods.end(), [desc, type, &returnBool](const BakedGood& good) {
            if (good.m_desc == desc && good.m_type == type) returnBool = true;
        });
        return returnBool;
    }

    std::list<BakedGood> Bakery::outOfStock(const BakedType& type) const {
        list<BakedGood> goods;
        for_each(m_goods.begin(), m_goods.end(), [type, &goods](const BakedGood& good) {
            if (good.m_type == type && good.m_stock == 0) goods.push_back(good);
        });
        return goods;
    }
    
}