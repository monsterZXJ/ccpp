#include "Node.h"

Node::Node(int num)
{
    this->Num=num;//ctor
}


void Node::append(Node*X)
{
    (this->children)[children_number]=X;
    X->parent=this;
    children_number++;
}
int Node::count()
{
    int cont=1;int i=0;
    for(i=0;i<children_number;i++)
    {
        cont +=(this->children)[i]->count();
    }
    return cont;
}
Node*Node::getParent()
{
    return(this->parent);
}
int Node::getValue()
{
    return this->Num;
}
Node::~Node()
{
    //dtor
}
