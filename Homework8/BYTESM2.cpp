#include <iostream>
#include <vector>
#include <string>
using namespace std;
int max(int a, int b, int c);
// void print( int tiles[][]);
int max(int a, int b, int c)
{
    int m = a;
    if(b > m) m = b;
    if(c > m) m = c;
    return m;
}

int main()
{
    int testcases = 0;
    int rows = 0;
    int cols = 0;
    cin >> testcases;

    while(testcases)
    {
        cin >> rows;
        cin >> cols;
        cols += 2; // 0 buffers on the left and right

        int tiles[rows][cols];

        //INITIALIZE THE ARRAY WITH CONTENTS AND WITH THE BUFFER
        for (int n=0; n<rows; n++){
            for (int m=0; m<cols; m++){
                if(m == 0 || m == cols - 1)// 0 buffers on the left and right
                    tiles[n][m] = 0;
                else cin >> tiles[n][m];
            }
        }

        //PRINT
        // for (int n=0; n<rows; n++){
        //     for (int m=0; m<cols; m++)
        //         cout << tiles[n][m] << " ";
        //     cout << "\n";
        // }
        for(int i = rows - 2; i >= 0; --i){
            for(int j = 1; j < cols - 1; ++j){
                tiles[i][j] += max(tiles[i+1][j-1], tiles[i+1][j], tiles[i+1][j+1]);
            }
        }
        //PRINT
        // for (int n=0; n<rows; n++){
        //     for (int m=0; m<cols; m++)
        //         cout << tiles[n][m] << " ";
        //     cout << "\n";
        // }
        int max = -1;
        for( int i = 0; i< cols; ++ i){
            if(tiles[0][i] > max)
                max = tiles[0][i];
        }

        cout << max <<"\n";

        --testcases;
    }


    return 0;
}
