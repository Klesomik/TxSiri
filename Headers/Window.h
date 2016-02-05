#include "DataFile.h"

struct Window
{
    const int xSize, ySize;

    Window ();

    void HelloSiri ();
    Node <string>* InIt ();
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
    prints ("Здравствуйте, меня зовут Siri.\n");

    prints ("Вы можете загадать кого-либо, а я отгадаю его.\n");

    prints ("Вперёд захватывать мир!\n");
    $d

    txSleep (250);
}

Node <string>* Window :: InIt ()
{
    DataFile rd ("r");

    Node <string>* root = rd.read ();

    return root;
}
