#include "PlayerStatusSystem.h"
#include "CustomComponents.hpp"
#include "../core/glm/glm.hpp"
#include "../core/glm/gtc/matrix_transform.hpp"
#include "../core/components.h"
#include "../core/world.h"
#include "../core/input.h"

#include <iostream>

PlayerStatusSystem::PlayerStatusSystem(World* w){
    mWorld = w;
    componentSignature main;
    main[type_id<TransformComponent>()] = 1;
    main[type_id<PlayerMovementComponent>()] = 1;
    neededComponentSignatures.push_back(main);
}

void PlayerStatusSystem::init(){

}

void PlayerStatusSystem::update(float deltaTime){
    for (int e : entities){
        PlayerStatus& player = mWorld->getComponent<PlayerStatus>(e);
        if (player.alive){
            
        }
    }
}
