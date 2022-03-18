//
// Created by Алексей on 18.03.2022.
//

#include "child.h"
child::child(string object_name, child* parent){
    this->object_name = object_name; //присвоение имени
    if (parent == nullptr)
    {
        set_parent(this->root); //если родителя нет
        (this->parent)->children.push_back(this); // пушим детей
    }
    else
    {
        this->parent = parent; //иначе заполняем поле родителя
        parent->children.push_back(this); //добавляем в список детей объекта-родителя
    }
    children.push_back(this); //добвляем в свой список детей как головной объект
    index = (this->parent)->children.size() - 1; //индекс ребенка в дереве
}

void child::set_parent(child *parent) {
    this->parent = parent;
}

child* child::get_parent(){
    return parent;
}

child* child::get_object_by_name(string name){
    child* val = nullptr;
    bool chek = false;
    for (size_t i = 0; i < children.size(); i++){
        val = children[i];

        if (children[i]->get_name() == name)
        {
            chek = true;
            return children[i];
        }
    }
    for (size_t i = 1; i <children.size(); i++) //поиск рекурсивно в наследниках наследников
    {
        val = (children[i]->get_object_by_name(name));
        if ((children[i]->get_object_by_name(name))->get_name() == name)
        {
            return (children[i]->get_object_by_name(name));
        }
    }
return val;
}


child::~child() {

}

