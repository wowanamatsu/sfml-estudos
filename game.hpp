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
    std::map<std::string, int> supportedKeys;

    //--------------------------------------------------------------------------------------------
    void initWindow() {
        window = new sf::RenderWindow( sf::VideoMode(SCREEN_W, SCREEN_H), "Estudos de C++ com SFML");
        window->setFramerateLimit(120);
    }

    //--------------------------------------------------------------------------------------------
    void initStates() {
        states.push( new GameState(window, &supportedKeys) );
    }

    //--------------------------------------------------------------------------------------------
    void initKeys() {
        supportedKeys.emplace("A", sf::Keyboard::A);
        supportedKeys.emplace("D", sf::Keyboard::D);
        supportedKeys.emplace("W", sf::Keyboard::W);
        supportedKeys.emplace("S", sf::Keyboard::S);
    }


public:

    Game() {
        initWindow();
        initKeys();
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

    void endApplication() {

    }

    //--------------------------------------------------------------------------------------------
    void updateDelta() {
        //Atualiza a variável delta a cada autlização de frame.
        delta = dtClock.restart().asSeconds();
        
    }
    
    //--------------------------------------------------------------------------------------------
    void updateEvents() {
        while (window->pollEvent(e))
            if(e.type == sf::Event::Closed)
                window->close();
        
    }

    //--------------------------------------------------------------------------------------------
    void update() {
        updateEvents();
        if(!states.empty()) {
            states.top()->update( delta );

            if(states.top()->getQuit()) {
                states.top()->endState();
                delete states.top();
                states.pop();
            }
        }else {
            //Encerra a aplicação
            endApplication();
            window->close();
        }
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