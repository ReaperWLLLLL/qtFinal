//
// Created by Reaper on 2023/9/8.
//

#include "Bd2no.h"

Bd2no::Bd2no():Component(1){
    //插入数据
    data.insert(pair<string,double>("bd",0));
    data.insert(pair<string,double>("no1",0));
    data.insert(pair<string,double>("no2",0));
}

Bd2no::~Bd2no() {
    data.clear();
}

void Bd2no::set(string name, double value) {
    //异常处理
    try {
        data.find(name)->second = value;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void Bd2no::set(int value1, int value2, int value3) {
    //异常处理
    try {
        data.find("bd")->second = value1;
        data.find("no1")->second = value2;
        data.find("no2")->second = value3;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void Bd2no::display() {
    cout << "Bd2no:" << id << endl;
    cout << "bd: " << data.find("bd")->second << endl;
    cout << "no1: " << data.find("no1")->second << endl;
    cout << "no2: " << data.find("no2")->second << endl;
}

int Bd2no::get(const string &name) {
    try {
        return data.find(name)->second;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

