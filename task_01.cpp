#include <iostream>
using namespace std;

int sumFun(int number)
    {
    int sum =0;
    for (int i = 0; i <= number; i ++) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        // cout << i;
        // cout << "Sum: " << sum;
                }
        }
        return sum;
    }


int main(){
    // sumFun(1000); //Problem 1
    cout << "Suma 1000: " << sumFun(1000) << endl; //Problem 1
    // cout << convertOrder;
        
}