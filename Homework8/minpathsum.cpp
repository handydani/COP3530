#include <iostream>
#include <vector>
#include <string>
using namespace std;
int minPathSum(int **grid, int rows, int cols);
//
int minPathSum(int **grid, int rows, int cols)
{
    //pad the array with +infinity
    //corner cases

    for(int i = 1; i < rows -1 ; ++i){
        for(int j = 1; j < cols - 1; ++j){
            grid[i][j] = min(grid[i-1][j], grid[i][j-1]); //check the value above and to the left because you can only go below and to the right
        }
    }

    return grid[rows - 2][cols - 2];
}


int main()
{

    int rows = 0;
    int cols = 0;

        cin >> rows;
        cin >> cols;
        cols += 2; // 0 buffers on the left and right
        rows += 2;
        int tiles[rows][cols];

        //INITIALIZE THE ARRAY WITH CONTENTS AND WITH THE BUFFER
        for (int n=0; n<rows; n++){

            for (int m=0; m<cols; m++){
                if(m == 0 || m == cols - 1 || n == 0 || n == rows - 1)// 0 buffers on the left and right
                    tiles[n][m] = 0;
                else cin >> tiles[n][m];
            }
        }



        //PRINT
        for (int n=0; n<rows; n++){
            for (int m=0; m<cols; m++)
                cout << tiles[n][m] << " ";
            cout << "\n";
        }

        cout << minPathSum(&tiles[0][0], rows, cols);


        return 0;

}
