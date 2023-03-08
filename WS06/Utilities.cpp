#include <string>
#include <iostream>
#include "Utilities.h"
#include "Person.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"

namespace sdds {

    Person* buildInstance(std::istream& in) {
        char temp = '0';
        in >> temp;
        in.ignore(); //ignores the , after the first letter
        if (temp == 'e' || temp == 'E') {
            Employee emp(in);    // extracts the employee information
            Employee* returnEmployee = new Employee;
            *returnEmployee = emp;
            return returnEmployee;
        }
        else if (temp == 'p' || temp == 'P') {
            Professor pro(in);    // extracts the professor information
            Professor* returnProfessor = new Professor;
            *returnProfessor = pro;
            return returnProfessor;
        }
        else if (temp == 's' || temp == 'S') {
            Student stu(in);    // extracts the student information
            Student* returnStudent = stu.newStu();;
            return returnStudent;
        }
        else {
            in.ignore(1000, '\n');
            return nullptr;
        }
    }

}