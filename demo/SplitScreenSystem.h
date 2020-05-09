#ifndef SPLITSCREEN_H
#define SPLITSCREEN_H

#include "../core/system.h"
#include "CustomComponents.hpp"

class SplitScreenSystem : public System{
    private:
        
    public:
        SplitScreenSystem(World* w);
        void init() override;
        void update(float deltaTime) override;
};

#endif
