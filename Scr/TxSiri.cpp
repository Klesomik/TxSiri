
//TODO: using hash to low speed of program

#include "TXLib.h"
#include "BaseFunctions.hpp"

Node* BuildTree (const char name[] = "TreeFile//Data.txt");

void Start ();
void Finish ();

void Work (const char name[] = "TreeFile//Data.txt");
int  MainLoop (Node* root, const char name[]);
void Advertisement (bool hosting);

int main()
{
    Start ();

    PrintSystem ("������� ���� ��� ������/������: ");

    std::string name;
    std::getline (std::cin, name, '\n');

    if (name == "~") Work ();
    else Work (name.c_str ());

    Finish ();

    return 0;
}

Node* BuildTree (const char name[])
{
    Node* root = new Node;

    std::ifstream in (name);

    assert (in);

    root->read (in);

    return root;
}

void Start ()
{
    const int size_x = 800, size_y = 600;

    mkdir (SIRI_PATH);

    srand (time (nullptr));

    setlocale(LC_ALL, "rus");

    txCreateWindow (size_x, size_y);
    SetWindowText (txWindow (), "TxSiri");

    _txExit = true;
}

void Finish ()
{
    unlink (SIRI_ANSWER);

    rmdir (SIRI_PATH);

    Sleep (2000);
}

void Work (const char name[])
{
    PrintSystem ("��������...\n");
    Node* root = BuildTree (name);
    PrintSystem ("�������� ���������.\n\n");

    txSleep (250);

    PrintSiri ("������������, ���� ����� Siri.\n"
               "�� ������ �������� ����-����, � � ������� ���.\n"
               "����� ����������� ���!\n");

    txSleep (250);

    int x = MainLoop (root, name);

    PrintSiri ("%s", buySiri[x % 4]);
}

int MainLoop (Node* root, const char name[])
{
    bool hosting = true;

    for (int i = 0;; i++)
    {
        if (i != 0 && i % 10 == 0)
            Advertisement (hosting);

        PrintSystem ("\n��� �� �������: [�]���������, [�]��� �����������, [�]������� �������\n"
                     "[�]������� ������, [�]������� ������, [�]������ ����, [�]���� � ����������� ��� [�]�� ����?\n");

        std::string cmd;
        std::getline (std::cin, cmd, '\n');

        if      (Compare (cmd, "����������")       || Compare (cmd, "�")) Guess (root);
        else if (Compare (cmd, "���� �����������") || Compare (cmd, "�")) WriteAboutObject (root);
        else if (Compare (cmd, "�������� �������") || Compare (cmd, "�")) WriteAboutTwoObjects (root);
        else if (Compare (cmd, "�������� ������")  || Compare (cmd, "�")) { PrintSiri ("%s", treeSiri[i % 4]); RenderTree (root, "Tree.dot", "Tree.jpg", true); }
        else if (Compare (cmd, "������� ����")     || Compare (cmd, "�")) DeleteBase (root);
        else if (Compare (cmd, "�������� ������")  || Compare (cmd, "�")) SiriThink (root);

        else if (Compare (cmd, " ") || Compare (cmd, "\n")) continue;

        //cmd - 'a'
        else if (Compare (cmd, "j") || Compare (cmd, "l") || Compare (cmd, "c") || Compare (cmd, "g") || Compare (cmd, "d") || Compare (cmd, ","))
            PrintSiri ("%s", rusSiri[i % 4]);

        else if (Compare (cmd, "�")) { std::ofstream out (name); root->write (out); return i; }
        else if (Compare (cmd, "�")) return i;

        else { PrintSiri ("� ��� �� �������. ������� �������, �������� ���:\n"); }
    }
}

void Advertisement (bool hosting)
{
    if (hosting)
    {
        PrintSystem ("�������:\n"
                     "���� �������� ������������ �������� ���������������� � ��������� ������������ � �����������: http://ded32.net.ru/\n"
                     "�����: ��������� ���� �����������\n");

        PrintSiri ("����� ��������� ������� ������� ��� ���-������ �������\n"
                   "��������: ����, �� ����� ^_^\n");
    }
}
