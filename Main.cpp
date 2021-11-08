#include <SFML/Graphics.hpp>
#include "Game.h"
///////////////////////|
//created by user2428//|
///////////////////////|


int main()
{
    Game game;

    while (game.getWindowIsOpen()) {
  
        //update
        game.update();
        //render
        game.render();
        
        
    }
    return 0;
}