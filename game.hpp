#pragma once
#include "stdafx.hpp"

class Game {

private:

    sf::RenderWindow *window;
    sf::Event e;

    sf::Clock dtClock;
    float delta;

    //--------------------------------------------------------------------------------------------
    void initWindow() {
        window = new sf::RenderWindow( sf::VideoMode(SCREEN_W, SCREEN_H), "Estudos de C++ com SFML");
    }


public:

    Game() {
        initWindow();
    }

    virtual ~Game() { delete window; }

    //================================== FUNCTIONS ===============================================

    void updateDelta() {
        //Atualiza a variável delta a cada autlização de frame.
        delta = dtClock.restart().asSeconds();
        
    }
    
    //--------------------------------------------------------------------------------------------
    void updateEvents() {
        while (window->pollEvent(e))
            if(e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape)
                window->close();
        
    }

    //--------------------------------------------------------------------------------------------
    void update() {
        updateEvents();
    }

    //--------------------------------------------------------------------------------------------
    void render() {
        window->clear();

        window->display();
    }

    //--------------------------------------------------------------------------------------------
    void run() {
        while( window->isOpen() ) {
            updateDelta();
            update();
            render();
        }
    }

};