#include "Dec.h"

void FindPath (Node <string>* current, vector <string> &path, string object, bool need);
bool Choose   (Node <string>* current);
void prints (const char param_print[], ...);
const char* printsScan (const char param_print[], ...);
const char* printScan (const char param_print[], ...);
void Swap (Node <string>* current, Node <string>* ask);
bool Direction (Node <string>* current);
bool ScanName (vector <string> &pathPetya, Node <string>* root, char petya[NAME_SIZE], const int count, bool write);
void IWantNew (Node <string>* root);
void Guess (Node <string>* root);

void FindPath (Node <string>* current, vector <string> &path, string object, bool need)
{
    if (stricmp (current -> key ().c_str (), object.c_str ()) == 0)
    {
        Node <string>* upper = current;

        if (need)
        {
            $y;

            prints ("%s это: ", upper -> key ().c_str ());

            $d;
        }

        while (upper -> parent ())
        {
            if (!Direction (upper))
            {
                upper = upper -> parent ();

                path.push_back ("не " + upper -> key ());
            }

            else
            {
                upper = upper -> parent ();

                path.push_back (upper -> key ());
            }
        }

        nextAsk = false;

        return;
    }

    else if (current -> left ())
    {
        assert (current -> right ());

        FindPath (current -> left  (), path, object, need);
        FindPath (current -> right (), path, object, need);
    }

    else return;
}

bool Choose (Node <string>* current)
{
    $c prints ("Это %s?\n", current -> key ().c_str()); $d

    for (int i = 0;; i++)
    {
        char answer[CMD_SIZE] = "";
        scanf ("%s", answer);

        if (stricmp (answer, "Да")  == 0 || stricmp (answer, "Д") == 0) return true;
        if (stricmp (answer, "Нет") == 0 || stricmp (answer, "Н") == 0) return false;

        if (i <   5) { $c prints ("%s", answerSiri[0]); $d }
        if (i ==  5) { $c prints ("%s", answerSiri[1]); $d }
        if (i ==  8) { $c prints ("%s", answerSiri[2]); $d }
        if (i == 10) { $c prints ("%s", answerSiri[3]); $d }
        if (i == 15) { $c prints ("%s", answerSiri[4]); $d }
    }
}

void prints (const char param_print[], ...)
{
    va_list list;
    va_start (list, param_print);

    char buff[512] = "";

    vsprintf (buff, param_print, list);

    printf ("%s", buff);

    SS (buff);

    va_end (list);
}

const char* printsScan (const char param_print[], ...)
{
    va_list list;
    va_start (list, param_print);

    char buff[512] = "";

    vsprintf (buff, param_print, list);

    $c printf ("%s", buff); $d

    SS (buff);

    va_end (list);

    fflush (stdin);

    static char scan_data[CMD_SIZE] = "";
    fgets (scan_data, sizeof (scan_data) - 1, stdin);

    int len = strlen (scan_data) - 1;
    if (len >= 1 && scan_data[len] == '\n') scan_data[len] = 0;

    return scan_data;
}

const char* printScan (const char param_print[], ...)
{
    va_list list;
    va_start (list, param_print);

    $c; vprintf (param_print, list); $d;

    va_end (list);

    fflush (stdin);

    static char scan_data[CMD_SIZE] = "";
    fgets (scan_data, sizeof (scan_data) - 1, stdin);

    int len = strlen (scan_data) - 1;
    if (len >= 1 && scan_data[len] == '\n') scan_data[len] = 0;

    return scan_data;
}

void Swap (Node <string>* current, Node <string>* ask)
{
    string tmp = current -> key ();
                 current -> key () = ask -> key ();
                                     ask -> key () = tmp;
}

bool Direction (Node <string>* current)
{
    if (current -> parent () -> right () == current)
        return true;

    else
        return false;
}

bool ScanName (vector <string> &pathPetya, Node <string>* root, char petya[NAME_SIZE], const int count, bool write)
{
    $c
    if (count != 0) strcpy (petya, printsScan ("Скажите мне название %d-го объекта: ", count));
    else            strcpy (petya, printsScan ("Скажите мне название объекта: "));

    nextAsk = true;

    FindPath (root, pathPetya, petya, write);

    if (nextAsk == true)
    {
        $c prints ("Не обманывайте меня. Я не знаю объекта %s. Хотите меня научить?\n", petya); $d

        IWantNew (root);

        return false;
    }

    reverse (pathPetya.begin (), pathPetya.end ());

    return true;
}

void IWantNew (Node <string>* root)
{
    while (true)
    {
        char answer[CMD_SIZE] = "";
        scanf ("%s", answer);

        if (stricmp (answer, "Да")  == 0 || stricmp (answer, "Д") == 0) { Guess (root); return; }
        if (stricmp (answer, "Нет") == 0 || stricmp (answer, "Н") == 0) return;

        prints ("Я не понимаю. Введите \"Да\" или \"Нет\":\n");
    }
}

void Guess (Node <string>* root)
{
    Node <string>* current = root;

    while (true)
    {
        if (Choose (current))
        {
            current = current -> right ();

            if (!current)
            {
                $c prints ("Я же говорила!\n"); $d

                return;
            }
        }

        else
        {
            if (current -> left ()) current = current -> left ();

            else
            {
                char name[128] = "";
                strcpy (name, printsScan ("А кто же это был?\n"));

                current -> insertRight (name);

                const char* answer = nullptr;
                while (true)
                {
                    $y; prints ("А чем %s отличается от %s?\n", name, current -> key ().c_str ()); $c;
                    answer = printScan ("Он(а)..."); $d;

                    char not_ask[128] = "";
                    sscanf (answer, " %s", not_ask);

                    if (stricmp (not_ask, "не") != 0) break;

                    $c; prints ("Вы мне вскружили голову своим 'не'. Говорите со мной проще!\n"); $d;
                }

                assert (answer);

                Node <string>* ask = current -> insertLeft (answer);

                $c prints ("Я запомнила, теперь вы меня не обманете\n"); $d

                Swap (current, ask);

                return;
            }
        }
    }
}
