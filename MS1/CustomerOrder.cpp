/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 20 March, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
//#include <utility>
#include <string>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder() {
        m_name = "";
        m_product = "";
        m_cntItem = 0;
    }

    CustomerOrder::CustomerOrder(const std::string info) {
        Utilities utLocal;
        size_t pos = 0u;
        bool next = true;

        try {
            m_name = utLocal.extractToken(info, pos, next);
            if (next) m_product = utLocal.extractToken(info, pos, next);

            //to get the count of the items
            auto itemsStart = pos;
            size_t count = 0;
            while (next) {
                auto temp = utLocal.extractToken(info, pos, next);
                ++count;
            }

            //to read and dynamically store the items
            pos = itemsStart;
            next = true;
            m_cntItem = count;
            m_lstItem = new Item*[m_cntItem];
            count = 0;
            while (next) {
                auto temp = utLocal.extractToken(info, pos, next);
                m_lstItem[count] = new Item(temp);
                ++count;
            }

            //to update the widthField
            if (m_widthField < utLocal.getFieldWidth()) m_widthField = utLocal.getFieldWidth();

        }
        catch (const char* err) {
            cout << err;
        }
        
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& newOrder) {
        m_name = "";
        m_product = "";
        m_cntItem = 0;
        throw("Creating copies of CustomerOrder is not allowed!");
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& newOrder) noexcept {
        *this = move(newOrder);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& newOrder) noexcept {
        m_name = newOrder.m_name;
        m_product = newOrder.m_product;
        m_cntItem = newOrder.m_cntItem;

        if (m_lstItem != nullptr) {
            for (auto i = 0u; i < m_cntItem; ++i) {
                delete m_lstItem[i];
            }
        }
        delete[] m_lstItem;

        m_lstItem = newOrder.m_lstItem;
        newOrder.m_lstItem = nullptr;
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        if (m_lstItem != nullptr) {
            for (auto i = 0u; i < m_cntItem; ++i) {
                delete m_lstItem[i];
            }
        }
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        bool returnBool = true;

        for (auto i = 0u; i < m_cntItem; ++i) {
            if (!m_lstItem[i]->m_isFilled) {
                returnBool = false;
                break;
            }
        }

        return returnBool;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool returnBool = true;

        for (auto i = 0u; i < m_cntItem; ++i) {
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
                returnBool = false;
                break;
            }
        }

        return returnBool;
    }

    void CustomerOrder::fillItem(sdds::Station& station, std::ostream& os) {
        bool isItemHere = false;
        size_t index = -1;

        for (auto i = 0u; i < m_cntItem; ++i) {
            if (m_lstItem[i]->m_itemName == station.getItemName()) {
                isItemHere = true;
                index = i;
            }
        }

        if (isItemHere && station.getQuantity() > 0) {
            m_lstItem[index]->m_isFilled = true;
            station.updateQuantity();
            os << "Filled " << m_name << ", PRODUCT[ " << m_lstItem[index]->m_itemName << "]" << endl;
        }
        else if (isItemHere && station.getQuantity() == 0) {
            os << "Unable " << m_name << ", PRODUCT[ " << m_lstItem[index]->m_itemName << "]" << endl;
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << endl;
        for (auto i = 0u; i < m_cntItem; ++i) {
            os << "[";
            os.width(6);
            os.fill('0');
            os << m_lstItem[i]->m_serialNumber << "] ";
            os << left;
            os.fill(' ');
            os.width(m_widthField + 3);
            os << m_lstItem[i]->m_itemName << "- ";
            if (m_lstItem[i]->m_isFilled == true) {
                os << "Filled" << endl;
            }
            else os << "TO BE FILLED" << endl;
        }
    }

}
