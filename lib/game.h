#include "stack.h"
#include "queue.h"
#include "monster.h"
#include "player.h"

#include <string>
#include <iostream>
#include <random>


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
        void    giveCard(Player);
        void    round();
        void    selectQueues(Player*);
        void    fight();
        int     random(int, int);
};

Game::Game(){

    initDeck();

    cout << "Who is the first player? : ";
    playerA = new Player(readString());

    cout << "Who is the second player? : ";
    playerB = new Player(readString());

    int coin = random(0,1);
    if(coin){
        Player * tempPlayer = playerB;
        playerB = playerA;
        playerA = tempPlayer;
        cout << "Coin tossed heads, " << playerA->name << " goes first!" << endl;
    }else{
        cout << "Coin tossed tails, " << playerA->name << " goes first!" << endl;        
    }

    playerA->print();
    playerB->print();

    for(int i = 0; i < 5; i++){
        Monster monsterA;
        deck.pop(monsterA);
        playerA->addCard(monsterA);

        Monster monsterB;
        deck.pop(monsterB);
        playerB->addCard(monsterB);
    }
    while(playerA->health > 0 && playerB->health > 0){
        cout << "Input any character to start the round!";
        string s;
        cin >> s;  
        round();  
    }

    if(playerA->health > 0){
        cout << "Congratulations " << playerA->name << ", you are the winner!" << endl;
    }else{
        cout << "Congratulations " << playerB->name << ", you are the winner!" << endl;        
    }
}

void Game::round(){
    selectQueues(playerA);
    selectQueues(playerB);

    fight();
}

int Game::random(int min, int max){
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);
    return min + x % n;
}

void Game::fight(){
    Monster playerAMonsterAttack; 
    Monster playerAMonsterDefense;
    Monster playerBMonsterAttack; 
    Monster playerBMonsterDefense;

    playerA->attackQueue->dequeue(playerAMonsterAttack);
    playerA->defenseQueue->dequeue(playerAMonsterDefense);
    playerB->attackQueue->dequeue(playerBMonsterAttack);
    playerB->defenseQueue->dequeue(playerBMonsterDefense);

    int playerADammage = playerBMonsterAttack.attack - playerAMonsterDefense.health;
    if(playerADammage > 0){
        cout << playerB->name << "'s " << playerBMonsterAttack.name << " destroyed " << playerA->name << "'s " << playerAMonsterDefense.name << "!" << endl;
        cout << playerB->name << "'s " << playerBMonsterAttack.name << " dammaged " << playerA->name << " with " << playerADammage << " points!" << endl;
        playerA->dammage(playerADammage);        
    }else{
        cout << playerB->name << "'s " << playerBMonsterAttack.name << " dammaged " << playerAMonsterDefense.name << " with " << playerBMonsterAttack.attack << " points!" << endl;        
    }

    int playerBDammage = playerAMonsterAttack.attack - playerBMonsterDefense.health;
    if(playerBDammage > 0){
        cout << playerA->name << "'s " << playerAMonsterAttack.name << " destroyed " << playerB->name << "'s " << playerBMonsterDefense.name << "!" << endl;
        cout << playerA->name << "'s " << playerAMonsterAttack.name << " dammaged " << playerB->name << " with " << playerBDammage << " points!" << endl;
        playerB->dammage(playerBDammage);        
    }else{
        cout << playerA->name << "'s " << playerAMonsterAttack.name << " dammaged " << playerBMonsterDefense.name << " with " << playerAMonsterAttack.attack << " points!" << endl;        
    }

    playerA->print();
    playerB->print();
}

string Game::readString(){
    string input;
    cin >> input;
    return input;
}

void Game::selectQueues(Player *player){
    cout << endl << "===========================" << endl;    
    cout << player->name << ", it is your turn." << endl;
    cout << "This is your hand:" << endl << endl;
    player->hand.print();
    int attackQueueIndex = -1;
    int defenseQueueIndex = -1;  
    do{
        cout << "Which card do you want to put in your attack queue?" << endl;
        cout << "Card number: ";
        cin >> attackQueueIndex;
        cout << "Which card do you want to put in your defense queue?" << endl;
        cout << "Card number: ";
        cin >> defenseQueueIndex;

        if(attackQueueIndex == defenseQueueIndex){
            cout << "You cannot select the same card for attack and defense!" << endl;\
            attackQueueIndex = -1;
            defenseQueueIndex = -1;
        }else if(attackQueueIndex < 0 || attackQueueIndex > player->handLength || defenseQueueIndex < 0 || defenseQueueIndex > player->handLength){
            cout << "You must select a card between 0 and " << player->handLength << endl;
            attackQueueIndex = -1;
            defenseQueueIndex = -1;
        }
    }while(attackQueueIndex == -1 || defenseQueueIndex == -1);

    Monster attackMonster = player->hand.remove(attackQueueIndex);
    Monster defenseMonster = player->hand.remove(defenseQueueIndex - 1);
    
    player->attackQueue->enqueue(attackMonster);
    player->defenseQueue->enqueue(defenseMonster);
    
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
        Monster monster(random(600,1500), random(600,1500), names[i]);
        deck.push(monster);
    }
}

#endif