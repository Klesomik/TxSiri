#ifndef BaseFunctions_hpp

#define BaseFunctions_hpp

#include "Node.hpp"

void FindPath (Node* current, std::vector <std::string>& path, const std::string& object, bool need);
bool Choose   (Node* current);
void Swap (Node* current, Node* ask);
bool Direction (Node* current);
bool ScanName (std::vector <std::string>& pathPetya, Node* root, std::string& petya, const int count, bool write);
void IWantNew (Node* root);
void Guess (Node* root);
void WriteAboutObject (Node* root);
void WriteAboutTwoObjects (Node* root);
void DeleteBase (Node* root);
void SiriThink (Node* root);

void FindPath (Node* current, std::vector <std::string>& path, const std::string& object, bool need)
{
    if (current->key () == object)
    {
        Node* upper = current;

        if (need)
            PrintSiri ("%s ���: ", upper->key ().c_str ());

        while (upper->parent ())
        {
            if (!Direction (upper))
            {
                upper = upper->parent ();

                path.push_back ("�� " + upper->key ());
            }

            else
            {
                upper = upper->parent ();

                path.push_back (upper->key ());
            }
        }

        nextAsk = false;

        return;
    }

    else if (current->left ())
    {
        assert (current->right ());

        FindPath (current->left  (), path, object, need);
        FindPath (current->right (), path, object, need);
    }

    else
        return;
}

bool Choose (Node* current)
{
    PrintSiri ("��� %s?\n", current->key ().c_str());

    for (int i = 0;; i++)
    {
        std::string answer;
        std::getline (std::cin, answer, '\n');

        if (Compare (answer, "��")  || Compare (answer, "�")) return true;
        if (Compare (answer, "���") || Compare (answer, "�")) return false;

        for (int j = 0; j < 5; j++)
        {
            if (i == 5 * (j + 1))
            {
                PrintSiri ("%s", answerSiri[j]);

                break;
            }
        }
    }
}

bool Direction (Node* current)
{
    return (current->parent ()->right () == current);
}

bool ScanName (std::vector <std::string>& pathPetya, Node* root, std::string& petya, const int count, bool write)
{
    if (count != 0) PrintSiri ("������� ��� �������� %d-�� �������: ", count);
    else            PrintSiri ("������� ��� �������� �������: ");

    std::getline (std::cin, petya, '\n');

    nextAsk = true;

    FindPath (root, pathPetya, petya, write);

    if (nextAsk)
    {
        PrintSiri ("�� ����������� ����. � �� ���� ������� %s. ������ ���� �������?\n", petya.c_str ());

        IWantNew (root);

        return false;
    }

    nextAsk = false;

    std::reverse (pathPetya.begin (), pathPetya.end ());

    return true;
}

void IWantNew (Node* root)
{
    while (true)
    {
        std::string answer;
        std::getline (std::cin, answer, '\n');

        if (Compare (answer, "��")  || Compare (answer, "�")) { Guess (root); break; }
        if (Compare (answer, "���") || Compare (answer, "�")) break;

        PrintSiri ("� �� �������. ������� \"��\" ��� \"���\":\n");
    }
}

void Guess (Node* root)
{
    Node* current = root;

    while (true)
    {
        if (Choose (current))
        {
            if (current->right ())
                current = current->right ();

            else
            {
                PrintSiri ("� �� ��������!\n");

                break;
            }
        }

        else
        {
            if (current->left ())
                current = current->left ();

            else
            {
                PrintSiri ("� ��� �� ��� ���?\n");

                std::string name;
                std::getline (std::cin, name, '\n');

                current->insertRight (name);

                std::string answer;

                PrintSiri ("� ��� %s ���������� �� %s?\n", name.c_str (), current->key ().c_str ());
                PrintSiri ("��(�)...");

                std::getline (std::cin, answer, '\n');

                Node* ask = current->insertLeft (answer);

                PrintSiri ("� ���������, ������ �� ���� �� ��������\n");

                std::swap (current->key (), ask->key ());

                break;
            }
        }
    }
}

void WriteAboutObject (Node* root)
{
    PrintSiri ("������� ��� �������� �������: ");

    std::string name;
    std::getline (std::cin, name, '\n');

    std::vector <std::string> path;

    FindPath (root, path, name, true);

    if (nextAsk)
    {
        PrintSiri ("�� ����������� ����. � �� ���� ������� %s. ������ ���� �������?\n", name.c_str ());

        IWantNew (root);

        return;
    }

    std::string buffer;

    for (int i = (int) path.size () - 1; i >= 0; i--)
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

    PrintSiri ("%s", buffer.c_str ());

    txSleep (500);
}

void WriteAboutTwoObjects (Node* root)
{
    std::string petya;
    std::vector <std::string> pathPetya;
    if (!ScanName (pathPetya, root, petya, 1, false)) return;

    std::string vasya;
    std::vector <std::string> pathVasya;
    if (!ScanName (pathVasya, root, vasya, 2, false)) return;

    std::string buffer;

    if (pathPetya[0] == pathVasya[0]) buffer += "����� ���, ��� ��� ���: ";
    else buffer += "� �������� ��� �������, ";

    for (size_t i = 0; i < std::max (pathPetya.size (), pathVasya.size ()); i++)
    {
        if (pathPetya[i] == pathVasya[i])
        {
            buffer += pathVasya[i].c_str ();
            buffer += ", ";
        }

        else
        {
            buffer += "�� ";
            buffer += petya;
            buffer += ": ";

            for (size_t j = i; j < pathPetya.size (); j++)
            {
                buffer += pathPetya[j].c_str ();
                buffer += ", ";
            }

            buffer += "� ";
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

    PrintSiri ("%s", buffer.c_str ());
}

void DeleteBase (Node* root)
{
    PrintSiri ("�� ������������� ������ ������� ��� ��� ������? ");

    while (true)
    {
        std::string ans;
        std::getline (std::cin, ans, '\n');

        if (Compare (ans, "��") || Compare (ans, "�"))
        {
            delete root->left  ();
            delete root->right ();

            root->left  () = nullptr;
            root->right () = nullptr;

            root->key () = "���������� ���";
        }

        else if (Compare (ans, "���") || Compare (ans, "�"))
            PrintSiri ("� ���� ������ ����������� �������\n");

        else
            continue;

        break;
    }
}

void SiriThink (Node* root)
{
    std::string buffer;

    Node* curr = root;

    while (curr->left () && curr->right ())
    {
        if (curr != root) buffer += ", ";

        int vect = rand () % 2 + 1;

        if (vect == 1)
        {
            buffer += "�� ";
            buffer += curr->key ().c_str ();

            curr = curr->left ();
        }

        else
        {
            buffer += curr->key ().c_str ();

            curr = curr->right ();
        }
    }

    buffer += ".\n";

    buffer[0] = (char) toupper (buffer[0]);

    PrintSiri ("%s", buffer.c_str ());

    PrintSiri ("���...");

    std::string answer;
    std::getline (std::cin, answer, '\n');

    if (Compare (answer, curr->key ()))
        PrintSiri ("������� ����� ���� � ����� ���������\n");

    else
        PrintSiri ("� ���������, �� �� �����. ��� ���(�): %s\n", curr->key ().c_str ());
}

#endif /* BaseFunctions_hpp */
