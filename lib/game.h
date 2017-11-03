#include "stack.h"
#include "queue.h"
#include "monster.h"
#include "player.h"

#include <string>
#include <iostream>

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game{
    public: 
        Player*     playerA;
        Player*     playerB;
        Stack       deck;
        
        Game();
        void    initDeck();
        string  readString();
        void    giveCard(&Player)
};

Game::Game(){

    initDeck();

    cout << "Who is the first player? : ";
    playerA = new Player(readString());

    cout << "Who is the second player? : ";
    playerB = new Player(readString());

    playerA->print();
    playerB->print();
}

string Game::readString(){
    string input;
    cin >> input;
    return input;
}

void Game::initDeck(){
    string names[20] = {
        "Vampling",
        "Hollowwings",
        "Vortexsoul",
        "Terrormask",
        "The Cloudy Wraith",
        "The Electric Mongrel",
        "The Eternal Statue",
        "The Aquatic Raptor Warthog",
        "The Arctic Skeleton Bee",
        "The Red-Eyed Assassin Swine",
        "Vampling",
        "Hollowwings",
        "Vortexsoul",
        "Terrormask",
        "The Cloudy Wraith",
        "The Electric Mongrel",
        "The Eternal Statue",
        "The Aquatic Raptor Warthog",
        "The Arctic Skeleton Bee",
        "The Red-Eyed Assassin Swine",
    };

    for(int i = 0; i < 20; i++){
        Monster monster(1000, 1000, names[i]);
        deck.push(monster);
    }
}

#endif