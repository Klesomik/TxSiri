#include "Dotter-fixed.h"
#include "DumpKey.h"

static const int SIZE_NAME = 640;

template <typename Data_T>
class Node;

template <typename Data_T>
class DotDump
{
    private:
        const std::string title;
        const std::string photo;
        const std::string type;

        const Node <Data_T>* root;

        DotDump (const DotDump& from);

        DotDump& operator = (const DotDump& from);

        void DotVersion ();

        void CreateDotFile ();
        void CloseDotFile ();

        void MakeTree (const Node <Data_T>* node, int number);

    public:
        DotDump (const string name_file, const string name_photo, const string name_type, const Node <Data_T>* first);
};

template <typename Data_T>
DotDump <Data_T> :: DotDump (const string name_file, const string name_photo, const string name_type, const Node <Data_T>* first):
    title (name_file),
    photo (name_photo),
    type  (name_type),
    root  (first)
    {
        DotVersion ();
    }

template <typename Data_T>
void DotDump <Data_T> :: DotVersion ()
{
    CreateDotFile ();

    MakeTree (root, 1);

    CloseDotFile ();
}

template <typename Data_T>
void DotDump <Data_T> :: CreateDotFile ()
{
    dtBegin (title.c_str());

    dtNodeStyle ().shape ("box");
}

template <typename Data_T>
void DotDump <Data_T> :: CloseDotFile ()
{
    dtEnd ();

    dtRender (title.c_str(), photo.c_str (), type.c_str ());
}

template <typename Data_T>
void DotDump <Data_T> :: MakeTree (const Node <Data_T>* node, int number)
{
    static int count = 0;
               count++;

    int cbPrint = 0;
    char node_str[SIZE_NAME] = "";

        //cbPrint += sprintf (node_str + cbPrint, "count = %d\n ", count);

        string str = node -> key ();

        cbPrint += sprint  (node_str + cbPrint,                   str);
        /*cbPrint += sprintf (node_str + cbPrint, "parent = %p\n ", node -> parent ());
        cbPrint += sprintf (node_str + cbPrint, "this = %p\n",    node);
        cbPrint += sprintf (node_str + cbPrint, "left = %p\n ",   node -> left ());
        cbPrint += sprintf (node_str + cbPrint, "right = %p\n ",  node -> right ());*/

    dtNode (count, node_str);

    if (count != 1) dtLink (number, count);

    int copy_count = count;

    if (node ->  left ()) MakeTree (node -> left (),  copy_count);
    if (node -> right ()) MakeTree (node -> right (), copy_count);
}
