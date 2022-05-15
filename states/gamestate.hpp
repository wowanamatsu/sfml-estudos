#pragma once
#include "state.hpp"

class GameState : public State {

private:


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
    }

    //--------------------------------------------------------------------------------------------
    void render( sf::RenderTarget* target=nullptr ) {}

};