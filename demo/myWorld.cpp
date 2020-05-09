#include "../core/runner.h"
#include "../core/components.h"
#include "../core/systems/TransformSystem.h"
#include "../core/systems/PhysicsSystem.h"
#include "../core/systems/CollisionSystem.h"
#include "../core/systems/RenderSystem.h"
#include "PlayerMovementSystem.h"
#include "AIMovementSystem.h"
#include "ProjectileSystem.h"

#include "myWorld.hpp"

MyWorld::MyWorld(){
    mSystems.push_back(new TransformSystem(this));
    mSystems.push_back(new RenderSystem(this));
	// add custom systems here
    mSystems.push_back(new PlayerMovementSystem(this));
	// stop adding custom systems here
    mSystems.push_back(new ProjectileSystem(this));
    mSystems.push_back(new CollisionSystem(this));
    mSystems.push_back(new PhysicsSystem(this));
    mComponents.registerComponent<TransformComponent>();
    mComponents.registerComponent<RenderComponent>();
    mComponents.registerComponent<PlayerMovementComponent>();
    mComponents.registerComponent<PhysicsComponent>();
    mComponents.registerComponent<ColliderComponent>();
    mComponents.registerComponent<BoxColliderComponent>();
    mComponents.registerComponent<SphereColliderComponent>();
    mComponents.registerComponent<CameraComponent>();
    mComponents.registerComponent<PointLightComponent>();
    mComponents.registerComponent<DirectionalLightComponent>();
    mComponents.registerComponent<ProjectileComponent>();
	// Register custom components here
	mComponents.registerComponent<PlayerMovementComponent>();
    mComponents.registerComponent<AIMovementSystem>();
}

bool MyWorld::customWorldGen(int entityID, std::string command, std::istringstream& data){
    if (command == "PlayerMovement"){
        PlayerMovementComponent pc;
        data >> pc.active;
        data >> pc.Iscamera;
        addComponentToEntity<PlayerMovementComponent>(entityID, pc);
    }
    else if (command == "Projectile"){
        ProjectileComponent pc;
        data >> pc.damage;
        addComponentToEntity<ProjectileComponent>(entityID, pc);
    }
    else if (command == "AI") {
        AIMovementComponent ai;
        data >> ai.active;
        data >> ai.startingX;
        data >> ai.startingY;
        data >> ai.startingZ;
        data >> ai.movingRight;
        addComponentToEntity<AIMovementComponent>(entityID, ai);
    }
    else if (command == "PlayerStatus") {
        PlayerStatus status;
        data >> status.alive;
        addComponentToEntity<PlayerStatus>(entityID, status);
    }
    else if (command == "EnemyStatus") {
        EnemyStatus status;
        data >> status.alive;
        addComponentToEntity<EnemyStatus>(entityID, status);
    }
    else if (command == "HUD") {
        HeadsUpDisplay hud;
        data >> hud.active;
        addComponentToEntity<HeadsUpDisplay>(entityID, hud);
    }
    return true;
}
