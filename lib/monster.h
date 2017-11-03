#include <string>
#include <iostream>

#ifndef MONSTER_H
#define MONSTER_H

using namespace std;

class Monster{        
    public:
        int attack;
        int health;
        string name;

        Monster(int, int, string);
        Monster();
        void print();
        void harm(int);
        void kill();
};

Monster::Monster(int _attack, int _health, string _name){
    attack = _attack;
    health = _health;
    name = _name;
}

Monster::Monster(){
    attack = 0;
    health = 0;
    name = "";
}

void Monster::print(){
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
}
void Monster::harm(int harm){
    health -= harm;
}

void Monster::kill(){
    health = 0;
}

#endif