#include "cl_application.h"
cl_application::cl_application(cl_base* parent = nullptr)
{
    cl_base::root->set_parent(parent); //инициализация головного объекта
    cl_base::root->set_name("root");
    cl_base::root->children.push_back(root);
}
void cl_application::bild_tree_objects()
{
    string name1, name2;
    cin >> name1;
    cl_base* child = new cl_base(name1, nullptr); //создание головного объекта
    while (true)
    {
        cin >> name1 >> name2; //ввод наследуемого класса и наследующего
        if (name1 == name2) //условие выхода
        {
            return;
        }
        cl_base* child2 = new cl_base(name2, root->get_object_by_name(name1)); //создание дочернего класса
        child = child2;
    }
}
int cl_application::exec_app()
{
    cout << root->children[1]->get_name(); //обраща
    root->children[1]->print_tree();
    return 0;
}
