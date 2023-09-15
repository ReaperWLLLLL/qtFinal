//
// Created by Reaper on 2023/9/8.
//

#include "El2no.h"

//构造时修改type
El2no::El2no() : Component(0) {
    data.insert(pair<string, double>("no1", 0));
    data.insert(pair<string, double>("no2", 0));
    data.insert(pair<string, double>("no3", 0));
}


El2no::~El2no() {
    data.clear();
}

void El2no::set(string name, double value) {
    //异常处理
    try {
        data.find(name)->second = value;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void El2no::set(int value1, int value2, int value3) {
    //异常处理
    try {
        data.find("no1")->second = value1;
        data.find("no2")->second = value2;
        data.find("no3")->second = value3;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void El2no::display() {
    cout << "El2no:" << id << endl;
    cout << "no1: " << data.find("no1")->second << endl;
    cout << "no2: " << data.find("no2")->second << endl;
    cout << "no3: " << data.find("no3")->second << endl;
}

int El2no::get(const string &name) {
    try {
        return data.find(name)->second;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
};

