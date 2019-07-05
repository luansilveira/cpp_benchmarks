#ifndef PERSON_BUILDER_H_
#define PERSON_BUILDER_H_

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
 public:
    explicit PersonBuilderBase(Person &person);
    virtual ~PersonBuilderBase();

    PersonAddressBuilder lives();

    PersonJobBuilder works();
    
    Person build();

    operator Person() {
        return person_;
    }


 protected:    
    Person &person_;
};

class PersonBuilder : public PersonBuilderBase {
 public:
    PersonBuilder(std::string name);
    ~PersonBuilder();

 private:
    Person person_;
};

#endif  // PERSON_BUILDER_H_