#include "PlayerMovementSystem.h"
#include "CustomComponents.hpp"
#include "../core/glm/glm.hpp"
#include "../core/glm/gtc/matrix_transform.hpp"
#include "../core/components.h"
#include "../core/world.h"
#include "../core/input.h"

#include <iostream>

#define LEFT_BOUNDS -80
#define RIGHT_BOUNDS 500
#define JUMP_WEIGHT 0.08f

std::string testEntity[] = {
    "Entity PhysicsBall\n"
    "Physics 1 1 1 .5     0 0 0   0 0 0\n"
    "Transform 0    -34 3 -8    0 0 0  1 1 1\n"
    "SphereCollider 0    0 0 0   1\n"
    "Render cSphere.obj cube.jpg  1 1 1 1 1 1 2\n"
    "Projectile 1\n"
    "/Entity\n",

    "Entity PhysicsCube\n"
    "Physics 1 1 1 .5     0 0 0   0 0 0\n"
    "Transform 0    -34 3 -8    0 0 0  1 1 1\n"
    "BoxCollider 0      0 0 0    .5 .5 .5\n"
    "Render cube.obj cube.jpg  1 1 1 1 1 1 2\n"
    "Projectile 0\n"
    "/Entity\n"
};

PlayerMovementSystem::PlayerMovementSystem(World* w){
    mWorld = w;
    componentSignature main;
    main[type_id<TransformComponent>()] = 1;
    main[type_id<PlayerMovementComponent>()] = 1;
    neededComponentSignatures.push_back(main);
}

void PlayerMovementSystem::init(){

}

void PlayerMovementSystem::update(float deltaTime){
    for (int e : entities){
        PlayerMovementComponent& pc = mWorld->getComponent<PlayerMovementComponent>(e);
        if (pc.active){
            // true if character facing to the right, false if facing left
            bool rightDirection = true;

            TransformComponent& tc = mWorld->getComponent<TransformComponent>(e);
            PhysicsComponent& tcpc = mWorld->getComponent<PhysicsComponent>(e);

            // close window when player reaches the end of the level
            if (tc.position.x > RIGHT_BOUNDS - 4) {
                // ... 
            }

            if (tcpc.velocity.y < 0.01f)
                pc.grounded = true;

            glm::vec3 forward = glm::normalize((tc.worldRotation * glm::vec3(0, 0, -1)) * glm::vec3(1, 0, 1));
            glm::vec3 left = glm::normalize((tc.worldRotation * glm::vec3(-1, 0, 0)) * glm::vec3(1, 0, 1));
            glm::vec3 up = glm::normalize((tc.worldRotation * glm::vec3(0, 1, 0)) * glm::vec3(0, 1, 0));
            float speed = 0;

            speed =  Input::getKey(GLFW_KEY_LEFT_SHIFT) ? pc.runSpeed : pc.walkSpeed;
            
            if (Input::getKey(GLFW_KEY_A) && tc.position.x > LEFT_BOUNDS){
                tc.position += left * speed * deltaTime;
                rightDirection = false;
            }
            if (Input::getKey(GLFW_KEY_D) && tc.position.x < RIGHT_BOUNDS){
                tc.position -= left * speed * deltaTime;
                rightDirection = true;
            }
            if (Input::getKey(GLFW_KEY_SPACE) && pc.grounded){
                tc.position += up * JUMP_WEIGHT; // * 2.0f;
            }

            tc.rotation = glm::vec3(0, 0, 0); 
            pc.currProjectile = glm::clamp(pc.currProjectile, 0, 1);


            if (Input::getMouseButtonDown(GLFW_MOUSE_BUTTON_1)){
                int baby = mWorld->createEntity(testEntity[pc.currProjectile]);
                TransformComponent& temp2 = mWorld->getComponent<TransformComponent>(baby);
                // temp2.position = tc.worldPosition;
                temp2.rotation = tc.rotation;
                PhysicsComponent& temp = mWorld->getComponent<PhysicsComponent>(baby);
                temp.velocity = glm::vec3(1, 0, 0) * (rightDirection?1.0f:-1.0f) * 2.0f;
            }
        } else if (pc.Iscamera) {
            
            for (int e2 : entities){
                PlayerMovementComponent& pc2 = mWorld->getComponent<PlayerMovementComponent>(e2);
                if (pc2.active) {
                    TransformComponent& tc = mWorld->getComponent<TransformComponent>(e);
                    TransformComponent& tc2 = mWorld->getComponent<TransformComponent>(e2);

                    if (tc.position.x <= tc2.position.x){
                        // tc.position.x += 20;
                    }
                    tc.position.x = tc2.position.x + 3;
                    tc.position.y = tc2.position.y + 5;
                }
            }
        }
    }
}
