#include <iostream>
using namespace std;

// Incomplete

int main() {
   const int ROCK = 0;
   const int PAPER = 1;
   const int SCISSORS = 2;
   string playerOne;
   string playerTwo;
   int playerOneWins = 0;
   int playerTwoWins = 0;
   int rounds;

   int seed;
   cin >> seed;
   srand(seed);
   
   cin >> playerOne;
   cin >> playerTwo;
   
   cin >> rounds;
   
   while(rounds < 1) {
      cout << "Rounds must be > 0" << endl;
      cin >> rounds;
   }
   
   cout << playerOne << " vs " << playerTwo << " for " << rounds << " rounds" << endl;
   
   for (int i = 0; i < rounds; i++) {
      int playerOneChoice = rand() % 3;
      int playerTwoChoice = rand() % 3;
   
      while (playerOneChoice == playerTwoChoice) {
         cout << "Tie" << endl;
         
         playerOneChoice = rand() % 3;
         playerTwoChoice = rand() % 3;
      }
      
      if (playerOneChoice == ROCK && playerTwoChoice == SCISSORS) {
         playerOneWins++;
         cout << playerOne << " wins with rock" << endl;
      } else if (playerOneChoice == SCISSORS && playerTwoChoice == PAPER) {
         playerOneWins++;
         cout << playerOne << " wins with scissors" << endl;
      } else if (playerOneChoice == PAPER && playerTwoChoice == SCISSORS) {
         playerOneWins++;
         cout << playerOne << "  wins with paper" << endl;
      } else if (playerTwoChoice == ROCK && playerOneChoice == SCISSORS) {
         playerTwoWins++;
         cout << playerTwo << " wins with rock" << endl;
      } else if (playerTwoChoice == SCISSORS && playerOneChoice == PAPER) {
         playerTwoWins++;
         cout << playerTwo << " wins with scissors" << endl;
      } else if (playerTwoChoice == PAPER && playerOneChoice == SCISSORS) {
         playerTwoWins++;
         cout << playerTwo << "  wins with paper" << endl;
      } else cout << "UNKNOWN" << endl;
   }
   
   cout << playerOne << " wins " << playerOneWins << " and " << playerTwo << " wins " << playerTwoWins << endl;
   return 0;

}
