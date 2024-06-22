#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <typeinfo>
using namespace std;

enum class repRank{
    None = 0,
    OnePair = 2,
    TwoPairs = 3,
    ThreeOfAKind = 4,
    FullHouse = 7,
    FourOfAKind = 8
};

bool areConsecutive(vector<int> inputVector){
    for (int i = 1; i < inputVector.size(); ++i){
        if (inputVector[i] != inputVector[i - 1] + 1){
            return false;
        }
    }
    return true;
}

bool checkIfSingleColor(vector<int> playerColor){
        return (count(playerColor.begin(), playerColor.end(), playerColor[0]) == 5);
}

void checkHighestValue(vector<int> player1, vector<int> player2, int &player1Score, int &player2Score){
    bool winer = false;
    sort(player1.begin(), player1.end(), greater<int>());
    sort(player2.begin(), player2.end(), greater<int>());
    for (size_t i = 0; i < player1.size(); ++i){
        if (player1[i] == player2[i]){
        }
        else if (player1[i] > player2[i]){
            player1Score ++;
            break;
        }
        else if (player1[i] < player2[i]){
            player2Score ++;
            break;
        }
    }
}


void straightSinglePlayer(vector<int> player, vector<int> playerColor, int &playerScore){
    if (areConsecutive(player)){ // Straight: All cards are consecutive values.
        playerScore = 5;
        if (checkIfSingleColor(playerColor)){ // Straight Flush: All cards are consecutive values of same suit.
            playerScore = 9;
            if (player[4] == 14){ // Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
                playerScore = 10;
            }
        }
    }
}


void checkRepeatForSinglePlayer(vector<int> player, vector<int> playerColor, int &playerScore, int& counterSum,int& sumCountAndValues){
    for (int i = 0; i < player.size(); i++){
        int repeat = count(player.begin(), player.end(), player[i]);
        counterSum = counterSum + repeat;
        if (repeat > 1){
            sumCountAndValues = sumCountAndValues + (repeat * player[i]);
        }
    }

    switch (counterSum){
    case 17: //Four of a Kind: Four cards of the same value.
        playerScore = static_cast<int>(repRank::FourOfAKind);
        break;
    case 13: //Full House: Three of a kind and a pair.
        playerScore = static_cast<int>(repRank::FullHouse);
        break;
    case 11: //Three of a Kind: Three cards of the same value.
        playerScore = static_cast<int>(repRank::ThreeOfAKind);
        break;
    case 9: //Two Pairs: Two different pairs.
        playerScore = static_cast<int>(repRank::TwoPairs);
        break;
    case 7: //One Pair: Two cards of the same value.
        playerScore = static_cast<int>(repRank::OnePair);
        break;
    case 5:
        break;
    }
}

