#include <iostream>
#include "Game.h"


int main() {

    Game<5,3> g;
    g.game_loop();
    // g.player_move();
    // g.display();

    // g.player_move();
    // g.display();

    // g.player_move();
    // g.display();

    std::cout << "state:" << g.validate_win_condition()<< std::endl;

}
