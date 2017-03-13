#ifndef Node_h

#define Node_h

#include "Tools.hpp"

class Node
{
    public:
        Node (const std::string& value = "");
        ~Node ();

        Node* insertLeft (const std::string& value = "");
        Node* insertRight (const std::string& value = "");

        Node* insertLeft (Node* example);
        Node* insertRight (Node* example);

        bool ok ();
        void dump (std::ofstream& out);

        void read (std::ifstream& in);
        void write (std::ofstream& out);

        void render (Dotter::Digraph& tree, const size_t number) const;

        const std::string& key () const;
        Node* right () const;
        Node* left () const;
        Node* parent () const;

        std::string& key ();
        Node*& right ();
        Node*& left ();
        Node*& parent ();

    private:
        std::string key_;

        Node *parent_, *left_, *right_;

        bool alive_;

        Node (const Node& from);

        Node& operator = (const Node& from);
};

Node::Node (const std::string& value /* = "" */):
    key_    (value),
    parent_ (nullptr),
    left_   (nullptr),
    right_  (nullptr),
    alive_  (true)
{
}

Node::~Node ()
{
    if (!alive_)
        return;

    alive_ = false;

    delete left_;
           left_ = nullptr;

    delete right_;
           right_ = nullptr;
}

Node* Node::insertLeft (const std::string& value /* = "" */)
{
    Node* add_element = new Node (value);

    return insertLeft (add_element);
}

Node* Node::insertRight (const std::string& value /* = "" */)
{
    Node* add_element = new Node (value);

    return insertRight (add_element);
}

Node* Node::insertLeft (Node* example)
{
    left_ = example;
            example->parent_ = this;

    return example;
}

Node* Node::insertRight (Node* example)
{
    right_ = example;
             example->parent_ = this;

    return example;
}

bool Node::ok ()
{
    if ((!left_) && (!right_))
        return true;

    if (left_ && right_)
        return true;

    return false;
}

void Node::dump (std::ofstream& out /* std::cout */)
{
    out << "\n=============DUMP=============\n";

    out << "Node (" << (ok ()? "ok" : "ERROR") << "):\n";

    out << "\t[this = " << this << "];\n";
    out << "\t[key  = " << key_ << "];\n";

    out << "==============================\n\n";
}

void Node::read (std::ifstream& in)
{
    char start = 0;

    in >> start;
    assert (start == '<');

    in >> start;
    assert (start == '"');

    std::getline (in, key_, '"');

    for (char current = 0;;)
    {
        in >> current;

        if (current == '>')
            break;

        else if (current == ',')
        {
            in >> current;

            assert (current == '(');

            if (!left_)
            {
                insertLeft ();

                left_->read (in);
            }

            else
            {
                insertRight ();

                right_->read (in);
            }

            in >> current;

            assert (current == ')');
        }

        else
            assert (false);
    }
}

void Node::write (std::ofstream& out)
{
    out << "<";

    out << key_;

    if (!left_)
        out << ",";

    else
    {
        out << "(";

        left_->write (out);

        out << "),(";

        right_->write (out);
    }

    out << ")>";
}

void Node::render (Dotter::Digraph& tree, const size_t number) const
{
	std::string title (key_);

    #ifdef MORE_INFORMATION

        char extra[640] = "";

        for (size_t i = 0; i < children_.size (); i++)
            sprintf (extra, "child[%d] = %p\n", i, children_[i]);

        title += extra;

    #endif /* MORE_INFORMATION */

    tree.node (number, title.c_str ());
}

const std::string& Node::key () const
{
    return key_;
}

Node* Node::right () const
{
    return right_;
}

Node* Node::left () const
{
    return left_;
}

Node* Node::parent () const
{
    return parent_;
}

std::string& Node::key ()
{
    return key_;
}

Node*& Node::right ()
{
    return right_;
}

Node*& Node::left ()
{
    return left_;
}

Node*& Node::parent ()
{
    return parent_;
}

Node* GetFirst (Node* example);
void RenderTree (const Node* root, const std::string& file_name, const std::string& render_name, const bool show);
void RenderNode (Dotter::Digraph& tree, const Node* current, const size_t number);

Node* GetFirst (Node* example)
{
    Node* current = example;

    while (current->parent () != nullptr)
        current = current->parent ();

    return current;
}

void RenderTree (const Node* root, const std::string& file_name, const std::string& render_name, const bool show)
{
    const std::string path ("Dotter");

    Dotter::Digraph tree;

    tree.dotter () = path;
    tree.text   () = file_name;
    tree.photo  () = render_name;

    tree.open ();

    root->render (tree, 0);

    if (root->left ())
        RenderNode (tree, root->left  (), 0);

    if (root->right ())
        RenderNode (tree, root->right (), 0);

    tree.render (show);
}

void RenderNode (Dotter::Digraph& tree, const Node* current, const size_t number)
{
    static size_t count = 0;
                  count++;

    current->render (tree, count);

    tree.link (number, count, "");

    size_t copy_count = count;

    if (current->left ())
        RenderNode (tree, current->left  (), copy_count);

    if (current->right ())
        RenderNode (tree, current->right (), copy_count);
}

#endif /* Node_h */
