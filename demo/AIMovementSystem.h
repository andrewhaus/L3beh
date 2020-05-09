#ifndef AIMOVEMENTSYSTEM_H
#define AIMOVEMENTSYSTEM_H

#include "../core/system.h"
#include "CustomComponents.hpp"

class AIMovementSystem: public System {     
    public:
        AIMovementSystem(World* w);
        void init() override;
        void update(float deltaTime) override;
};

#endif
