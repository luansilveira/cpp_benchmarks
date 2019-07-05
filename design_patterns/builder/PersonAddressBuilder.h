#ifndef PERSON_ADDRESS_BUILDER_H_
#define PERSON_ADDRESS_BUILDER_H_

#include "PersonBuilder.h"

class PersonAddressBuilder : public PersonBuilderBase {
 public:
    PersonAddressBuilder(Person &person);

    ~PersonAddressBuilder();

    PersonAddressBuilder &at(std::string address);
    PersonAddressBuilder &with_postcode(std::string post_code);
    PersonAddressBuilder &in(std::string city);
};

#endif  // PERSON_ADDRESS_BUILDER_H_
