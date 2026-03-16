//hjk0056

#ifndef FUNC
#define FUNC

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Pair{
    string key;
    string value;
};

vector<Pair>db;

string filename="data.db";

void setVal(string key, string value, bool write=true){
    for (int i=0; i<db.size(); i++){
        if (db[i].key==key){
            if (db[i].value==value) return;
            db[i].value=value;
            if (write){
                ofstream file(filename, ios::app);
                file <<"SET " << key << " " << value << endl;
                file.close();
            }
            return;
        }
    }

    db.push_back({key, value});
    if (write){
        ofstream file(filename, ios::app);
        file<<"SET "<<key<<" "<<value<<endl;
        file.close();
    }
}

string getVal(string key){
    for (int i=0; i<db.size(); i++){
        if (db[i].key==key){
            return db[i].value;
        }
    }

    return "NULL";
}

void loadDb() {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        string cmd, key, value;
        stringstream ss(line);

        ss>>cmd>>key>>value;

        if (cmd=="SET") {
            setVal(key, value, false);
        }
    }

    file.close();
}

#endif