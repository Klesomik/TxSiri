#include "StdSiri.h"

class DataFile
{
    private:
        FILE* binaryTree_;

        DataFile (const DataFile &from);

        DataFile& operator = (const DataFile &from);

    public:
        DataFile (const char mode[]);

        ~DataFile ();

        Node <string>* read ();
        void write (Node <string>* current);
};

DataFile :: DataFile (const char mode[]):
    binaryTree_ (fopen ("TreeFile//Data.txt", mode))
    {
        assert (binaryTree_);
    }

DataFile :: ~DataFile ()
{
    fclose (binaryTree_);

    binaryTree_ = nullptr;
}

Node <string>* DataFile :: read ()
{
    char sym = -1;
    if (fscanf (binaryTree_, " %c", &sym) != 1 || (sym != '(' && sym != '*'))
    {
        printf ("sym = %c, sym = %d, Syntax error 1 in data file\n", sym, sym);

        return nullptr;
    }

    if (sym == '*')
        return nullptr;

    char key[640] = "";
    if (fscanf (binaryTree_, " <%[^>]>", key) != 1)
    {
        printf ("Syntax error 2 in data file\n");

        return nullptr;
    }

    Node <string>* curr = new Node <string> (key);

    curr -> left ()  = read ();
    if (curr -> left ())
        curr -> left () -> parent () = curr;

    curr -> right () = read ();
    if (curr -> right ())
        curr -> right () -> parent () = curr;

    if (fscanf (binaryTree_, " %c", &sym) != 1 || sym != ')')
    {
        printf ("Syntax error 4 in data file\n");

        return nullptr;
    }

    return curr;
}

void DataFile :: write (Node <string>* current)
{
    if (!current)
    {
        fprintf (binaryTree_, "*");

        return;
    }

    fprintf (binaryTree_, "(");

    fprintf (binaryTree_, "<%s>", current -> key ().c_str());

    write (current -> left ());
    write (current -> right ());

    fprintf (binaryTree_, ")");
}
