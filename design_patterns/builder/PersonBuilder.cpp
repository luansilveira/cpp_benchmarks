#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonBuilderBase::PersonBuilderBase(Person &person) 
        : person_(person) {}

PersonBuilderBase::~PersonBuilderBase() {}

PersonBuilder::PersonBuilder(std::string name) 
        : PersonBuilderBase(person_) {
            person_.name_ = name;
        }

PersonBuilder::~PersonBuilder() {}

PersonAddressBuilder PersonBuilderBase::lives() {
    return PersonAddressBuilder{person_};
}

PersonJobBuilder PersonBuilderBase::works() {
    return PersonJobBuilder{person_};
}

Person PersonBuilderBase::build() {
    return person_;
}





