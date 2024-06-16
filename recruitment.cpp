// Example program
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

bool areConsecutive(vector<int> inputVector){
    cout << "\n----------------->>>>>  areConsecutive fun -------->>>>>>> ";
    for(int i =1; i < inputVector.size(); ++i){
        if (inputVector[i] != inputVector[i-1]+1){
            return false;
        }
    }
    return true;
}

void checkIfColor(vector <int> player1Color, vector <int> player2Color, int& player1Score, int& player2Score){
    cout << "\n----------------->>>>>  checkIfColor fun -------->>>>>>> ";
    if(count(player1Color.begin(), player1Color.end(), player1Color[0]) == 5){
        cout << "Player1 Color!";
        player1Score = 6;
    }
    if(count(player2Color.begin(), player2Color.end(), player2Color[0]) == 5){
        cout << "Player2 Color!";
        player2Score = 6;
    }
}

int checkIfSingleColor(vector <int> playerColor){
    cout << "\n----------------->>>>>  checkIfSingleColor fun -------->>>>>>> ";
    if(count(playerColor.begin(), playerColor.end(), playerColor[0]) == 5){
        cout << "Player1 Color!";
        return true;
    }
    return false;
}

void straight(vector <int> player1, vector <int> player2, vector <int> player1Color, vector <int> player2Color, int& player1Score, int& player2Score){
    cout << "\n----------------->>>>>  straight fun -------->>>>>>> ";
    if(areConsecutive(player1)){ // Straight: All cards are consecutive values.
        cout << "\nplayer1 Straight !";
        player1Score = 5;
        if(checkIfSingleColor(player1Color)){ //Straight Flush: All cards are consecutive values of same suit.
            cout << "\nplayer1 Straight Flush !";
            player1Score = 9;
                if(player1[4]==14){ // Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
                    cout << "\nplayer1 Royal Flush !";
                    player1Score = 10;
                    }
                }
    }
    if(areConsecutive(player2)){ // Straight: All cards are consecutive values.
        cout << "\nplayer2 Straight !";
        player2Score = 5;
        if(checkIfSingleColor(player2Color)){ //Straight Flush: All cards are consecutive values of same suit.
            cout << "\nplayer2 Straight Flush !";
            player2Score = 9;
                if(player2[4]==14){ // Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
                    cout << "\nplayer2 Royal Flush !";
                    player2Score = 10;
                    }
                }
    }
}



void checkHighestValue(vector <int> player1, vector <int> player2, int& player1Score, int& player2Score){
    cout << "\n----------------->>>>>  checkHighestValue fun -------->>>>>>> ";
      sort(player1.begin(), player1.end(), greater<int>());
        sort(player2.begin(), player2.end(), greater<int>());
        for(size_t i = 0; i < player1.size(); ++i){
            if(player1[i]==player2[i]){
            cout << "\nI'm checking the card number "<< i << " player 1: " << player1[i] << " player 2: " << player2[i] << " - Cards are equal";
            }
            else if (player1[i] > player2[i])
            {
                player1Score =+1;
                cout << "\nI'm checking the card number "<< i << " player 1: " << player1[i] << " player 2: " << player2[i] << " - Player1 Win!";
            }
            else if (player1[i] < player2[i])
            {
                player2Score =+1;
                cout << "\nI'm checking the card number "<< i << " player 1: " << player1[i] << " player 2: " << player2[i] << " - Player2 Win!";
            }
        }
}    

