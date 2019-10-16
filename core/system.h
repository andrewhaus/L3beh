#ifndef SYSTEM_H
#define SYSTEM_H

#include "component_utils.h"
#include <vector>
#include <set>
class World;

class System{
    protected:
        World *mWorld;
        std::vector<componentSignature> neededComponentSignatures;
        std::set<int> entities;

    public:
        System(){}

        // Called before first frame is generated.
        // needs to be overwritten!
        virtual void init() = 0;

        // Called every frame of the game.
        // Needs to be overwritten!
        virtual void update(float deltaTime) = 0;

        // returns a vector of componentSignatures that this system can accept.
        // not recommended to change.
        std::vector<componentSignature> getNeededComponents() { return neededComponentSignatures; }

        // default: adds entity to a set of all entities that fit within the system
        // optional to overwrite
        virtual void addEntity(int entityID, componentSignature sig) { entities.emplace(entityID); }

        // default:
        // optional to overwrite
        virtual void removeEntity(int entityID) { entities.erase(entityID); }
};

#endif
