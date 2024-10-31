#include "mecs/mecs.h"
#include "person.h"

class Identity
{
public:
    static std::map<Entity, Identity> identitys;

    Identity(){}

    static void add(Entity entity,void *component)
    {
        if (identitys.find(entity) == identitys.end()){
            identitys.insert(std::pair<Entity, Identity>(entity,*(Identity*)component));
        }
    }

    static void run(Entity entity)
    {
        if (identitys.find(entity) != identitys.end() && Person::Persons.find(entity) != Person::Persons.end()){
            Person *p = &Person::Persons[entity];
            std::cout << "name: " << p->name << std::endl;
            std::cout << "age: "  << p->age << std::endl;

        }
    }

    static void remove(Entity entity)
    {
        if (identitys.find(entity) != identitys.end()){
            identitys.erase(entity);
        }
    }
};
std::map<Entity, Identity> Identity::identitys = {};

Register_System identityregister(Identity::add,Identity::run,Identity::remove);