#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void) {
    return (rand() % 13+1) ; 
}

int calScore(int x, int y, int z) {

    if (x >= 10) x = 0;
    if (y >= 10) y = 0;
    if (z >= 10) z = 0;

    int num = x+y+z;


    return num %10;
}

int findYugiAction(int s) {
	int num;
	cin >> s;
	if(s < 6){
		num = 1;
	}
	if(s >= 9){
		num = 2;
	}
	if(s >= 6 && s <= 8){
		int x = rand()%100;
		if(x<69){
			return 1;
		}
		else{
			return 2;
		}
	}
	
return num%10;
}


void checkWinner(int p, int y){
	if(p<y){
		cout << endl;
		cout << "---------------------------------" << endl;
		cout << "|          Yugi wins!!!         |"<< endl;
		cout << "---------------------------------"<< endl;
	}
	if(p>y){
		cout << endl;
		cout << "---------------------------------"<< endl;
		cout << "|         Player wins!!!        |"<< endl;
		cout << "---------------------------------"<< endl;
	}
	if(p == y){
		cout << endl;
		cout << "---------------------------------"<< endl;
		cout << "|             Draw!!!           |"<< endl;
		cout << "---------------------------------"<< endl;
	}
}

int main(){	
    srand(time(0));

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), drawCard()};
	int yugiCards[3]= {drawCard(), drawCard(), drawCard()};
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],0);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1){
		
	
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		cout << "Your new score: " << calScore(playerCards[0],playerCards[1],playerCards[2]) <<"\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],0);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] <<"\n";
		cout << "Yugi's new score: " << calScore(yugiCards[0],yugiCards[1],yugiCards[2]) <<"\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}