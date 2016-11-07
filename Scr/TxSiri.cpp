
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

    const char* name = printScan ("Введите файл для чтения/записи: ");

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
    printf ("Загрузка...\n");
    Node <string>* root = tx_version.InIt (name);
    printf ("Загрузка завершена.\n\n");

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

        const char* cmd = printScan ("\nЧто Вы желаете: [О]тгадывать, [Д]ать определение, [С]равнить объекты\n"
                                         "[З]агадать объект, [П]оказать дерево, [У]далить базу, [В]ыйти с сохранением или [б]ез него?\n");

        if      (stricmp (cmd, "Отгадывать")        == 0 || stricmp (cmd, "О") == 0) Guess (root);

        else if (stricmp (cmd, "Дать определение")  == 0 || stricmp (cmd, "Д") == 0) WriteAboutObject (root);
        else if (stricmp (cmd, "Сравнить объекты")  == 0 || stricmp (cmd, "С") == 0) WriteAboutTwoObjects (root);
        else if (stricmp (cmd, "Показать дерево")   == 0 || stricmp (cmd, "П") == 0) { $c prints ("%s", treeSiri[i % 4]); $d DotDump <string> finish ("Tree.dot", "Tree.jpg", "jpg", root); }
        else if (stricmp (cmd, "Удалить базу")      == 0 || stricmp (cmd, "У") == 0) DeleteBase (root);
        else if (stricmp (cmd, "Загадать объект\n") == 0 || stricmp (cmd, "З") == 0) SiriThink (root);
        else if (stricmp (cmd, " ")   == 0) continue;
        else if (stricmp (cmd, "\n")  == 0) continue;

        //cmd - 'a'
        else if ((stricmp (cmd, "j")  == 0) ||
                 (stricmp (cmd, "l")  == 0) ||
                 (stricmp (cmd, "c")  == 0) ||
                 (stricmp (cmd, "g")  == 0) ||
                 (stricmp (cmd, "d")  == 0) ||
                 (stricmp (cmd, ",")  == 0)) { $c prints ("%s", rusSiri[i % 4]); $d }

        else if (stricmp (cmd, "В")   == 0) { DataFile wr (name, "w"); wr.write (root); return i; }
        else if (stricmp (cmd, "Б")   == 0) return i;

        else { $c prints ("Я вас не понимаю. Введите команду, понятную мне:\n"); $d }
    }
}

void DeleteBase (Node <string>* root)
{
    $c; const char* ans = printsScan ("Вы действительно хотите удалить все мои знания? "); $d;

    if (stricmp (ans, "Да")  == 0 || stricmp (ans, "Д") == 0)
    {
        delete root -> left  ();
        delete root -> right ();

        root -> left  () = nullptr;
        root -> right () = nullptr;

        root -> key () = "Неизвестно кто";
    }

    if (stricmp (ans, "Нет")  == 0 || stricmp (ans, "Н") == 0)
    {
        $c;

        prints ("Я рада вашему обдуманному решению\n");

        $d;
    }
}

void Advertisement (bool hosting)
{
    if (hosting)
    {
        $y; prints ("Реклама:\n");

        prints ("Сайт методики довузовского обучения программированию и проектной деятельности в информатике: http://ded32.net.ru/\n");
        prints ("Автор: Дединский Илья Рудольфович\n"); $d;

        prints ("Чтобы отключить рекламу скажите мне что-нибудь хорошее\n");
        prints ("Например: Сири, ты милая ^_^\n");
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
            buffer += "не ";
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

    const char* answer = printScan ("Это...");

    if (stricmp (answer, curr -> key ().c_str ()) == 0) prints ("Приятно иметь дело с умным человеком\n");

    else prints ("К сожалению, вы не правы. Это был(а): %s\n", curr -> key ().c_str ());

    $d;
}
