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
std::set<Entity> active_entityes;
Entity next_entity = 0;

typedef struct struct_System
{
    void (*add)(Entity, void *);
    void *(*get)(Entity);
    void (*run)(Entity);
    void (*remove)(Entity);
} System;

std::vector<System> Systems;

class Register_System
{
public:
    Register_System(void (*add)(Entity, void *),
                    void *(*get)(Entity),
                    void (*run)(Entity),
                    void (*remove)(Entity))
    {
        System system;

        system.add = add;
        system.get = get;
        system.run = run;
        system.remove = remove;

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
        if (next_entity == MAX_ENTITIES)
        {
            std::cerr << "too many entities" << std::endl;
            abort();
        }
        next_entity++;
    }

    active_entityes.insert(ret);

    return ret;
}

void remove_entity(Entity entity)
{
    for (System s : Systems)
    {
        s.remove(entity);
    }
    free_entityes.insert(entity);
    active_entityes.erase(entity);
}

bool is_entity_valid(Entity entity){return active_entityes.find(entity) != active_entityes.end();}