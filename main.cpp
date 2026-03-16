#include "functions.h"

int main(){
    string line;

    while (true){
        getline(cin, line);
        stringstream ss(line);

        string cmd, key, value;
        ss>>cmd;
        if (cmd=="SET"){
            ss>>key>>value;
            //set function
        }
        else if (cmd=="GET"){
            ss>>key;
            //get function
        }
        else if (cmd=="EXIT"){
            break;
        }
    }

    return 0;
}