#include "Game.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>


Game::Game() : m_window(sf::VideoMode(900, 600), "Catchy Catcher"), m_player(), listOfFallingObjects() {}

void Game::run() {
    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void Game::update() {
    sf::Time deltaTime = m_clock.restart();
    m_player.update(deltaTime);

    if (listOfFallingObjects.size() == 0 
        || listOfFallingObjects.size() == 1 
        || listOfFallingObjects.size() == 2
        || listOfFallingObjects.size() == 3
        ) {
        populateFallingObjList();
    }

    for (auto& objPtr : listOfFallingObjects) {
        objPtr->update(deltaTime);
    }
}

void Game::render() {
    m_window.clear(sf::Color::Black);
    m_player.draw(m_window);
    for (auto& objPtr : listOfFallingObjects) {
        objPtr->draw(m_window);
    }

    m_window.display();
}

void Game::populateFallingObjList() {
    std::unique_ptr<FallingGameObj> fallingObj = std::make_unique<FallingGameObj>();
    listOfFallingObjects.push_back(std::move(fallingObj));
}
