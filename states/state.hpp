#pragma once
#include "../stdafx.hpp"

class State {
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;

public:
    State( sf::RenderWindow* window ) {
        this->window = window;
    }
    
    virtual ~State() {}

    //================================== FUNCTIONS ===============================================
    //--------------------------------------------------------------------------------------------
    virtual void endState() = 0;
    virtual void update( const float& dt ) = 0;
    virtual void render( sf::RenderTarget* target=nullptr ) = 0;

};