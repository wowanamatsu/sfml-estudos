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

    void update( const float& dt ) {
    }

    void render( sf::RenderTarget* target=nullptr ) {}

};