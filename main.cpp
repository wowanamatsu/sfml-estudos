#include "stdafx.hpp"
#include "player.hpp"

int main() {
    
    sf::RenderWindow window( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Estudos");
    sf::Event e;
    
    window.setFramerateLimit(FPS);
    
    Player player;
    
    while( window.isOpen() ) {
        while( window.pollEvent(e) )
            if( e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape )
                window.close();
            
        window.clear();
        
        //DRAWING
        player.render( window );
        
        window.display();
    }
    
    window.close();
    return 0;
}
