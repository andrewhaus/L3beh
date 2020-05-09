//
//  myWorld.hpp
//  L3Beh
//
//  Created by Andrew Niedringhaus on 1/22/20.
//  Copyright © 2020 Andrew Niedringhaus. All rights reserved.
//

#pragma once

#include "../core/world.h"

class MyWorld : public World{
    public:
        MyWorld();
        bool customWorldGen(int entityID, std::string command, std::istringstream& data) override;
};
