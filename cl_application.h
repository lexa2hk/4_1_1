//
// Created by Алексей on 10.03.2022.
//

#ifndef INC_4_1_1_CL_APPLICATION_H
#define INC_4_1_1_CL_APPLICATION_H

#include "cl_base.h"
#include "child.h"
#include <string>
using namespace std;
class cl_application : public cl_base
{
public:
    cl_application(child* parent);
    void bild_tree_objects();
    int exec_app();
};

#endif //INC_4_1_1_CL_APPLICATION_H
