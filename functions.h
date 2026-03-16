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

void setVal(string key, string value){
    for (int i=0; i<db.size(); i++){
        if (db[i].key==key){
            db[i].value=value;
            goto write;
        }
    }

    db.push_back({key, value});

    write:
        fstream file(filename, ios::app);
        file<<"SET "<<key<<" "<<value<<endl;
        file.close();
}

string getVal(string key){
    for (int i=0; i<db.size(); i++){
        if (db[i].key==key){
            return db[i].value;
        }
    }

    return "NULL";
}

#endif