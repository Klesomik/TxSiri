
//TODO: using hash to low speed of program

#include "TXLib.h"
#include "Window.h"

void Start ();
void Finish ();

void Work (Window &tx_version, const char name[] = "Materials//Data.txt");
int  MainLoop (Node* root, const char name[]);
void DeleteBase (Node* root);
void Advertisement (bool hosting);
void SiriThink (Node* root);

int main()
{
    Start ();

    Window tx_version;

    _txExit = true;

    const char* name = printScan ("Ââåäèòå ôàéë äëÿ ÷òåíèÿ/çàïèñè: ");

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
    printf ("Çàãğóçêà...\n");
    Node* root = tx_version.InIt (name);
    printf ("Çàãğóçêà çàâåğøåíà.\n\n");

    tx_version.HelloSiri ();

    int x = MainLoop (root, name);

    $c prints ("%s", buySiri[x % 4]);
}

int MainLoop (Node* root, const char name[])
{
    bool hosting = true;

    for (int i = 0;; i++)
    {
        if (i != 0 && i % 10 == 0) Advertisement (hosting);

        const char* cmd = printScan ("\n×òî Âû æåëàåòå: [Î]òãàäûâàòü, [Ä]àòü îïğåäåëåíèå, [Ñ]ğàâíèòü îáúåêòû\n"
                                         "[Ç]àãàäàòü îáúåêò, [Ï]îêàçàòü äåğåâî, [Ó]äàëèòü áàçó, [Â]ûéòè ñ ñîõğàíåíèåì èëè [á]åç íåãî?\n");

        if      (stricmp (cmd, "Îòãàäûâàòü")        == 0 || stricmp (cmd, "Î") == 0) Guess (root);

        else if (stricmp (cmd, "Äàòü îïğåäåëåíèå")  == 0 || stricmp (cmd, "Ä") == 0) WriteAboutObject (root);
        else if (stricmp (cmd, "Ñğàâíèòü îáúåêòû")  == 0 || stricmp (cmd, "Ñ") == 0) WriteAboutTwoObjects (root);
        else if (stricmp (cmd, "Ïîêàçàòü äåğåâî")   == 0 || stricmp (cmd, "Ï") == 0) { $c prints ("%s", treeSiri[i % 4]); $d DotDump finish ("Tree.dot", "Tree.jpg", "jpg", root); }
        else if (stricmp (cmd, "Óäàëèòü áàçó")      == 0 || stricmp (cmd, "Ó") == 0) DeleteBase (root);
        else if (stricmp (cmd, "Çàãàäàòü îáúåêò\n") == 0 || stricmp (cmd, "Ç") == 0) SiriThink (root);
        else if (stricmp (cmd, " ")   == 0) continue;
        else if (stricmp (cmd, "\n")  == 0) continue;

        //cmd - 'a'
        else if ((stricmp (cmd, "j")  == 0) ||
                 (stricmp (cmd, "l")  == 0) ||
                 (stricmp (cmd, "c")  == 0) ||
                 (stricmp (cmd, "g")  == 0) ||
                 (stricmp (cmd, "d")  == 0) ||
                 (stricmp (cmd, ",")  == 0)) { $c prints ("%s", rusSiri[i % 4]); $d }

        else if (stricmp (cmd, "Â")   == 0) { DataFile wr (name, "w"); wr.write (root); return i; }
        else if (stricmp (cmd, "Á")   == 0) return i;

        else { $c prints ("ß âàñ íå ïîíèìàş. Ââåäèòå êîìàíäó, ïîíÿòíóş ìíå:\n"); $d }
    }
}

void DeleteBase (Node* root)
{
    $c; const char* ans = printsScan ("Âû äåéñòâèòåëüíî õîòèòå óäàëèòü âñå ìîè çíàíèÿ? "); $d;

    if (stricmp (ans, "Äà")  == 0 || stricmp (ans, "Ä") == 0)
    {
        delete root -> left  ();
        delete root -> right ();

        root -> left  () = nullptr;
        root -> right () = nullptr;

        root -> key () = "Íåèçâåñòíî êòî";
    }

    if (stricmp (ans, "Íåò")  == 0 || stricmp (ans, "Í") == 0)
    {
        $c;

        prints ("ß ğàäà âàøåìó îáäóìàííîìó ğåøåíèş\n");

        $d;
    }
}

void Advertisement (bool hosting)
{
    if (hosting)
    {
        $y; prints ("Ğåêëàìà:\n");

        prints ("Ñàéò ìåòîäèêè äîâóçîâñêîãî îáó÷åíèÿ ïğîãğàììèğîâàíèş è ïğîåêòíîé äåÿòåëüíîñòè â èíôîğìàòèêå: http://ded32.net.ru/\n");
        prints ("Àâòîğ: Äåäèíñêèé Èëüÿ Ğóäîëüôîâè÷\n"); $d;

        prints ("×òîáû îòêëş÷èòü ğåêëàìó ñêàæèòå ìíå ÷òî-íèáóäü õîğîøåå\n");
        prints ("Íàïğèìåğ: Ñèğè, òû ìèëàÿ ^_^\n");
    }
}

void SiriThink (Node* root)
{
    srand (time (nullptr));

    string buffer;

    Node* curr = root;

    while (curr -> left () && curr -> right ())
    {
        if (curr != root) buffer += ", ";

        int vect = rand () % 2 + 1;

        if (vect == 1)
        {
            buffer += "íå ";
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

    const char* answer = printScan ("İòî...");

    if (stricmp (answer, curr -> key ().c_str ()) == 0) prints ("Ïğèÿòíî èìåòü äåëî ñ óìíûì ÷åëîâåêîì\n");

    else prints ("Ê ñîæàëåíèş, âû íå ïğàâû. İòî áûë(à): %s\n", curr -> key ().c_str ());

    $d;
}
