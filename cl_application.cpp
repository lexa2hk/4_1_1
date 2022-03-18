#include "cl_application.h"
#include "child.h"
cl_application::cl_application(child* parent = nullptr)
{
    cl_base* parent1 = parent;
    child::root->set_parent(parent1); //инициализация головного объекта
    child::root->set_name("root");
    child::root->children.push_back(root);
}
void cl_application::bild_tree_objects()
{
    string name1, name2;
    cin >> name1;
    child* child1 = new child(name1, nullptr); //создание головного объекта
    while (true)
    {
        cin >> name1 >> name2; //ввод наследуемого класса и наследующего
        if (name1 == name2) //условие выхода
        {
            return;
        }
        child* child2 = new child(name2, root->get_object_by_name(name1)); //создание дочернего класса
    }
}
int cl_application::exec_app()
{
    cout << root->children[1]->get_name(); //обращаемся к главному объекту
    root->children[1]->print_tree(); //выводим дерево рекурсивно
    return 0;
}
