#include "HeadsUpDisplaySystem.h"
#include "CustomComponents.hpp"
#include "../core/glm/glm.hpp"
#include "../core/glm/gtc/matrix_transform.hpp"
#include "../core/components.h"
#include "../core/world.h"
#include "../core/input.h"

#include <iostream>
// TODO: download and use freetype library to enable text rendering on screen for HUD
// #include <ft2build.h>
// #include FT_FREETYPE_H 

HeadsUpDisplaySystem::HeadsUpDisplaySystem(World* w){
    mWorld = w;
    componentSignature main;
    main[type_id<TransformComponent>()] = 1;
    main[type_id<PlayerMovementComponent>()] = 1;
    neededComponentSignatures.push_back(main);
}

void HeadsUpDisplaySystem::init(){

}

void HeadsUpDisplaySystem::update(float deltaTime){
    for (int e : entities){
        HeadsUpDisplay& hud = mWorld->getComponent<HeadsUpDisplay>(e);
        PlayerStatus& player = mWorld->getComponent<PlayerStatus>(e);
        if (hud.active && player.alive){
            // std::cout << "Health: " << player.health << std::endl;
            // std::cout << "Ammo: " << player.ammo << std::endl;
        }
    }
}
