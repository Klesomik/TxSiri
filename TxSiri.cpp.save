#include "Headers\Window.h"

int  MainLoop (Node <string>* root);
void Advertisement (bool hosting);
void SiriThink (Node <string>* root);

int main()
{
    Window tx_version;

    _txExit = true;

    printf ("Загрузка...\n");
    Node <string>* root = tx_version.InIt ();
    printf ("Загрузка завершена.\n\n");

    tx_version.HelloSiri ();

    int x = MainLoop (root);

    $c prints ("%s", buySiri[x % 4]);

    Sleep (2000);

    return 0;
}

int MainLoop (Node <string>* root)
{
    bool hosting = true;

    for (int i = 0;; i++)
    {
        if (i != 0 && i % 10 == 0) Advertisement (hosting);

        const char* cmd = printScan ("\nЧто Вы желаете: [О]тгадывать, [Д]ать определение, [С]равнить объекты\n"
                                         "[З]агадать объект, [П]оказать дерево, [У]далить базу, [В]ыйти с сохранением или [б]ез него?\n");

        if      (stricmp (cmd, "Отгадывать")       == 0 || stricmp (cmd, "О") == 0) Guess (root);

        else if (stricmp (cmd, "Дать определение") == 0 || stricmp (cmd, "Д") == 0) WriteAboutObject (root);
        else if (stricmp (cmd, "Сравнить объекты") == 0 || stricmp (cmd, "С") == 0) WriteAboutTwoObjects (root);
        else if (stricmp (cmd, "Показать дерево")  == 0 || stricmp (cmd, "П") == 0) { $c prints ("%s", treeSiri[i % 4]); $d DotDump <string> finish ("EX1", root); }
        else if (stricmp (cmd, "Удалить базу")     == 0 || stricmp (cmd, "У") == 0);
        else if (stricmp (cmd, "Загадать объект\n")     == 0 || stricmp (cmd, "З") == 0) SiriThink (root);
        else if (stricmp (cmd, " ")   == 0) continue;
        else if (stricmp (cmd, "\n")  == 0) continue;

        //cmd - 'a'
        else if ((stricmp (cmd, "j")  == 0) ||
                 (stricmp (cmd, "l")  == 0) ||
                 (stricmp (cmd, "c")  == 0) ||
                 (stricmp (cmd, "g")  == 0) ||
                 (stricmp (cmd, "d")  == 0) ||
                 (stricmp (cmd, ",")  == 0)) { $c prints ("%s", rusSiri[i % 4]); $d }

        else if (stricmp (cmd, "В")   == 0) { DataFile wr ("w"); wr.write (root); return i; }
        else if (stricmp (cmd, "Б")   == 0) return i;

        else { $c prints ("Я вас не понимаю. Введите команду, понятную мне:\n"); $d }
    }
}

void Advertisement (bool hosting)
{
    $y; prints ("РЕКЛАМА\n");

    prints ("Сайт методики довузовского обучения программированию и проектной деятельности в информатике: http://ded32.net.ru/\n");
    prints ("Автор: Дединский Илья Рудольфович\n"); $d;

    prints ("Чтобы отключить рекламу скажите мне что-нибудь хорошее\n");
    prints ("Например: Сири, ты милая ^_^\n");
}

void SiriThink (Node <string>* root)
{
    srand (time (nullptr));

    const int HTREE = 3;

    Node <string>* curr = root;

    for (int how_many = rand () % HTREE + 1; how_many > 0; how_many--)
    {
        int vect = rand () % 2 + 1;

        if (vect == 1) { prints ("не %s, ", curr -> key ().c_str ()); curr = curr -> left ();  }
        else           { prints ("%s, ", curr -> key ().c_str ());    curr = curr -> right (); }
    }
}
