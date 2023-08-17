#include "Game.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

Game::Game() : m_window(sf::VideoMode(900, 600), "Catchy Catcher"), m_player() {
}

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
}

void Game::render() {
    m_window.clear(sf::Color::Black);
    m_player.draw(m_window);

    m_window.display();
}
