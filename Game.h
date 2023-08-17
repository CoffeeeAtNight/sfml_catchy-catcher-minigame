#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    sf::Clock m_clock;

    Player m_player;

    // Other game-related variables and classes...
};

#endif // GAME_HPP