#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>

namespace sdds {

    class Pair
    {
        std::string m_key{};
        std::string m_value{};
        public:
            Pair();
            const std::string& getKey() const { return m_key; }
            const std::string& getValue() const { return m_value; }
            Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

            Pair& operator=(const Pair& rightPair);
            bool operator==(const Pair& rightPair) const;
            friend std::ostream& operator<<(std::ostream& os ,const Pair& rightPair);
    };

}

#endif // !SDDS_PAIR_H