//
// Created by Reaper on 2023/9/8.
//

#ifndef FINALHW_NO2XY_H
#define FINALHW_NO2XY_H


#include <map>
#include "Component.h"

class No2xy : public Component {
private:
    map<string, double> data;
public:
    No2xy();

    ~No2xy();

    void set(string name, double value) override;

    void set(double value1, double value2);

    double get(const string& name);

    void display() override;
};


#endif //FINALHW_NO2XY_H
