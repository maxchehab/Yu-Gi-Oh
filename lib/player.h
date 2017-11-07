// Specification file for the DynIntStack class
#include "monster.h"
#include "queue.h"
#include "list.h"

#include <string>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
    public:
        int health;
        string name;
        List hand;
        int handLength = 0;
        Queue* attackQueue;
        Queue* defenseQueue;

        Player(string);
        Player(string, int, int, int);
        void print();
        void dammage(int);
        void kill();
        void addCard(Monster);
        Monster removeCard(int);
};

Player::Player(string _name){
    name = _name; 
    health = 8000;
    attackQueue = (new Queue(10));
    defenseQueue = (new Queue(10));
}

Player::Player(string _name, int _health, int handSize, int queueSize){
    name = _name;
    health = _health;
    attackQueue = (new Queue(queueSize));
    defenseQueue = (new Queue(queueSize));
}

void Player::dammage(int dammage){
    health -= dammage;
}

void Player::kill(){
    health = 0;
}

void Player::print(){
    cout << "Player: " << name << endl;
    cout << "Health: " << health << endl;
}

void Player::addCard(Monster monster){
    if(handLength < 5){
        hand.add(monster);
        handLength++;
    }
}

Monster Player::removeCard(int index){
    Monster monster;
    monster = hand.remove(index);
    handLength--;
    return monster;
}
#endif