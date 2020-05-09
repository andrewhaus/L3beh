#ifndef ENEMYSTATUSSYSTEM_H
#define ENEMYSTATUSSYSTEM_H

#include "../core/system.h"
#include "CustomComponents.hpp"

class EnemyStatusSystem : public System{
    private:
        
    public:
        EnemyStatusSystem(World* w);
        void init() override;
        void update(float deltaTime) override;
};

#endif
