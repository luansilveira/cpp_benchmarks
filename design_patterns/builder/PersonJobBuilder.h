#include "PersonBuilder.h"
#ifndef PERSON_JOB_BUILDER_H_
#define PERSON_JOB_BUILDER_H_

#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase {
public:
    PersonJobBuilder(Person &person);
    ~PersonJobBuilder();

    PersonJobBuilder &at(std::string company_name);
    PersonJobBuilder &as_a(std::string position);
    PersonJobBuilder &earning(int income);
};

#endif  // PERSON_JOB_BUILDER_H_
