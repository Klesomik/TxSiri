#ifndef Node_h

#define Node_h

#include "Tools.h"

class Node
{
    private:
        string key_;

        Node *parent_, *left_, *right_;

        bool alive_;

        Node (const Node& from);

        Node& operator = (const Node& from);

    public:
        Node (const string& value);
        ~Node ();

        Node* insertLeft (const string& value);
        Node* insertRight (const string& value);

        Node* insertLeft (Node* example);
        Node* insertRight (Node* example);

        void eraseNode ();
        void eraseSubTree ();

        bool ok ();
        void dump (FILE* out = stdout);

        Node* getFirst (Node* example);

        const string& key () const;
        Node* right () const;
        Node* left () const;
        Node* parent () const;

        string& key ();
        Node*& right ();
        Node*& left ();
        Node*& parent ();
};

Node :: Node(const string& value):
    key_   (value),
    parent_  (nullptr),
    left_  (nullptr),
    right_ (nullptr),
    alive_ (true)
    { /*DUMP (4, "Constructor\n");*/ }


Node :: ~Node()
{
    if(!alive_)
        return;

    alive_ = false;

    delete left_;
           left_ = nullptr;

    delete right_;
           right_ = nullptr;
}


Node* Node :: insertLeft(const string& value)
{
    Node* add_element = new Node(value);

    return insertLeft (add_element);
}


Node* Node :: insertRight(const string& value)
{
    Node* add_element = new Node(value);

    return insertRight (add_element);
}


Node* Node :: insertLeft(Node* example)
{
    left_ = example;
            example -> parent_ = this;

    return example;
}


Node* Node :: insertRight(Node * example)
{
    right_ = example;
             example -> parent_ = this;

    return example;
}


void Node :: eraseNode()
{
    if(left_)
        left_ -> parent_ = parent_;

    if(right_)
        right_ -> parent_ = parent_;

    //key_    = POISON;
    //parent_ = POISON;
    //left_   = POISON;
    //right_  = POISON;
}


void Node :: eraseSubTree()
{
    delete this;
}


bool Node :: ok()
{
    if(this == nullptr || (this == (Node *) POISON))
        return false;

    if(IsPoison(parent_) || IsPoison(left_) || IsPoison(right_))
        return false;

    if(parent_)
    {
       if(IsPoison(parent_ -> parent_) || IsPoison(parent_ -> left_) || IsPoison(parent_ -> right_))
           return false;
    }

    if(left_)
    {
       if(IsPoison(left_ -> parent_) || IsPoison(left_ -> left_) || IsPoison(left_ -> right_))
           return false;
    }

    if(right_)
    {
       if(IsPoison(right_ -> parent_) || IsPoison(right_ -> left_) || IsPoison(right_ -> right_))
           return false;
    }

    if(parent_ && ((parent_ -> left_ != this) && (parent_ -> right_ != this)))
        return false;

    if(right_ && (right_ -> parent_ != this))
        return false;

    if(left_ && (left_ -> parent_ != this))
        return false;

    return true;
}


void Node :: dump(FILE* out /* = stdout */)
{
    fprintf(out, "\n=============dump=============\n");

    fprintf(out, "Node (%s) [this = %p][", ok()? "ok" : "ERROR", this);
    fprint(out, key_);
    fprintf(out, "]\n");

    fprintf(out, "    prev = %p;\n", parent_);
    fprintf(out, "    left = %p; right = %p;\n", left_, right_);

    fprintf(out, "==============================\n\n");
}


Node* Node :: getFirst(Node* example)
{
    Node* ptr_search = example;

    while(ptr_search -> parent_ != nullptr)
        ptr_search = ptr_search -> parent_;

    return ptr_search;
}


const string& Node :: key() const
{
    return key_;
}


Node* Node :: right() const
{
    return right_;
}


Node* Node :: left() const
{
    return left_;
}


Node* Node :: parent() const
{
    return parent_;
}


string& Node :: key()
{
    return key_;
}


Node*& Node :: right()
{
    return right_;
}

Node*& Node :: left()
{
    return left_;
}

Node*& Node :: parent()
{
    return parent_;
}

#endif /* Node_h */
