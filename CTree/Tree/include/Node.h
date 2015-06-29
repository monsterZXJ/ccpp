#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(int);
        void append(Node*);
        int count();
        Node* getParent();
        int children_number=0;
        int getValue();
        virtual ~Node();
    protected:
    private:
        int Num;
        Node*children[10];

        Node*parent;
};

#endif // NODE_H
