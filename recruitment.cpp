// Example program
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>




using namespace std;

string test = "8C TS KC 9H 4S 7D 2S 5D 3S AC";
// defOrder = {2, 3, 4, 5, 6, 7, 8, 9, 10-T, Jack-J, Queen-Q, King-K, Ace-A}; 
// list<int> convertOrder = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

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

        vector<int> results;
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
            }
            cout<<"\n\nNew hand\n";
           for (const auto& res : results){ //display cards
            cout << res << " ";
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
        One pair
        */

        /*
        Two pair
        */

        /*
        Three
        */

        /*
        Straight
        */

        /*
        Flush
        */

        /*
        Full house
        */

        /*
        Straight Flush
        check if we have max number - 4 == nim number
        if max number == 14 and abowe we have Royal Flush
        */

        /*
        SRoyal Flush
        check if we have max number - 4 == nim number
        if max number == 14 and abowe we have Royal Flush
        */

        /*check witch player win if there is no figures
        High Card: Highest value card.*/
        if(player1[4]>player2[4]){
            winner = "Player1";
        }
        else if (player1[4]<player2[4])
        {
            winner = "Player2";
        }
        results.clear();
        player1.clear();
        player2.clear();
        
        cout << "\nHighest card Player 1: " << player1[4]<< "\nHighest card Player 2: " <<player2[4] << "\n" << winner << " wins!\n"; 
        }
        
        
    
    }
    
    inputFile.close();
   
}



int main()
{
    // sumFun(1000);
    // cout << "Suma 1000: " << sumFun(1000) << endl;
    // poker(test);
    // cout << convertOrder;
    readFile("data_test.txt");
        
}