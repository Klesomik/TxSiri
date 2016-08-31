#include "DataFile.h"

struct Window
{
    const int xSize, ySize;

    Window ();

    void HelloSiri ();
    Node <string>* InIt (const char name[] = "TreeFile//Data.txt");
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
    prints ("������������, ���� ����� Siri.\n");

    prints ("�� ������ �������� ����-����, � � ������� ���.\n");

    prints ("����� ����������� ���!\n");
    $d

    txSleep (250);
}

Node <string>* Window :: InIt (const char name[])
{
    DataFile rd (name, "r");

    Node <string>* root = rd.read ();

    return root;
}
