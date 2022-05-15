#pragma once
#include "state.hpp"

class GameState : public State {

private:
    Entity player;

    void initKeyBinds() {
        keyBinds.emplace("MOVE_LEFT", supportedKeys->at("A"));
        keyBinds.emplace("MOVE_RIGHT", supportedKeys->at("D"));
        keyBinds.emplace("MOVE_UP", supportedKeys->at("W"));
        keyBinds.emplace("MOVE_DOWN", supportedKeys->at("S"));
    }

public:
    GameState( sf::RenderWindow* window, std::map<std::string, int>* supportedKeys ) 
        : State(window, supportedKeys) 
    {
        initKeyBinds();
    }

    virtual ~GameState() {}

    //================================== FUNCTIONS ===============================================
    //--------------------------------------------------------------------------------------------
    void endState() {}

    //--------------------------------------------------------------------------------------------
    void updateInput( const float& dt ) {
        checkForQuit();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_LEFT")))) {
            player.move(dt, -1.f, 0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_RIGHT")))) {
            player.move(dt, 1.f, 0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_UP")))) {
            player.move(dt, 0.f, -1.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_DOWN")))) {
            player.move(dt, 0.f, 1.f);
        }
    }

    //--------------------------------------------------------------------------------------------
    void update( const float& dt ) {
        updateInput( dt );

        player.update(dt);
    }

    //--------------------------------------------------------------------------------------------
    void render( sf::RenderTarget* target ) {
        if(!target)
            target = window;
        player.render( target );
    }

};