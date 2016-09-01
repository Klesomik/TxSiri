#include "HelpSiri.h"

void WriteAboutObject (Node <string>* root);
void WriteAboutTwoObjects (Node <string>* root);

void WriteAboutObject (Node <string>* root)
{
    $c const char* name = printsScan ("Скажите мне название объекта: "); $d

    vector <string> path;

    $y;
    FindPath (root, path, name, true);

    if (nextAsk == true)
    {
        $c prints ("Не обманывайте меня. Я не знаю объекта %s. Хотите меня научить?\n", name); $d

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
            buffer += "и ";
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

    string buffer;

    if (pathPetya[0] == pathVasya[0]) buffer += "Схожи тем, что они оба: ";
    else buffer += "У объектов нет сходств, ";

    size_t size = max (pathPetya.size (), pathVasya.size ());

    for (size_t i = 0; i < size; i++)
    {
        if (pathPetya[i] == pathVasya[i])
        {
            buffer += pathVasya[i].c_str ();
            buffer += ", ";
        }

        else
        {
            buffer += "но ";
            buffer += petya;
            buffer += ": ";

            for (size_t j = i; j < pathPetya.size (); j++)
            {
                buffer += pathPetya[j].c_str ();
                buffer += ", ";
            }

            buffer += "а ";
            buffer += vasya;
            buffer += ": ";

            for (size_t j = i; j < pathVasya.size (); j++)
            {
                if (j < pathVasya.size () - 1)
                {
                    buffer += pathVasya[j].c_str ();
                    buffer += ", ";
                }

                else
                {
                    buffer += pathVasya[j].c_str ();
                    buffer += ".\n";
                }
            }

            break;
        }
    }

    $y; prints ("%s", buffer.c_str ()); $d;
}
