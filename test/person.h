#pragma once
#include "mecs/mecs.h"
#include <map>

class Person
{

public:
    static std::map<Entity, Person> Persons;

    std::string name;
    unsigned int age;

    Person(){

    }

    Person(std::string name, unsigned int age)
    {
        this->name = name;
        this->age = age;
    }

    static void add(Entity entity, void *component)
    {
        if (Persons.find(entity) == Persons.end())
        {
            Persons.insert(std::pair<Entity, Person>(entity, *(Person *)component));
        }
    }

    static void run(Entity entity)
    {
    }

    static void remove(Entity entity)
    {
        if (Persons.find(entity) != Persons.end())
        {
            std::cout << "goodbye: " << Persons[entity].name << std::endl;
            Persons.erase(entity);
        }
    }
};
std::map<Entity, Person> Person::Persons = {};

Register_System personregister(Person::add,Person::run,Person::remove);