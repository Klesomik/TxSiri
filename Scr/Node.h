#include "DotDump.h"

template <typename Data_T>
class Node
{
    private:
        Data_T key_;

        Node *parent_, *left_, *right_;

        bool alive_;

        Node (const Node& from);

        Node& operator = (const Node& from);

    public:
        Node (const Data_T value);
        ~Node ();

        Node* insertLeft (const Data_T value);
        Node* insertRight (const Data_T value);

        Node* insertLeft (Node <Data_T>* example);
        Node* insertRight (Node <Data_T>* example);

        void eraseNode ();
        void eraseSubTree ();

        void dump ();
        void dumpAll ();
        void dump_file ();
        void dumpAll_file ();

        bool ok ();

        Node* getFirst (Node* example);

              Data_T& key ();
              Node*& right ();
              Node*& left ();
              Node*& parent ();

        const Data_T& key ()  const;
              Node* parent () const;
              Node* right ()  const;
              Node* left ()   const;
};

template <typename Data_T>
Node <Data_T> :: Node(const Data_T value):
    key_   (value),
    parent_  (nullptr),
    left_  (nullptr),
    right_ (nullptr),
    alive_ (true)
    { /*DUMP (4, "Constructor\n");*/ }

template <typename Data_T>
Node <Data_T> :: ~Node()
{
    if(!alive_)
        return;

    alive_ = false;

    delete left_;
           left_ = nullptr;

    delete right_;
           right_ = nullptr;
}

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: insertLeft(const Data_T value)
{
    Node* add_element = new Node(value);

    return insertLeft (add_element);
}

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: insertRight(const Data_T value)
{
    Node* add_element = new Node(value);

    return insertRight (add_element);
}

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: insertLeft(Node <Data_T>* example)
{
    left_ = example;
            example -> parent_ = this;

    return example;
}

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: insertRight(Node <Data_T>* example)
{
    right_ = example;
             example -> parent_ = this;

    return example;
}

template <typename Data_T>
void Node <Data_T> :: eraseNode()
{
    if(left_)
        left_ -> parent_ = parent_;

    if(right_)
        right_ -> parent_ = parent_;

    key_    = POISON;
    parent_ = POISON;
    left_   = POISON;
    right_  = POISON;
}

template <typename Data_T>
void Node <Data_T> :: eraseSubTree()
{
    delete this;
}

template <typename Data_T>
void Node <Data_T> :: dump()
{
    printf("\n=============dump=============\n");

    printf("Node (%s) [this = %p][", ok()? "ok" : "ERROR", this);
    print(key_);
    printf("]\n");

    printf("    prev = %p;\n", parent_);
    printf("    left = %p; right = %p;\n", left_, right_);

    printf("==============================\n\n");
}

template <typename Data_T>
void Node <Data_T> :: dump_file()
{
    fprintf(__DUMP__.dump_, "\n=============dump=============\n");

    fprintf(__DUMP__.dump_, "Node (%s) [%p]\n", ok()? "ok" : "ERROR", this);

    fprintf(__DUMP__.dump_, "==============================\n\n");
}

template <typename Data_T>
bool Node <Data_T> :: ok()
{
    if(this == nullptr || (this == (Node <Data_T>*) POISON))
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

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: getFirst(Node* example)
{
    Node* ptr_search = example;

    while(ptr_search -> parent_ != nullptr)
        ptr_search = ptr_search -> parent_;

    return ptr_search;
}

template <typename Data_T>
Data_T& Node <Data_T> :: key()
{
    return key_;
}

template <typename Data_T>
Node <Data_T>*& Node <Data_T> :: right()
{
    return right_;
}

template <typename Data_T>
Node <Data_T>*& Node <Data_T> :: left()
{
    return left_;
}

template <typename Data_T>
Node <Data_T>*& Node <Data_T> :: parent()
{
    return parent_;
}

template <typename Data_T>
const Data_T& Node <Data_T> :: key()      const
{
    return key_;
}

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: parent()  const
{
    return parent_;
}

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: right()   const
{
    return right_;
}

template <typename Data_T>
Node <Data_T>* Node <Data_T> :: left()    const
{
    return left_;
}
