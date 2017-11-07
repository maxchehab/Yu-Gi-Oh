#include <iostream>
#include <string>

#include "./lib/game.h"
#include "./lib/list.h"
#include "./lib/stack.h"
#include "./lib/queue.h"
#include "./lib/monster.h"
//#include "./lib/player.h"

using namespace std;

int main(){
    new Game();
    
    return 0;
}
/*
void test(){
    const int MAX_VALUES = 6;
    
    cout << endl << "Pushing..." << endl << endl;
    Stack stack;
    for(int i = 0; i < MAX_VALUES; i++){
        Monster monster(i, i, "monster");
        monster.print();
        stack.push(monster);
    }

    cout << endl << "Poping" << endl << endl;

    for(int i = 0; i < MAX_VALUES; i++){
        Monster monster;
        stack.pop(monster);        
        monster.print();
    }

    
    cout << endl << "Queuing..." << endl << endl;
    Queue queue(MAX_VALUES);
    for(int i = 0; i < MAX_VALUES; i++){
        Monster monster(i, i, "monster");
        monster.print();
        queue.enqueue(monster);
    }
    cout << endl << "Enqueueing" << endl << endl;
    for(int i = 0; i < MAX_VALUES; i++){
        Monster monster;
        queue.dequeue(monster);        
        monster.print();
    }

    Monster monster(1000, 2000, "Coral Dragon");
    monster.print();
    monster.harm(500);
    monster.print();
    monster.kill();
    monster.print();
}*/