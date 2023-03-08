#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utilities.h"
#include "Utilities.h"
#include "College.h"
#include "College.h"

void loadData(const char* filename, sdds::College& theCollege)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cout << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	sdds::Person* thePerson = nullptr;
    while (file)
    {
        try {
            thePerson = sdds::buildInstance(file);
        }
        catch (std::string message) {
            std::cout << message << std::endl;
            thePerson = nullptr;
        }
        if (thePerson)
            theCollege += thePerson;
    }
}


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::College theCollege;
	loadData(argv[1], theCollege);
	theCollege.display(std::cout);

	std::list<const sdds::Person*> persons;
	{
        auto students = [](const sdds::Person* person) {
            if (person->status() == "Student") {
                return true;
            } return false;
        };
		theCollege.select(students, persons);
	
		std::cout << "|                                        Test #3 Students in the college!                                              |\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto it = persons.begin(); it != persons.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
	}

	persons.clear();
	{
		auto professors = [](const sdds::Person* person) {
            if (person->status() == "Professor") {
                return true;
            } return false;
        };
		theCollege.select(professors, persons);
	
		std::cout << "|                                        Test #4 Professors in the college!                                            |\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";		
		for (const auto person : persons)
		{
			person->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
	}

	return 0;
}