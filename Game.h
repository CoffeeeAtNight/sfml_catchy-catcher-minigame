#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "FallingGameObj.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void populateFallingObjList();

    sf::RenderWindow m_window;
    sf::Clock m_clock;

    sf::Font font;
    sf::Text scoreDisplayText;

    Player m_player;
    std::vector<std::unique_ptr<FallingGameObj>> listOfFallingObjects;

};

#endif // GAME_HPP