#pragma once
#include "../stdafx.hpp"

class State {
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;

    bool quit;

public:
    State( sf::RenderWindow* window ) {
        this->window = window;
        quit = false;
    }

    virtual ~State() {}

    //================================== FUNCTIONS ===============================================
    //--------------------------------------------------------------------------------------------
    const bool& getQuit() const {
        return quit;
    }

    //--------------------------------------------------------------------------------------------
    virtual void checkForQuit() {
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ) {
            quit = true;
        }
    }

    //--------------------------------------------------------------------------------------------
    virtual void endState() = 0;    

    //--------------------------------------------------------------------------------------------
    virtual void updateKeyBinds( const float& dt ) = 0;
    virtual void update( const float& dt ) = 0;
    virtual void render( sf::RenderTarget* target=nullptr ) = 0;

};