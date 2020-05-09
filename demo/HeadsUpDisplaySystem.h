#ifndef HUD_H
#define HUD_H

#include "../core/system.h"
#include "CustomComponents.hpp"

class HeadsUpDisplaySystem : public System{
    private:
        
    public:
        HeadsUpDisplaySystem(World* w);
        void init() override;
        void update(float deltaTime) override;
};

#endif
