//
// Created by Алексей on 18.03.2022.
//

#ifndef INC_4_1_1_CHILD_H
#define INC_4_1_1_CHILD_H
#include "cl_base.h"

class child: public cl_base{
    string object_name;
    child* parent;
    int index = 0;
public:
    static child* root;
    vector <child*> children;
    child(string object_name, child* parent);
    void set_parent(child* parent);
    child* get_parent();
    child* get_object_by_name(string name);
    ~child();
};

#endif //INC_4_1_1_CHILD_H