void checkRepeat(vector <int> player1, vector <int> player2, vector <int> player1Color, vector <int> player2Color, int& player1Score, int& player2Score){
    cout << "\n----------------->>>>>  checkRepeat fun -------->>>>>>> ";
    int counterSum1=0;
    int sumCountAndValues1 = 0;
    int counterSum2=0;
    int sumCountAndValues2 = 0;
    cout << "\ncheckPair for Player1: ";
     for(int i = 0; i<player1.size(); i++){
        int repeat = count(player1.begin(), player1.end(), player1[i]);
        counterSum1 = counterSum1+repeat;
        if(repeat > 1){
            sumCountAndValues1 = sumCountAndValues1 + (repeat*player1[i]);
        }
        cout << repeat;
       }
       cout << "\nsumCountAndValues1 : " << sumCountAndValues1;
    cout << "\ncounterSum1: "<<counterSum1; //17 - Four of a Kind, 13 - Full House, 11 - Three of a Kind, 7 - One Pair, 9 - Two Pairs, 5 no repeat
    switch (counterSum1){
        case 17: cout << "\nFour of a Kind";
        player1Score = 8;
        break;
        case 13: cout << "\nFull House";
        player1Score = 7;
        break;
        case 11: cout << "\nThree of a Kind";
        player1Score = 4;
        break;
        case 9: cout << "\nTwo Pairs";
        player1Score = 3;
        break;
        case 7: cout << "\nOne Pair";
        player1Score = 2;
        break;
        case 5: cout << "\nNo repeat";
        break;
    }
    cout << "\ncheckPair for Player2: ";
     for(int i = 0; i<player2.size(); i++){
        int repeat = count(player2.begin(), player2.end(), player2[i]);
        counterSum2 = counterSum2+repeat;
        if(repeat > 1){
            sumCountAndValues2 = sumCountAndValues2 + (repeat*player2[i]);
        }
        cout << repeat;
       }
       cout << "\nsumCountAndValues2 : " << sumCountAndValues2;
    cout << "\ncounterSum2: "<<counterSum2; //17 - Four of a Kind, 13 - Full House, 11 - Three of a Kind, 7 - One Pair, 9 - Two Pairs, 5 no repeat
    switch (counterSum2){
        case 17: cout << "\nFour of a Kind";
        player2Score = 8;
        break;
        case 13: cout << "\nFull House";
        player2Score = 7;
        break;
        case 11: cout << "\nThree of a Kind";
        player2Score = 4;
        break;
        case 9: cout << "\nTwo Pairs";
        player2Score = 3;
        break;
        case 7: cout << "\nOne Pair";
        player2Score = 2;
        break;
        case 5: cout << "\nNo repeat";
        break;
    }
    if(counterSum1 > counterSum2){
        cout << "\nPlayer1 win!";
    }else if (counterSum1 < counterSum2)
    {
        cout << "\nPlayer2 win!";
    }else if (counterSum1 == counterSum2 and sumCountAndValues1 > sumCountAndValues2)
    {
        cout << "\nPlayer1 win!";
    }else if (counterSum1 == counterSum2 and sumCountAndValues1 < sumCountAndValues2)
    {
        cout << "\nPlayer2 win!";
    }else if (counterSum1 == counterSum2 and sumCountAndValues1 == sumCountAndValues2)
    {
        cout << "\ncheck highest card";
        checkHighestValue(player1, player2, player1Score, player2Score);
    }
            
            

}
int sumFun(int number)
    {
    int sum =0;
    for (int i = 0; i <= number; i ++) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        cout << i << endl;
        cout << "Sum: " << sum << endl;
                }
        }
        return sum;
    }

