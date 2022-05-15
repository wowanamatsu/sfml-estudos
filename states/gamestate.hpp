#pragma once
#include "state.hpp"

class GameState : public State {

private:
    Entity player;

public:
    GameState( sf::RenderWindow* window ) : State(window) {
    }

    virtual ~GameState() {}

    //================================== FUNCTIONS ===============================================
    //--------------------------------------------------------------------------------------------
    void endState() {}

    //--------------------------------------------------------------------------------------------
    void updateKeyBinds( const float& dt ) {
        checkForQuit();
    }

    //--------------------------------------------------------------------------------------------
    void update( const float& dt ) {
        updateKeyBinds( dt );

        player.update(dt);
    }

    //--------------------------------------------------------------------------------------------
    void render( sf::RenderTarget* target ) {
        player.render( window );
    }

};