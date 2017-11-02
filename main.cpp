#include <iostream>
#include "./lib/stack.h"
#include "./lib/queue.h"

using namespace std;
int main(){
    const int MAX_VALUES = 5;
    
    cout << endl << "Stacking..." << endl << endl;
    Stack stack;
    for(int i = 0; i < MAX_VALUES; i++){
        cout << "Pushing {" << i << "}" << endl;
        stack.push(i);
    }

    for(int i = 0; i < MAX_VALUES; i++){
        int value;
        stack.pop(value);        
        cout << "Poping {" << value << "}" << endl;
    }

    
    cout << endl << "Queuing..." << endl << endl;
    Queue queue(MAX_VALUES);
    for(int i = 0; i < MAX_VALUES; i++){
        cout << "Enqueuing {" << i << "}" << endl;
        queue.enqueue(i);
    }

    for(int i = 0; i < MAX_VALUES; i++){
        int value;
        queue.dequeue(value);        
        cout << "Dequeuing {" << value << "}" << endl;
    }


    return 0;
}