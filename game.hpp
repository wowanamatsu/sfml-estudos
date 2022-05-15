#pragma once
#include "stdafx.hpp"
#include "states/gamestate.hpp"


class Game {

private:

    sf::RenderWindow *window;
    sf::Event e;

    sf::Clock dtClock;
    float delta;

    std::stack<State*> states;

    //--------------------------------------------------------------------------------------------
    void initWindow() {
        window = new sf::RenderWindow( sf::VideoMode(SCREEN_W, SCREEN_H), "Estudos de C++ com SFML");
        window->setFramerateLimit(120);
    }

    //--------------------------------------------------------------------------------------------
    void initStates() {
        states.push( new GameState(window) );
    }


public:

    Game() {
        initWindow();
        initStates();
    }

    virtual ~Game() { 
        delete window;
        while( !states.empty() ) {
            delete states.top();
            states.pop();
        }
    }

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
        if(!states.empty()) states.top()->update( delta );
    }

    //--------------------------------------------------------------------------------------------
    void render() {
        window->clear();

        //Draw
        if(!states.empty()) states.top()->render();

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