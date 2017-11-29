#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isValidNum(string num);
int main(){
    vector<string> inputs;
    int num = 0;
    string temp = "";

    while(cin){
        getline(cin, temp);
        num = stoi( temp );
        if(!num)
            break;
        inputs.push_back(temp);
    }

    for (vector<string>::iterator it = inputs.begin(); it != inputs.end(); ++it)
    {
        for(int i = 0; i < it->size(); ++i)
        {
            // if(isValidNum(*it.substr(i, 1))){
            //     //add to list of possible solutions
            // }
            // if (isValidNum(*it.substr(i, 2))){
            //     //add to list of possible solutions
            // }
        }
    }




    cout << '\n';

    return 0;

}


bool isValidNum(string num){

    num = stoi( num );

    return ((stoi(num) <= 26) && (stoi(num) >= 1));
}
