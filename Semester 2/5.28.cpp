#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> playerNums;
    vector<int> playerRatings;
    char option;

    for (int i = 0; i < 5; i++) {
	    int jerseyNumber;
	    int rating;

	    cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
	    cin >> jerseyNumber;

        playerNums.push_back(jerseyNumber);

	    cout << "Enter player " << i + 1 << "'s rating:" << endl;
	    cin >> rating;

        playerRatings.push_back(rating);

        cout << endl;
    }
    
    cout << "ROSTER" << endl;

    for (int i = 0; i < static_cast<int>(playerNums.size()); i++) {
        cout
            << "Player " << i + 1
            << " -- Jersey number: " << playerNums.at(i)
            << ", Rating: " << playerRatings.at(i) << endl;
    }

    cout
        << endl << "MENU" << endl
        << "a - Add player" << endl
        << "d - Remove player" << endl
        << "u - Update player rating" << endl
        << "r - Output players above a rating" << endl
        << "o - Output roster" << endl
        << "q - Quit" << endl << endl
        << "Choose an option:" << endl;

    cin >> option;

    while (option != 'q') {
        if (option == 'a') {
	        int jerseyNumber;
	        int rating;

	        cout << "Enter a new player's jersey number:" << endl;
	        cin >> jerseyNumber;

            playerNums.push_back(jerseyNumber);

	        cout << "Enter the player's rating:" << endl;
	        cin >> rating;

            playerRatings.push_back(rating);
        } else if (option == 'd') {
            int playerNum;
            int chosenPlayerIndex;

            cout << "Enter a jersey number:" << endl;
            cin >> playerNum;

            for (int i = 0; i < static_cast<int>(playerNums.size()); i++) {
                if (playerNums.at(i) == playerNum) chosenPlayerIndex = i; 
            }

            if (!chosenPlayerIndex) {
                cout << "Error: Invalid player jersey" << endl;

                continue;
            }

            playerNums.erase(playerNums.begin() + chosenPlayerIndex);
            playerRatings.erase(playerRatings.begin() + chosenPlayerIndex);
        } else if (option == 'u') {
            int playerNum;
            int chosenPlayerIndex;
            int newRating;

            cout << "Enter a jersey number:" << endl;
            cin >> playerNum;

            for (int i = 0; i < static_cast<int>(playerNums.size()); i++) {
                if (playerNums.at(i) == playerNum) chosenPlayerIndex = i; 
            }

            if (!chosenPlayerIndex) {
                cout << "Error: Invalid player jersey" << endl;

                continue;
            }

            cout << "Enter a new rating for player:" << endl;
            cin >> newRating;

            playerRatings.at(chosenPlayerIndex) = newRating;
        } else if (option == 'r') {
            int chosenRating;
            int counter = 1;

            cout << "Enter a rating:" << endl;
            cin >> chosenRating;

            cout << "ABOVE " << chosenRating << endl;

            for (int i = 0; i < static_cast<int>(playerNums.size()); i++) {
                if (playerRatings.at(i) >= chosenRating) {
                    cout
                        << "Player " << counter
                        << " -- Jersey number: " << playerNums.at(i)
                        << ", Rating: " << playerRatings.at(i) << endl;
                    
                    counter++;
                }
            }


        } else if (option == 'o') {
            for (int i = 0; i < static_cast<int>(playerNums.size()); i++) {
                cout
                    << "Player " << i + 1
                    << " -- Jersey number: " << playerNums.at(i)
                    << ", Rating: " << playerRatings.at(i) << endl;
            }
        }

        cout
            << endl << "MENU" << endl
            << "a - Add player" << endl
            << "d - Remove player" << endl
            << "u - Update player rating" << endl
            << "r - Output players above a rating" << endl
            << "o - Output roster" << endl
            << "q - Quit" << endl << endl
            << "Choose an option:" << endl;

        cin >> option;
    }
    
    return 0;
}
