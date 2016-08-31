#include "HelpSiri.h"

void WriteAboutObject (Node <string>* root);
void WriteAboutTwoObjects (Node <string>* root);

void WriteAboutObject (Node <string>* root)
{
    $c const char* name = printsScan ("������� ��� �������� �������: "); $d

    vector <string> path;

    $y;
    FindPath (root, path, name, true);

    if (nextAsk == true)
    {
        $c prints ("�� ����������� ����. ������ ������� ���. ������ ���� �������?\n"); $d

        IWantNew (root);

        return;
    }

    string buffer;

    for (int i = path.size () - 1; i >= 0; i--)
    {
        if (i > 1)
        {
            buffer += path[i].c_str ();
            buffer += ", ";
        }

        else if (i == 1)
        {
            buffer += path[i].c_str ();
            buffer += " ";
        }

        else if (path.size () - 1 == 0)
        {
            buffer += path[i].c_str ();
            buffer += ".\n";
        }

        else if (i == 0)
        {
            buffer += "� ";
            buffer += path[i].c_str ();
            buffer += ".\n";
        }
    }

    $y; prints ("%s", buffer.c_str ()); $d;

    txSleep (500);
}

void WriteAboutTwoObjects (Node <string>* root)
{
    char petya[NAME_SIZE] = "";
    vector <string> pathPetya;
    if (!ScanName (pathPetya, root, petya, 1, false)) return;

    char vasya[NAME_SIZE] = "";
    vector <string> pathVasya;
    if (!ScanName (pathVasya, root, vasya, 2, false)) return;

    $y;
    if (pathPetya[0] == pathVasya[0]) prints ("����� ���, ��� ��� ���: ");
    else prints ("� �������� ��� �������, ");

    size_t size = max (pathPetya.size (), pathVasya.size ());

    for (size_t i = 0; i < size; i++)
    {
        if (pathPetya[i] == pathVasya[i]) prints ("%s, ", pathVasya[i].c_str ());

        else
        {
            prints ("�� %s ", petya);
            for (size_t j = i; j < pathPetya.size (); j++) prints ("%s, ", pathPetya[j].c_str ());

            prints ("� %s ", vasya);
            for (size_t j = i; j < pathVasya.size (); j++)
            {
                if (j < pathVasya.size () - 1) prints ("%s, ", pathVasya[j].c_str ());

                else { prints ("%s.\n", pathVasya[j].c_str ()); $d }
            }

            return;
        }
    }
}
