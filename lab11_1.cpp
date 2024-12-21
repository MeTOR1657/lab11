#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main() {
 
    srand(time(0));


    string g[] = {"A", "B+", "B", "C+", "C", "D+", "D", "F", "W"};

    cout << "Press Enter 3 times to reveal your future.";

    
    for (int i = 0; i < 3; i++) {
        cin.get();
    }

    
    int random = rand() % 9; 
    string rangrade = g[random];

    
    cout << "You will get " << rangrade << " in this 261102. ";

    return 0;
}
