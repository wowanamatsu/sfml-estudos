#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "stdafx.hpp"

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    
public:
    Player() {
        texture.loadFromFile("./assets/player/player.png");
        sprite.setTexture(texture);
        sprite.setPosition({100, 100});
        sprite.setTextureRect( sf::IntRect(0, 0, 40, 50) );
        sprite.setScale({4.0f, 4.0f});
    }
    
    void render( sf::RenderTarget& target ) {
        target.draw( sprite );
    }
    
};
#endif
