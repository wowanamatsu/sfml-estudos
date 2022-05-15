#pragma once
#include "../stdafx.hpp"

class Entity {

private:

protected:
    sf::RectangleShape shape;

    float movementSpeed;

public:
    Entity() {
        shape.setSize({50.f, 50.f});
        movementSpeed = 100.f;
    }

    virtual ~Entity() {}

    //================================== FUNCTIONS ===============================================
    //--------------------------------------------------------------------------------------------
    virtual void move(const float& dt, const float dir_x, const float dir_y) {
        shape.move(dir_x * movementSpeed * dt, dir_y * movementSpeed * dt);
    }
    
    //--------------------------------------------------------------------------------------------
    virtual void update( const float& dt ) {


    };

    //--------------------------------------------------------------------------------------------
    virtual void render( sf::RenderTarget* target ) {
        target->draw( shape );
    };
    //--------------------------------------------------------------------------------------------
};