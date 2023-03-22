/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 20 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CUSTOMERSORDER_H
#define SDDS_CUSTOMERSORDER_H

#include <string>
#include "Station.h"

namespace sdds {

    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };

        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder {
        private:
            std::string m_name;
            std::string m_product;
            size_t m_cntItem;
            Item** m_lstItem{};
            static size_t m_widthField;
        public:
            CustomerOrder();
            CustomerOrder(const std::string info);
            CustomerOrder(const CustomerOrder& newOrder);
            CustomerOrder& operator=(const CustomerOrder& newOrder) = delete;
            CustomerOrder(CustomerOrder&& newOrder) noexcept;
            CustomerOrder& operator=(CustomerOrder&& newOrder) noexcept;
            ~CustomerOrder();

            bool isOrderFilled() const;
            bool isItemFilled(const std::string& itemName) const;
            void fillItem(sdds::Station& station, std::ostream& os);
            void display(std::ostream& os) const;

    };

}

#endif // !SDDS_CUSTOMERSORDER_H
