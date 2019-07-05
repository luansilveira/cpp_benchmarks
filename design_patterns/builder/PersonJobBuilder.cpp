#include "PersonJobBuilder.h"

PersonJobBuilder::PersonJobBuilder(Person &person ) 
        : PersonBuilderBase(person) {}

PersonJobBuilder::~PersonJobBuilder() {}

PersonJobBuilder &PersonJobBuilder::at(std::string company_name) {
    person_.company_name_ = company_name;
    return *this;
}

PersonJobBuilder &PersonJobBuilder::as_a(std::string position) {
    person_.position_ = position;
    return *this;
}

PersonJobBuilder &PersonJobBuilder::earning(int annual_income) {
    person_.annual_income_ = annual_income;
    return *this;
}

