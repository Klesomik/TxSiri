
//TODO: using hash to low speed of program

#include "TXLib.h"
#include "Window.h"

void Start ();
void Finish ();

void Work (Window &tx_version, const char name[] = "Materials//Data.txt");
int  MainLoop (Node <string>* root, const char name[]);
void DeleteBase (Node <string>* root);
void Advertisement (bool hosting);
void SiriThink (Node <string>* root);

int main()
{
    Start ();

    Window tx_version;

    _txExit = true;

    const char* name = printScan ("������� ���� ��� ������/������: ");

    if (stricmp (name, "~") == 0) Work (tx_version);
    else Work (tx_version, name);

    Finish ();

    Sleep (2000);

    return 0;
}

void Start ()
{
    mkdir (SIRI_PATH);
}

void Finish ()
{
    unlink (SIRI_ANSWER);

    rmdir (SIRI_PATH);
}

void Work (Window &tx_version, const char name[])
{
    printf ("��������...\n");
    Node <string>* root = tx_version.InIt (name);
    printf ("�������� ���������.\n\n");

    tx_version.HelloSiri ();

    int x = MainLoop (root, name);

    $c prints ("%s", buySiri[x % 4]);
}

int MainLoop (Node <string>* root, const char name[])
{
    bool hosting = true;

    for (int i = 0;; i++)
    {
        if (i != 0 && i % 10 == 0) Advertisement (hosting);

        const char* cmd = printScan ("\n��� �� �������: [�]���������, [�]��� �����������, [�]������� �������\n"
                                         "[�]������� ������, [�]������� ������, [�]������ ����, [�]���� � ����������� ��� [�]�� ����?\n");

        if      (stricmp (cmd, "����������")        == 0 || stricmp (cmd, "�") == 0) Guess (root);

        else if (stricmp (cmd, "���� �����������")  == 0 || stricmp (cmd, "�") == 0) WriteAboutObject (root);
        else if (stricmp (cmd, "�������� �������")  == 0 || stricmp (cmd, "�") == 0) WriteAboutTwoObjects (root);
        else if (stricmp (cmd, "�������� ������")   == 0 || stricmp (cmd, "�") == 0) { $c prints ("%s", treeSiri[i % 4]); $d DotDump <string> finish ("Tree.dot", "Tree.jpg", "jpg", root); }
        else if (stricmp (cmd, "������� ����")      == 0 || stricmp (cmd, "�") == 0) DeleteBase (root);
        else if (stricmp (cmd, "�������� ������\n") == 0 || stricmp (cmd, "�") == 0) SiriThink (root);
        else if (stricmp (cmd, " ")   == 0) continue;
        else if (stricmp (cmd, "\n")  == 0) continue;

        //cmd - 'a'
        else if ((stricmp (cmd, "j")  == 0) ||
                 (stricmp (cmd, "l")  == 0) ||
                 (stricmp (cmd, "c")  == 0) ||
                 (stricmp (cmd, "g")  == 0) ||
                 (stricmp (cmd, "d")  == 0) ||
                 (stricmp (cmd, ",")  == 0)) { $c prints ("%s", rusSiri[i % 4]); $d }

        else if (stricmp (cmd, "�")   == 0) { DataFile wr (name, "w"); wr.write (root); return i; }
        else if (stricmp (cmd, "�")   == 0) return i;

        else { $c prints ("� ��� �� �������. ������� �������, �������� ���:\n"); $d }
    }
}

void DeleteBase (Node <string>* root)
{
    $c; const char* ans = printsScan ("�� ������������� ������ ������� ��� ��� ������? "); $d;

    if (stricmp (ans, "��")  == 0 || stricmp (ans, "�") == 0)
    {
        delete root -> left  ();
        delete root -> right ();

        root -> left  () = nullptr;
        root -> right () = nullptr;

        root -> key () = "���������� ���";
    }

    if (stricmp (ans, "���")  == 0 || stricmp (ans, "�") == 0)
    {
        $c;

        prints ("� ���� ������ ����������� �������\n");

        $d;
    }
}

void Advertisement (bool hosting)
{
    if (hosting)
    {
        $y; prints ("�������:\n");

        prints ("���� �������� ������������ �������� ���������������� � ��������� ������������ � �����������: http://ded32.net.ru/\n");
        prints ("�����: ��������� ���� �����������\n"); $d;

        prints ("����� ��������� ������� ������� ��� ���-������ �������\n");
        prints ("��������: ����, �� ����� ^_^\n");
    }
}

void SiriThink (Node <string>* root)
{
    srand (time (nullptr));

    string buffer;

    Node <string>* curr = root;

    while (curr -> left () && curr -> right ())
    {
        if (curr != root) buffer += ", ";

        int vect = rand () % 2 + 1;

        if (vect == 1)
        {
            buffer += "�� ";
            buffer += curr -> key ().c_str ();

            curr = curr -> left ();
        }

        else
        {
            buffer += curr -> key ().c_str ();

            curr = curr -> right ();
        }
    }

    buffer += ".\n";

    buffer[0] = (char) toupper (buffer[0]);

    $y; prints ("%s", buffer.c_str ()); $c;

    const char* answer = printScan ("���...");

    if (stricmp (answer, curr -> key ().c_str ()) == 0) prints ("������� ����� ���� � ����� ���������\n");

    else prints ("� ���������, �� �� �����. ��� ���(�): %s\n", curr -> key ().c_str ());

    $d;
}
