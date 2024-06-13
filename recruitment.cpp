// Example program
#include <iostream>
#include <string>
#include <list>



using namespace std;

string test = "8C TS KC 9H 4S 7D 2S 5D 3S AC";
//defOrder = {2, 3, 4, 5, 6, 7, 8, 9, 10-T, Jack-J, Queen-Q, King-K, Ace-A}; 
// list<int> convertOrder = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

int sumFun(int number)
    {
    int sum =0;
    for (int i = 0; i <= number; i ++) {
        // cout << i;
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        // cout << i << endl;
        // cout << "Suma: " << sum << endl;
                }
        }
        return sum;
    }
    
    
    
int poker(string input){
    cout <<input<<"\n\nP1/1: " << input[0] << "\nP1/2: "<< input[3] << "\nP1/3: "<< input[6] <<  "\nP1/4: "<< input[9] <<  "\nP1/5: "<< input[12] << "\n\nP2/1: " << input[15] << "\nP2/2: "<< input[18] << "\nP2/3: "<< input[21] <<  "\nP2/4: "<< input[24] <<  "\nP2/5: "<< input[27] <<endl;
    }


int main()
{
    // sumFun(1000);
    
    // cout << "Suma 1000: " << sumFun(1000) << endl;
    poker(test);
    // cout << convertOrder;
}