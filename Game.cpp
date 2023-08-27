#include "Game.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>


Game::Game() : m_window(sf::VideoMode(900, 600), "Catchy Catcher"), m_player(), listOfFallingObjects() {
    if (!font.loadFromFile("arial.ttf")) {
        try {
            throw std::runtime_error("Failed to load font!");
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    scoreDisplayText.setFont(font);
    scoreDisplayText.setCharacterSize(24);
    scoreDisplayText.setFillColor(sf::Color::Red);
    scoreDisplayText.setStyle(sf::Text::Bold | sf::Text::Underlined);
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
    scoreDisplayText.setString("Test");

    static sf::Time timeSinceLastPopulation = sf::Time::Zero;
    timeSinceLastPopulation += deltaTime;

    if (timeSinceLastPopulation >= sf::seconds(3.0f)) {
        populateFallingObjList();
        timeSinceLastPopulation = sf::Time::Zero;
    }

    listOfFallingObjects.erase(
        std::remove_if(
            listOfFallingObjects.begin(),
            listOfFallingObjects.end(),
            [](const std::unique_ptr<FallingGameObj>& obj) {
                return obj->markForRemoval;
            }),
        listOfFallingObjects.end()
    );

    for (auto& objPtr : listOfFallingObjects) {
        objPtr->update(deltaTime);
        //std::cout << listOfFallingObjects.size() << std::endl;
    }
}

void Game::render() {
    m_window.clear(sf::Color::Black);
    m_player.draw(m_window);
    m_window.draw(scoreDisplayText);

    for (auto& objPtr : listOfFallingObjects) {
        objPtr->draw(m_window);
    }

    m_window.display();
}

void Game::populateFallingObjList() {
    std::unique_ptr<FallingGameObj> fallingObj = std::make_unique<FallingGameObj>();
    listOfFallingObjects.push_back(std::move(fallingObj));
}
