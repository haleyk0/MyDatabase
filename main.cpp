#include "functions.h"

int main(){
    loadDb();
    string line;

    while (true){
        getline(cin, line);
        stringstream ss(line);

        string cmd, key, value;
        ss>>cmd;
        if (cmd=="SET"){
            ss>>key>>value;
            setVal(key, value);
        }
        else if (cmd=="GET"){
            ss>>key;
            cout<<getVal(key)<<endl;
        }
        else if (cmd=="EXIT"){
            break;
        }
    }

    return 0;
}