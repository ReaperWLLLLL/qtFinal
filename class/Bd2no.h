//
// Created by Reaper on 2023/9/8.
//

#ifndef FINALHW_BD2NO_H
#define FINALHW_BD2NO_H

#include <map>
#include "Component.h"

using namespace std;

class Bd2no : public Component {
private:
    map<string, int> data;
public:
    Bd2no();

    ~Bd2no();

    void set(string name, double value) override;

    void set(int value1, int value2, int value3);

    void display() override;

    int get(const string& name);
};


#endif //FINALHW_BD2NO_H
