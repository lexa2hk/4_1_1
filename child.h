//
// Created by Алексей on 18.03.2022.
//

#ifndef INC_4_1_1_CHILD_H
#define INC_4_1_1_CHILD_H
#include "cl_base.h"

class child: public cl_base{
    string object_name;
    cl_base* parent;
    int index = 0;
public:
    using cl_base::cl_base;
};

#endif //INC_4_1_1_CHILD_H
