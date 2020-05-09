#include "SplitScreenSystem.h"
#include "CustomComponents.hpp"
#include "../core/glm/glm.hpp"
#include "../core/glm/gtc/matrix_transform.hpp"
#include "../core/components.h"
#include "../core/world.h"
#include "../core/input.h"

#include <iostream>

SplitScreenSystem::SplitScreenSystem(World* w){
    mWorld = w;
    componentSignature main;
    main[type_id<TransformComponent>()] = 1;
    main[type_id<PlayerMovementComponent>()] = 1;
    neededComponentSignatures.push_back(main);
}

void SplitScreenSystem::init(){

}

void SplitScreenSystem::update(float deltaTime){
    // 
}
