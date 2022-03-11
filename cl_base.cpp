#include "cl_base.h"
#include <string>
cl_base* cl_base::root = new cl_base();
cl_base::cl_base()
{
    parent = nullptr;
}
cl_base::cl_base(string object_name, cl_base* parent)
{
    this->object_name = object_name; //присвоение имени
    if (parent == nullptr)
    {
        set_parent(root); //если родителя нет
        (this->parent)->children.push_back(this); // пушим детей
    }
    else
    {
        this->parent = parent; //иначе заполняем поле родителя
        parent->children.push_back(this); //добавляем в список детей родителя
    }
    children.push_back(this); //добвляем в свой список детей
    index = (this->parent)->children.size() - 1; //индекс ребенка в дереве
}
void cl_base::set_name(string name)
{
    this->object_name = name; //присвоение имени
}
void cl_base::set_parent(cl_base* parent) //установление родителя
{
    this->parent = parent;
}
///
cl_base* cl_base::get_parent() //вернуть родительский класс
{
    return parent;
}
///
string cl_base::get_name() //вернуть имя класса
{
    return object_name;
}
cl_base* cl_base::get_object_by_name(string name)
{
    cl_base* val = nullptr;
    bool chek = false;
    for (size_t i = 0; i < children.size(); i++)
    {
        val = children[i];

        if (children[i]->get_name() == name)
        {
            chek = true;
            return children[i];
        }
    }
    for (size_t i = 1; i <children.size(); i++)
    {
        val = (children[i]->get_object_by_name(name));
        if ((children[i]->get_object_by_name(name))->get_name() ==
            name)
        {
            return (children[i]->get_object_by_name(name));
        }
    }
    return val;
}
void cl_base::print_tree()
{
    for (int i = 0; i < children.size(); i++)
    {
        if (i == 0)
            cout << endl;
        cout << children[i]->get_name();
        if(i+1 < children.size())
            cout << " ";
    }
    for (size_t i = 1; i < children.size(); i++)
    {
        if (children[i]->children.size() > 1)
        {
            children[i]->print_tree();
        }
    }
}
cl_base::~cl_base()
{
}