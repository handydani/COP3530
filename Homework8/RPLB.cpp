// Will contain an integer T, then, T cases will follow,
// each case starts with a number N and K, being N the number of bushes and K the number of blueberries
// Teresa will pick as maximum, the next line contains N integers, each one representing the blueberries there is on the i-th bush.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<int> bushes_odd;
    vector<int> bushes_even;

    int ctr = 0;
    int sack = 0;
    int num_bushes = 0;
    int bush_temp = 0;
    int odd_sum = 0;
    int even_sum = 0;
    int scenario_num = 1;
    cin >> ctr;
    while(ctr)
    {
        cout << "ctr is "<<ctr <<"\n";

        cin >> num_bushes;
        cout << "number of bushes is "<<num_bushes <<"\n";

        cin >> sack;
        cout << "sack size is "<< sack <<"\n";


        for(int i = 0; i < num_bushes; i += 2){
            cin >> bush_temp;
            bushes_even.push_back(bush_temp);
            if(i != num_bushes - 1){
                cin >> bush_temp;
                bushes_odd.push_back(bush_temp);
            }

        }

        for (vector<int>::iterator it = bushes_odd.begin(); it != bushes_odd.end(); ++it){
            // cout << *it << "->";
            odd_sum += *it;

        }
        cout <<"\n";
        for (vector<int>::iterator it = bushes_even.begin(); it != bushes_even.end(); ++it){
            // cout << *it << "->";
            even_sum += *it;

        }
        // cout <<"\n";
        cout << "odd sum is "<< odd_sum<<"\n";
        cout << "even sum is "<< even_sum<<"\n";

        if (odd_sum > sack && even_sum > sack)
        {
            //logic to handle case in which both the even and odd sums are bigger than the sack size
        }
        else{
            if(odd_sum > even_sum && odd_sum <= sack){
                cout << "Scenario #" << scenario_num <<": " << odd_sum <<"\n";
            }
            else if (even_sum > odd_sum && even_sum <= sack){
                cout << "Scenario #" << scenario_num <<": " << even_sum <<"\n";
            }
            else{
                cout <<"error\n";
            }

        }


        scenario_num++;
        --ctr;
    }




    return 0;
}
