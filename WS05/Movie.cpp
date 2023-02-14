#include "Movie.h"

using namespace std;

namespace sdds {

    Movie::Movie() {
        m_year = 0;
    }

    Movie::Movie(const std::string& strMovie) {
        
    }

    const std::string& Movie::title() const {
        return m_title;
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {

    }

}