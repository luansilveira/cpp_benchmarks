#ifndef PERSON_H_
#define PERSON_H_

#include <string>   
#include <iostream>   

class PersonBuilder;

class Person {
 friend class PersonBuilder;
 friend class PersonBuilderBase;
 friend class PersonAddressBuilder;
 friend class PersonJobBuilder;
 
 public:
    Person(std::string name = "");
    ~Person();

    static PersonBuilder create(std::string name);

    friend std::ostream& operator<<(std::ostream& os, const Person& obj) {
        return os
            << " name: " << obj.name_ << std::endl
            << " street_address: " << obj.street_address_ << std::endl
            << " post_code: " << obj.postcode_ << std::endl
            << " city: " << obj.city_ << std::endl
            << " company_name: " << obj.company_name_ << std::endl
            << " position: " << obj.position_ << std::endl
            << " annual_income: " << obj.annual_income_ << std::endl;
    }

 protected:
    std::string name_;
    std::string street_address_;
    std::string postcode_;
    std::string city_;
    std::string company_name_;
    std::string position_;
    int annual_income_;
};


#endif  // PERSON_H_