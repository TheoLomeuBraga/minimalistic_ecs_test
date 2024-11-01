#pragma once
#include "mecs/mecs.h"
#include <map>

class Person
{

public:
    static std::map<Entity, Person> persons;

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
        if (persons.find(entity) == persons.end())
        {
            persons.insert(std::pair<Entity, Person>(entity, *(Person *)component));
        }
    }

    static void *get(Entity entity)
    {
        if (persons.find(entity) != persons.end() && Person::persons.find(entity) != Person::persons.end()){
            return &persons[entity];
        }
        return NULL;
    }

    static void run(Entity entity)
    {
    }

    static void remove(Entity entity)
    {
        if (persons.find(entity) != persons.end())
        {
            std::cout << "goodbye: " << persons[entity].name << std::endl;
            persons.erase(entity);
        }
    }
};
std::map<Entity, Person> Person::persons = {};

Register_System personregister(Person::add,Person::get,Person::run,Person::remove);