void readFile(string filePath, int&player1WinCount, int&player2WinCount){ //read date from file
    ifstream inputFile(filePath);
    if(inputFile.is_open()){

        int player1Score =0;
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
            charToIntMap['T'] = 10; // Ten
            charToIntMap['J'] = 11; // Jack
            charToIntMap['Q'] = 12; // Queen
            charToIntMap['K'] = 13; // King
            charToIntMap['A'] = 14; // Ace
            charToIntMapColor['S'] = 1;    // Spad
            charToIntMapColor['H'] = 2;    // Heart
            charToIntMapColor['D'] = 3;    // Diamond
            charToIntMapColor['C'] = 4;    // Club

        vector<int> results;
        vector<int> resultsColor;
        string line;
        int lineCount = 1;
        string winner;
        
        while (getline(inputFile, line))
        {
            std::istringstream iss(line);
            string word;
            while (iss>>word)
            {
                char firstChar = word[0]; //check first char from world - card
                if(charToIntMap.find(firstChar) != charToIntMap.end()){ // map card char with number from chartomap
                    results.push_back(charToIntMap[firstChar]);
                }else{
                    results.push_back(0);
                } 

                char secChar = word[1]; // check second char froem world - color
                if(charToIntMapColor.find(secChar) != charToIntMapColor.end()){// map color char with number from chartomap
                    resultsColor.push_back(charToIntMapColor[secChar]);
                }else{
                    resultsColor.push_back(0);
                }
            }
            cout<<"\n\nNew hand\n";
        //    for (const auto& res : results){ //display cards
        //     cout <<res << " ";
        //         }

        //     cout <<"\n";
        //     for (const auto& resColor : resultsColor){ //display color
        //         cout << resColor << " ";
        //         }
        vector <int> player1(results.begin(), results.end()-5);//create single vector for player 1 Cards
        vector <int> player2(results.begin()+5, results.end());//create single vector for player 2 Cards
        vector <int> player1Color(resultsColor.begin(), resultsColor.end()-5);//create single vector for player 1 Color 
        vector <int> player2Color(resultsColor.begin()+5, resultsColor.end());//create single vector for player 2 Color
        sort(player1.begin(), player1.end());
        sort(player2.begin(), player2.end());

        // for (const auto& p1 : player1){//display vector for player 1
        //     cout << "\nP1:" << p1;
        // }
        // for (const auto& p2 : player2){//display vector for player 1
        //     cout << "\nP2:" << p2;
        // }
        /*
        TODO One Pair: Two cards of the same value. - DONE
        TODO draw  - DONE
        */
       checkRepeat(player1, player2, player1Color, player2Color, player1Score, player2Score);
       if(player1Score ==0 or player2Score == 0){
        cout<< "\nplayer1Score == " << player1Score << " and "<< "player2Score == " << player2Score;

       straight(player1, player2, player1Color, player2Color, player1Score, player2Score);

       if(player1Score <6 or player2Score < 6){
       checkIfColor(player1Color, player2Color, player1Score, player2Score);
       }
       }
        if(player1Score>player2Score){
            player1WinCount++;
        }
        if(player1Score<player2Score){
            player2WinCount++;
        }
        cout<<"\nplayer1WinCount: "<<player1WinCount;
        cout<<"\nplayer2WinCount: "<<player2WinCount;

        /*
        TODO Two Pairs: Two different pairs.- DONE
        TODO draw - DONE
        */

        /*
        TODO Three of a Kind: Three cards of the same value.- DONE
        TODO draw - DONE
        */

        /*
        TODO Straight: All cards are consecutive values.
        TODO draw
        */

        /*
        TODO Flush: All cards of the same suit.
        TODO draw
        */

        /*
        TODO Full House: Three of a kind and a pair.- DONE
        TODO draw - DONE
        */
       
        /*
        TODO Four of a Kind: Four cards of the same value.- DONE
        TODO draw - DONE
        */

        /*
        TODO Straight Flush: All cards are consecutive values of same suit.
        TODO draw
        check if we have max number - 4 == nim number
        if max number == 14 and abowe we have Royal Flush
        */

        /*
        TODO Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
        TODO draw
        check if we have max number - 4 == nim number
        if max number == 14 and abowe we have Royal Flush
        */
        /*
        TODO High Card: Highest value card. - DONE
        TODO draw - DONE
        */
        /*check witch player win if there is no figures
        High Card: Highest value card.
        
        we need to use loop - two player can have same highest card, than we need check second one and so on..... 
        // */
        cout << "\nplayer1Score: "<<player1Score<< "\nplayer2Score: "<< player2Score; 
        results.clear();
        player1.clear();
        player2.clear();
        }
    }
    inputFile.close();
}


int main(){
    int player1WinCount = 0;
    int player2WinCount = 0;
    // sumFun(1000); //Problem 1
    // cout << "Suma 1000: " << sumFun(1000) << endl; //Problem 1
    // cout << convertOrder;
    readFile("data.txt", player1WinCount, player2WinCount); //Problem 54
    cout  << "\nplayer1WinCount: "<<player1WinCount;
    cout  << "\nplayer2WinCount: "<<player2WinCount;
    cout  << "\nsum: "<<player2WinCount+player1WinCount;
        
}