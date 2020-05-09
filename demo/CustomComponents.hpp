#ifndef CUSTOMCOMPONENT_HPP
#define CUSTOMCOMPONENT_HPP

using namespace std;

struct PlayerMovementComponent{
    bool active;
    bool Iscamera;
    bool grounded;
    int currProjectile = 1;
    float walkSpeed = 6.0f;
    float runSpeed = 10.0f;
};

struct AIMovementComponent{
    bool active;
    bool grounded;
    bool movingRight;
    float startingX;
    float startingY;
    float startingZ;
    float health = 100.0f; 
    float walkSpeed = 2.0f;
    float runSpeed = 4.0f;
};

struct ProjectileComponent{
    float speed = 5.0f;
    bool movingRight; 
    float damage = 5.0f;
};

struct HeadsUpDisplay {
    bool active; 
};

struct PlayerStatus {
    bool alive; 
    float health = 100.0f;
    int ammo = 10;
    bool isReloading; 
};

struct EnemyStatus {
    bool alive; 
    float health = 100.0f;
};

#endif
