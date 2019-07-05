#include <iostream>
#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"


int main(int argc, char const *argv[]) {
    auto person = Person::create("Luan")
        .lives().at("English Beach").with_postcode("1234").in("Florianopolis")
        .works().at("ABC").as_a("Software Engineer").earning(100000).build();

    std::cout << person << std::endl;
    return 0;
}
