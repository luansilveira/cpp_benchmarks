#include "Person.h"
#include "PersonBuilder.h"

Person::Person(std::string name) 
        : name_(name),
          annual_income_{} { }

Person::~Person() { }

PersonBuilder Person::create(std::string name) {
    PersonBuilder builder(name);
    return builder;
}
