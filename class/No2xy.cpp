//
// Created by Reaper on 2023/9/8.
//

#include "No2xy.h"

No2xy::No2xy() : Component(2) {
    data.insert(pair<string, double>("x", 0));
    data.insert(pair<string, double>("y", 0));
}

No2xy::~No2xy() {
    data.clear();
}

void No2xy::set(string name, double value) {
    //异常处理
    try {
        data.find(name)->second = value;//使用find函数可以保证不会插入新的键值对
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void No2xy::set(double value1, double value2) {
    //异常处理
    try {
        data.find("x")->second = value1;
        data.find("y")->second = value2;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void No2xy::display() {
    cout << "No2xy:" << id << endl;
    cout << "x: " << data.find("x")->second << endl;
    cout << "y: " << data.find("y")->second << endl;
}

double No2xy::get(const string& name) {
    try {
        return data.find(name)->second;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
};
