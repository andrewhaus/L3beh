#include "AIMovementSystem.h"
#include "CustomComponents.hpp"
#include "../core/glm/glm.hpp"
#include "../core/glm/gtc/matrix_transform.hpp"
#include "../core/components.h"
#include "../core/world.h"
#include "../core/input.h"

#include <iostream>

#define LEFT_BOUNDS -80
#define RIGHT_BOUNDS 200
#define JUMP_WEIGHT 0.08f

AIMovementSystem::AIMovementSystem(World* w){
    mWorld = w;
    componentSignature main;
    main[type_id<TransformComponent>()] = 1;
    main[type_id<PlayerMovementComponent>()] = 1;
    neededComponentSignatures.push_back(main);
}

void AIMovementSystem::init(){

}

void AIMovementSystem::update(float deltaTime){
    for (int e : entities){
        AIMovementComponent& ai = mWorld->getComponent<AIMovementComponent>(e);
        if (ai.active){
            TransformComponent& tc = mWorld->getComponent<TransformComponent>(e);
            PhysicsComponent& pc = mWorld->getComponent<PhysicsComponent>(e);

            if (tc.position.x >= ai.startingX + 5)
                    pc.velocity.x = -1.0f * ai.runSpeed;
            else if (tc.position.x <= ai.startingX - 5)
                    pc.velocity.x = -1.0f * ai.runSpeed;
        }
    }
}
