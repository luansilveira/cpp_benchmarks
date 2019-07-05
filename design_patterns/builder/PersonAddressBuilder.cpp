#include "PersonAddressBuilder.h"
#include "Person.h"

PersonAddressBuilder::PersonAddressBuilder(Person &person)
        : PersonBuilderBase(person) {}

PersonAddressBuilder::~PersonAddressBuilder() {}

PersonAddressBuilder &PersonAddressBuilder::at(std::string address) {
    person_.street_address_ = address;
    return *this;
}
PersonAddressBuilder &PersonAddressBuilder::with_postcode(std::string post_code) {
    person_.postcode_ = post_code;
    return *this;
}
PersonAddressBuilder &PersonAddressBuilder::in(std::string city) {
    person_.city_ = city;
    return *this;
};