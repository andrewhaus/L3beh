#include "EnemyStatusSystem.h"
#include "CustomComponents.hpp"
#include "../core/glm/glm.hpp"
#include "../core/glm/gtc/matrix_transform.hpp"
#include "../core/components.h"
#include "../core/world.h"
#include "../core/input.h"

#include <iostream>

EnemyStatusSystem::EnemyStatusSystem(World* w){
    mWorld = w;
    componentSignature main;
    main[type_id<TransformComponent>()] = 1;
    main[type_id<PlayerMovementComponent>()] = 1;
    neededComponentSignatures.push_back(main);
}

void EnemyStatusSystem::init(){

}

void EnemyStatusSystem::update(float deltaTime){
    for (int e : entities){
        
    }
}
