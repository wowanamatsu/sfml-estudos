#pragma once
#include "../entities/entity.hpp"

class State {
private:
protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keyBinds;
    bool quit;

    virtual void initKeyBinds() = 0;

public:
    State( sf::RenderWindow* window, std::map<std::string, int>* supportedKeys ) {
        this->window = window;
        this->supportedKeys = supportedKeys;
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
    virtual void updateInput( const float& dt ) = 0;
    virtual void update( const float& dt ) = 0;
    virtual void render( sf::RenderTarget* target=NULL ) = 0;

};