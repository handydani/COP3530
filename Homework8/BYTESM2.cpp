#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<string> inputs;

    int testcases = 0;
    int rows = 0;
    int cols = 0;
    cin >> testcases;

    while(testcases){
        cin >> rows;
        cin >> cols;

        int tiles[rows][cols];
        int stones[rows];

        for (int n=0; n<rows; n++)
        {
            for (int m=0; m<cols; m++)
            {
              cin >> tiles[n][m];
            }
        }
        // getline(cin, temp);
        // inputs.push_back(temp);
        int max = -1;
        //find the largest num in the first row
        for (int m=0; m<cols; m++)
        {
            if(tiles[0][m] > max)
                max = tiles[0][m];
        }

        for (int n=0; n<rows; n++)
        {
            for (int m=0; m<cols; m++)
            {
              stones[n];
            }
        }
        --testcases;
    }


    return 0;
}
