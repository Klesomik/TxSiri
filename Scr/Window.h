#include "DataFile.h"

struct Window
{
    const int xSize, ySize;

    Window ();

    void HelloSiri ();
    Node* InIt (const char name[] = "TreeFile//Data.txt");
};

Window :: Window():
    xSize (800),
    ySize (600)
    {
        txCreateWindow (xSize, ySize);

        SetWindowText (txWindow (), "TxSiri");
    }

void Window :: HelloSiri ()
{
    txSleep (250);

    $c
    prints ("Здравствуйте, меня зовут Siri.\n"
            "Вы можете загадать кого-либо, а я отгадаю его.\n"
            "Вперёд захватывать мир!\n");
    $d

    txSleep (250);
}

Node* Window :: InIt (const char name[])
{
    DataFile rd (name, "r");

    Node* root = rd.read ();

    return root;
}
