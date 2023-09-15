//
// Created by Reaper on 2023/9/8.
//

#ifndef FINALHW_EL2NO_H
#define FINALHW_EL2NO_H


#include <map>
#include "Component.h"

using namespace std;

class El2no : public Component {
private:
    map<string, int> data;
public:
    El2no();

    ~El2no();

    void set(string name, double value) override;

    void set(int value1, int value2, int value3);

    void display() override;

    int get(const string& name);
};


#endif //FINALHW_EL2NO_H
