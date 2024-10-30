#include <iostream>

#define MAX_ENTITIES 16
#include "mecs.h"


#include "identity.h"






int main(void)
{

    Entity e1 = new_entity();
    Entity e2 = new_entity();
    Entity e3 = new_entity();
    Entity e4 = new_entity();
    Entity e5 = new_entity();

    std::cout << "ids" << std::endl;
    std::cout << (int)e1 << std::endl;
    std::cout << (int)e2 << std::endl;
    std::cout << (int)e3 << std::endl;
    std::cout << (int)e4 << std::endl;
    std::cout << (int)e5 << std::endl;

    Person p("adam",12);
    Person::add(e1,&p);
    p = Person("joao",23);
    Person::add(e2,&p);
    Identity i;
    Identity::add(e1,&i);
    Identity::add(e2,&i);
    Identity::run(e1);
    Identity::run(e2);

    remove_entity(e1);
    remove_entity(e2);
    remove_entity(e3);
    remove_entity(e4);
    remove_entity(e5);

    e1 = new_entity();
    e2 = new_entity();
    e3 = new_entity();
    e4 = new_entity();
    e5 = new_entity();

    

    Identity::run(e1);
    Identity::run(e2);

    std::cout << std::endl;
    std::cout << "ids" << std::endl;
    std::cout << std::endl;
    std::cout << (int)e1 << std::endl;
    std::cout << (int)e2 << std::endl;
    std::cout << (int)e3 << std::endl;
    std::cout << (int)e4 << std::endl;
    std::cout << (int)e5 << std::endl;

    while (true)
    {
        std::cout << (int)new_entity() << std::endl;
    }

    return (0);
}