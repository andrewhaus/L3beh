#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include "../core/system.h"
#include "CustomComponents.hpp"

class PlayerStatusSystem : public System{
    private:
        
    public:
        PlayerStatusSystem(World* w);
        void init() override;
        void update(float deltaTime) override;
};

#endif
