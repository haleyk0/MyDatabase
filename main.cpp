#include "functions.h"

int main(){
    string line;

    while (true){
        getline(cin, line);
        stringstream ss(line);

        string cmd;
        ss>>cmd;

        if (cmd=="EXIT"){
            break;
        }
    }

    return 0;
}