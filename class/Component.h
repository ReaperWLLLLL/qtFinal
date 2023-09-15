//
// Created by Reaper on 2023/9/8.
//

#ifndef FINALHW_COMPONENT_H
#define FINALHW_COMPONENT_H
#include "iostream"
#include "string"

using namespace std;
class Component {
protected:
    const int id;
    const int type;//0:El2no 1:Bd2no 2:No2xy
    static unsigned int existing_num;
    static unsigned int existing_num_max;
public:
    explicit Component(int a);
    Component(const Component& a);
    ~Component();
    virtual void set(string name,double value) = 0 ;
    virtual void display() = 0;
    [[nodiscard]] int get_id() const {return id;}
    //重载运算符=
    Component& operator=(const Component& a);
};

#endif //FINALHW_COMPONENT_H
