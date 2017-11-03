// Specification file for the DynIntStack class
#include "monster.h"
#include "queue.h"

#include <string>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
    public:
        int health;
        string name;
        Monster hand[5];
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
    hand = new Monster[5];
    attackQueue = (new Queue(10));
    defenseQueue = (new Queue(10));
}

Player::Player(string _name, int _health, int handSize, int queueSize){
    name = _name;
    health = _health;
    hand = new Monster[handSize];
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

void addCard(Monster monster){
    if(handLength < 5){
        hand[handLength] = monster;
        handLength++;
    }
}
#endif