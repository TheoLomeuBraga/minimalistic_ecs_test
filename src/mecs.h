#pragma once

#ifndef Entity
#define Entity unsigned char
#endif

#include <limits>

#ifndef MAX_ENTITIES
#define MAX_ENTITIES std::numeric_limits<Entity>::max()
#endif

#include <set>
#include <iostream>
#include <string>
#include <vector>

std::set<Entity> free_entityes;
Entity next_entity = 0;

class Component_Basis{

};

typedef struct struct_System{
    void(*add)(Entity,Component_Basis*);
    void(*run)(Entity);
    void(*remove)(Entity);
} System;
 
std::vector<System> Systems;

class Register_System {
public:
    Register_System(System system){
        Systems.push_back(system);
    }
};

Entity new_entity()
{
    Entity ret;
    if (free_entityes.size() > 0)
    {
        ret = *free_entityes.begin();
        free_entityes.erase(free_entityes.begin());
    }
    else
    {
        ret = next_entity;
        if (next_entity == MAX_ENTITIES){
            std::cerr << "too many entities" << std::endl;
            abort();
        }
        next_entity++;
    }

    return ret;
}

void remove_entity(Entity entity)
{
    for(System s : Systems){
        s.remove(entity);
    }
    free_entityes.insert(entity);
}