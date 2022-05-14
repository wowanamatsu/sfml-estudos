#include "stdafx.hpp"

int main() {
    
    sf::RenderWindow window( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Estudos");
    sf::Event e;
    
    window.setFramerateLimit(FPS);
    
    while( window.isOpen() ) {
        while( window.pollEvent(e) )
            if( e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape )
                window.close();
            
        window.clear();
        
        
        window.display();
    }
    
    window.close();
    return 0;
}
