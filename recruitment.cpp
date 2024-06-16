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

string test = "8C TS KC 9H 4S 7D 2S 5D 3S AC";
// defOrder = {2, 3, 4, 5, 6, 7, 8, 9, 10-T, Jack-J, Queen-Q, King-K, Ace-A}; 
// list<int> convertOrder = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};


    // list<int> myList;
    // int value = 30;
    // if(find(myList.begin(), myList.end(), value) != myList.end()){
    //     cout << "znalazlem " << value << " w liscie";
    // }
    // else{
    //     cout << "nie znalazlem " << value << " w liscie";

    // }

int checkHighestValue(vector <int> player1, vector <int> player2){
      sort(player1.begin(), player1.end(), greater<int>());
        sort(player2.begin(), player2.end(), greater<int>());
        for(size_t i = 0; i < player1.size(); ++i){
            if(player1[i]==player2[i]){
            cout << "\nSprawdzam karty nr: "<< i << " gracz 1: " << player1[i] << " gracz 2: " << player2[i] << " - Cards are equal";
            }
            else if (player1[i] > player2[i])
            {
                cout << "\nSprawdzam karty nr: "<< i << " gracz 1: " << player1[i] << " gracz 2: " << player2[i] << " - Player1 Win!";
            }
            else if (player1[i] < player2[i])
            {
                cout << "\nSprawdzam karty nr: "<< i << " gracz 1: " << player1[i] << " gracz 2: " << player2[i] << " - Player2 Win!";
            }

        }
        return 0;
}    

void checkRepeat(vector<int> player1, vector<int> player2){
    int counterSum1=0;
    int sumCountAndValues1 = 0;
    int counterSum2=0;
    int sumCountAndValues2 = 0;
    // cout << "\nplayer1.size() : " << player1.size();
    cout << "\ncheckPair for Player1: ";
     for(int i = 0; i<player1.size(); i++){
        int repeat = count(player1.begin(), player1.end(), player1[i]);
        counterSum1 = counterSum1+repeat;
        if(repeat > 1){
            sumCountAndValues1 = sumCountAndValues1 + (repeat*player1[i]);
        }
        // cout <<  "\nsumCountAndValues1 = " << sumCountAndValues1 << " Repeat * " << repeat << " player1[i] " << player1[i];
        cout << repeat;

        // cout << "\n" << counterSum1;
       }
       cout << "\nsumCountAndValues1 : " << sumCountAndValues1;
    

            cout << "\ncounterSum1: "<<counterSum1; //17 - Four of a Kind, 13 - Full House, 11 - Three of a Kind, 7 - One Pair, 9 - Two Pairs, 5 no repeat
            switch (counterSum1){
                case 17: cout << "\nFour of a Kind";
                break;
                case 13: cout << "\nFull House";
                break;
                case 11: cout << "\nThree of a Kind";
                break;
                case 9: cout << "\nTwo Pairs";
                break;
                case 7: cout << "\nOne Pair";
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
        // cout <<  "\nsumCountAndValues1 = " << sumCountAndValues1 << " Repeat * " << repeat << " player1[i] " << player1[i];
        cout << repeat;

        // cout << "\n" << counterSum1;
       }
       cout << "\nsumCountAndValues2 : " << sumCountAndValues2;
    

            cout << "\ncounterSum2: "<<counterSum2; //17 - Four of a Kind, 13 - Full House, 11 - Three of a Kind, 7 - One Pair, 9 - Two Pairs, 5 no repeat
            switch (counterSum2){
                case 17: cout << "\nFour of a Kind";
                break;
                case 13: cout << "\nFull House";
                break;
                case 11: cout << "\nThree of a Kind";
                break;
                case 9: cout << "\nTwo Pairs";
                break;
                case 7: cout << "\nOne Pair";
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
                checkHighestValue(player1, player2);
            }
            
            

}
int sumFun(int number)
    {
    int sum =0;
    for (int i = 0; i <= number; i ++) {
        // cout << i;
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        cout << i << endl;
        cout << "Suma: " << sum << endl;
                }
        }
        return sum;
    }
    
    
    
void poker(string input){ //display and count cards for each player
    cout <<input<<"\n\nP1/1: " << input[0] << "\nP1/2: "<< input[3] << "\nP1/3: "<< input[6] <<  "\nP1/4: "<< input[9] <<  "\nP1/5: "<< input[12] << "\n\nP2/1: " << input[15] << "\nP2/2: "<< input[18] << "\nP2/3: "<< input[21] <<  "\nP2/4: "<< input[24] <<  "\nP2/5: "<< input[27] <<endl;
     }

void readFile(string filePath){ //read date from file
    ifstream inputFile(filePath);
    if(inputFile.is_open()){

        map<char, int> charToIntMap;
    charToIntMap['2'] = 2;
    charToIntMap['3'] = 3;
    charToIntMap['4'] = 4;
    charToIntMap['5'] = 5;
    charToIntMap['6'] = 6;
    charToIntMap['7'] = 7;
    charToIntMap['8'] = 8;
    charToIntMap['9'] = 9;
    charToIntMap['T'] = 10;
    charToIntMap['J'] = 11;
    charToIntMap['Q'] = 12;
    charToIntMap['K'] = 13;
    charToIntMap['A'] = 14;
    charToIntMap['S'] = 101;
    charToIntMap['H'] = 102;
    charToIntMap['D'] = 103;
    charToIntMap['C'] = 104;

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
                char firstChar = word[0];
                if(charToIntMap.find(firstChar) != charToIntMap.end()){
                    results.push_back(charToIntMap[firstChar]);
                }else{
                    results.push_back(0);
                } 

                char secChar = word[1];
                if(charToIntMap.find(secChar) != charToIntMap.end()){
                    resultsColor.push_back(charToIntMap[secChar]);
                }else{
                    resultsColor.push_back(0);
                }
            }
            cout<<"\n\nNew hand\n";
           for (const auto& res : results){ //display cards
            cout << "\n" <<res << " ";
                }
            for (const auto& resColor : resultsColor){ //display cards
                cout << "\n" << resColor << " ";
                }
        // cout << "results size :" << results.size();

        // sort(results.begin()+5, results.end());//sort values in results from 5 to 10 
        // sort(results.begin(), results.end()-5);//sort values in results from 0 to 5 
        // partial_sort(results.begin()+5, results.begin()+10, results.end());
        vector <int> player1(results.begin(), results.end()-5);//create single vector for player 1
        vector <int> player2(results.begin()+5, results.end());//create single vector for player 2
        sort(player1.begin(), player1.end());
        sort(player2.begin(), player2.end());

        for (const auto& p1 : player1){//display vector for player 1
            cout << "\nP1:" << p1;
        }
        for (const auto& p2 : player2){//display vector for player 1
            cout << "\nP2:" << p2;
        }
        /*
        TODO One Pair: Two cards of the same value. - DONE
        TODO draw  - DONE
        */
       checkRepeat(player1, player2);

      

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
        // if(player1[4]>player2[4]){
        //     winner = "Player1";
        // }
        // else if (player1[4]<player2[4]){
        //     winner = "Player2";
        // }

        
        
        // cout << "\nHighest card Player 1: " << player1[4]<< "\nHighest card Player 2: " <<player2[4] << "\n" << winner << " wins!\n"; 

      

        results.clear();
        player1.clear();
        player2.clear();
        
        }
        
        
    
    }
    
    inputFile.close();
   
}



int main(){
    // sumFun(1000);
    // cout << "Suma 1000: " << sumFun(1000) << endl;
    // poker(test);
    // cout << convertOrder;
    
  

    readFile("data_test.txt");
        
}