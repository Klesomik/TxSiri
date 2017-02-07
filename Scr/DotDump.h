#ifndef DotDump_h

#define DotDump_h

#include "Node.h"
#include "Dotter-fixed.h"

static const int SIZE_NAME = 640;

class DotDump
{
    private:
        const std::string title;
        const std::string photo;
        const std::string type;

        const Node* root;

        DotDump (const DotDump& from);

        DotDump& operator = (const DotDump& from);

        void DotVersion ();

        void CreateDotFile ();
        void CloseDotFile ();

        void MakeTree (const Node* node, int number);

    public:
        DotDump (const string name_file, const string name_photo, const string name_type, const Node* first);
};

DotDump :: DotDump (const string name_file, const string name_photo, const string name_type, const Node* first):
    title (name_file),
    photo (name_photo),
    type  (name_type),
    root  (first)
    {
        DotVersion ();
    }

void DotDump :: DotVersion ()
{
    CreateDotFile ();

    MakeTree (root, 1);

    CloseDotFile ();
}

void DotDump :: CreateDotFile ()
{
    dtBegin (title.c_str());

    dtNodeStyle ().shape ("box");
}

void DotDump :: CloseDotFile ()
{
    dtEnd ();

    dtRender (title.c_str(), photo.c_str (), type.c_str ());
}

void DotDump :: MakeTree (const Node* node, int number)
{
    static int count = 0;
               count++;

    int cbPrint = 0;
    char node_str[SIZE_NAME] = "";

        string str = node -> key ();

        cbPrint += sprint  (node_str + cbPrint,                   str);

        #ifdef MORE_INFORMATION

        cbPrint += sprintf (node_str + cbPrint, "parent = %p\n ", node -> parent ());
        cbPrint += sprintf (node_str + cbPrint, "this = %p\n",    node);
        cbPrint += sprintf (node_str + cbPrint, "left = %p\n ",   node -> left ());
        cbPrint += sprintf (node_str + cbPrint, "right = %p\n ",  node -> right ());

        #endif /* MORE_INFORMATION */

    dtNode (count, node_str);

    if (count != 1) dtLink (number, count);

    int copy_count = count;

    if (node ->  left ()) MakeTree (node -> left (),  copy_count);
    if (node -> right ()) MakeTree (node -> right (), copy_count);
}

#endif /* DotDump_h */
