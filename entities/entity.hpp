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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            move(dt, -1.f, 0.f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            move(dt, 1.f, 0.f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            move(dt, 0.f, -1.f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            move(dt, 0.f, 1.f);
        }

    };

    //--------------------------------------------------------------------------------------------
    virtual void render( sf::RenderTarget* target ) {
        target->draw( shape );
    };
    //--------------------------------------------------------------------------------------------
};