void readFile(string filePath, int &player1WinCount, int &player2WinCount, int &lineCounter){
    ifstream inputFile(filePath);
    if (inputFile.is_open()){
        int counterSum1 = 0;
        int counterSum2 = 0;
        int sumCountAndValues1 =0;
        int sumCountAndValues2 =0;
        int player1Score = 0;
        int player2Score = 0;
        map<char, int> charToIntMap;
        map<char, int> charToIntMapColor;
        charToIntMap['2'] = 2;
        charToIntMap['3'] = 3;
        charToIntMap['4'] = 4;
        charToIntMap['5'] = 5;
        charToIntMap['6'] = 6;
        charToIntMap['7'] = 7;
        charToIntMap['8'] = 8;
        charToIntMap['9'] = 9;
        charToIntMap['T'] = 10;     // Ten
        charToIntMap['J'] = 11;     // Jack
        charToIntMap['Q'] = 12;     // Queen
        charToIntMap['K'] = 13;     // King
        charToIntMap['A'] = 14;     // Ace
        charToIntMapColor['S'] = 1; // Spad
        charToIntMapColor['H'] = 2; // Heart
        charToIntMapColor['D'] = 3; // Diamond
        charToIntMapColor['C'] = 4; // Club

        vector<int> newHand;
        vector<int> newHandColor;
        string line;
        int lineCount = 1;
        string winner;

        while (getline(inputFile, line)){
            std::istringstream iss(line);
            string word;
            while (iss >> word){
                char firstChar = word[0]; // check first char from world - card
                if (charToIntMap.find(firstChar) != charToIntMap.end()){ // map card char with number from chartomap
                    newHand.push_back(charToIntMap[firstChar]);
                }
                else{
                    newHand.push_back(0);
                }

                char secChar = word[1]; // check second char froem world - color
                if (charToIntMapColor.find(secChar) != charToIntMapColor.end()){ // map color char with number from chartomap
                    newHandColor.push_back(charToIntMapColor[secChar]);
                }
                else{
                    newHandColor.push_back(0);
                }
            }
            cout << "\n\nNew hand\n";
            for (auto card : newHand){ // display cards
                cout << card << " ";
            }

            cout << "\n";
            for (auto cardColor : newHandColor){ // display color
                cout << cardColor << " ";
            }
            vector<int> player1(newHand.begin(), newHand.end() - 5);                // create single vector for player 1 Cards
            vector<int> player2(newHand.begin() + 5, newHand.end());                // create single vector for player 2 Cards
            vector<int> player1Color(newHandColor.begin(), newHandColor.end() - 5); // create single vector for player 1 Color
            vector<int> player2Color(newHandColor.begin() + 5, newHandColor.end()); // create single vector for player 2 Color
            sort(player1.begin(), player1.end());
            sort(player2.begin(), player2.end());

            checkRepeatForSinglePlayer(player1, player1Color, player1Score, counterSum1, sumCountAndValues1);
            checkRepeatForSinglePlayer(player2, player2Color, player2Score, counterSum2, sumCountAndValues2);

            if (counterSum1 == counterSum2 and sumCountAndValues1 > sumCountAndValues2){
                player1Score++;
            }
            else if (counterSum1 == counterSum2 and sumCountAndValues1 < sumCountAndValues2){
                player2Score++;
            }
            else if (counterSum1 == counterSum2 and sumCountAndValues1 == sumCountAndValues2){
                checkHighestValue(player1, player2, player1Score, player2Score);
            }

            if (player1Score < 2 or player2Score < 2){
                straightSinglePlayer(player1, player1Color, player1Score);
                straightSinglePlayer(player2, player2Color, player2Score);
                if (player1Score == player2Score){
                    checkHighestValue(player1, player2, player1Score, player2Score);
                    }
                if (player1Score < 6 or player2Score < 6){

                    if (checkIfSingleColor(player1)){
                        player1Score = 6;
                    }
                    if (checkIfSingleColor(player2)){
                        player2Score = 6;
                    }
                }
            }


            cout << "Player1 score: " << player1Score << "   " << "Player2 score: " << player2Score;
            if (player1Score > player2Score){
                cout << "\nPlayer1 - Win !";
                player1WinCount++;
            }
            else if (player1Score < player2Score){
                cout << "\nPlayer2 - Win !";
                player2WinCount++;
            }
            else{
                cout << "\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$  Breake!!!!  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
                break;
            }
            lineCounter++;
            counterSum1 = 0;
            counterSum2 = 0;
            sumCountAndValues1 =0;
            sumCountAndValues2 =0;
            newHand.clear();
            newHandColor.clear();
            player1.clear();
            player2.clear();
            player1Color.clear();
            player2Color.clear();
            player1Score = 0;
            player2Score = 0;
        }
    }
    inputFile.close();
}

int main()
{
    int player1WinCount = 0;
    int player2WinCount = 0;
    int lineCounter = 0;
    readFile("data.txt", player1WinCount, player2WinCount, lineCounter); // Problem 54
    cout << "\nplayer1WinCount: " << player1WinCount;
    cout << "\nplayer2WinCount: " << player2WinCount;
    cout << "\nsum: " << player2WinCount + player1WinCount;
    cout << "\nlineCounter: " << lineCounter;
}