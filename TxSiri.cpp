
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

    PrintSystem ("Введите файл для чтения/записи: ");

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
    PrintSystem ("Загрузка...\n");
    Node* root = BuildTree (name);
    PrintSystem ("Загрузка завершена.\n\n");

    txSleep (250);

    PrintSiri ("Здравствуйте, меня зовут Siri.\n"
               "Вы можете загадать кого-либо, а я отгадаю его.\n"
               "Вперёд захватывать мир!\n");

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

        PrintSystem ("\nЧто Вы желаете: [О]тгадывать, [Д]ать определение, [С]равнить объекты\n"
                     "[З]агадать объект, [П]оказать дерево, [У]далить базу, [В]ыйти с сохранением или [б]ез него?\n");

        std::string cmd;
        std::getline (std::cin, cmd, '\n');

        if      (Compare (cmd, "Отгадывать")       || Compare (cmd, "О")) Guess (root);
        else if (Compare (cmd, "Дать определение") || Compare (cmd, "Д")) WriteAboutObject (root);
        else if (Compare (cmd, "Сравнить объекты") || Compare (cmd, "С")) WriteAboutTwoObjects (root);
        else if (Compare (cmd, "Показать дерево")  || Compare (cmd, "П")) { PrintSiri ("%s", treeSiri[i % 4]); RenderTree (root, "Tree.dot", "Tree.jpg", true); }
        else if (Compare (cmd, "Удалить базу")     || Compare (cmd, "У")) DeleteBase (root);
        else if (Compare (cmd, "Загадать объект")  || Compare (cmd, "З")) SiriThink (root);

        else if (Compare (cmd, " ") || Compare (cmd, "\n")) continue;

        //cmd - 'a'
        else if (Compare (cmd, "j") || Compare (cmd, "l") || Compare (cmd, "c") || Compare (cmd, "g") || Compare (cmd, "d") || Compare (cmd, ","))
            PrintSiri ("%s", rusSiri[i % 4]);

        else if (Compare (cmd, "В")) { std::ofstream out (name); root->write (out); return i; }
        else if (Compare (cmd, "Б")) return i;

        else { PrintSiri ("Я вас не понимаю. Введите команду, понятную мне:\n"); }
    }
}

void Advertisement (bool hosting)
{
    if (hosting)
    {
        PrintSystem ("Реклама:\n"
                     "Сайт методики довузовского обучения программированию и проектной деятельности в информатике: http://ded32.net.ru/\n"
                     "Автор: Дединский Илья Рудольфович\n");

        PrintSiri ("Чтобы отключить рекламу скажите мне что-нибудь хорошее\n"
                   "Например: Сири, ты милая ^_^\n");
    }
}
