//
// Created by Reaper on 2023/9/8.
//

#include "Component.h"

unsigned int Component::existing_num = 0;
unsigned int Component::existing_num_max = 0;

Component::Component(int a) : id(existing_num_max++), type(a) {
    existing_num++;
}

Component::~Component() {
    existing_num--;
}

Component::Component(const Component &a) : id(a.id), type(a.type){
    existing_num++;
    existing_num_max++;
}

Component &Component::operator=(const Component &a) {
    //通过强制类型转换来实现const的赋值
    const_cast<int&>(id) = a.id;
    const_cast<int&>(type) = a.type;
    return *this;
}



