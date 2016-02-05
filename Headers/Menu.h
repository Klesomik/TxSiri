

bool menu         ();
void aboutLoop    ();
void settingsLoop ();

void play     (COLORREF color);
void about    (COLORREF color);
void settings (COLORREF color);
void exit     (COLORREF color);
void back     (COLORREF color);

bool menu ()
{
    while (true)
    {
        txBegin ();

        play     (TX_LIGHTGREEN);
        about    (TX_GRAY);
        settings (TX_BLUE);
        exit     (TX_CYAN);

        if (txMouseX () >= 125 && txMouseX () <= 675 && txMouseY () >= 225 && txMouseY () <= 325)
        {
            play (TX_GREEN);

            if (txMouseButtons () & 1) return true;
        }

        if (txMouseX () >= 125 && txMouseX () <= 400 && txMouseY () >= 325 && txMouseY () <= 425)
        {
            about (TX_RED);

            if (txMouseButtons () & 1) aboutLoop ();
        }

        if (txMouseX () >= 400 && txMouseX () <= 675 && txMouseY () >= 325 && txMouseY () <= 425)
        {
            settings (TX_PINK);

            if (txMouseButtons () & 1) settingsLoop ();
        }

        if (txMouseX () >= 125 && txMouseX () <= 675 && txMouseY () >= 425 && txMouseY () <= 525)
        {
            exit (TX_YELLOW);

            if (txMouseButtons () & 1) return false;
        }

        txEnd ();
    }
}

void play (COLORREF color)
{
    txSetColor     (color);
    txSetFillColor (color);

    txRectangle (125, 225, 675, 325);

    txSetColor   (TX_WHITE);
    txSelectFont ("Times New Roman", 80);
    txTextOut    (225, 225, "Играть");
}

void about (COLORREF color)
{
    txSetColor     (color);
    txSetFillColor (color);

    txRectangle (125, 325, 400, 425);

    txTextOut   (125, 325, "Информация");
}

void settings (COLORREF color)
{
    txSetColor     (color);
    txSetFillColor (color);

    txRectangle (400, 325, 675, 425);

    txTextOut   (400, 325, "Настройки");
}

void exit (COLORREF color)
{
    txSetColor     (color);
    txSetFillColor (color);

    txRectangle (125, 425, 675, 525);

    txTextOut   (125, 425, "Выход");
}

void back (COLORREF color)
{
    txSetColor     (color);
    txSetFillColor (color);

    txRectangle (650, 25, 750, 75);

    txTextOut   (650, 25, "Назад");
}

void aboutLoop ()
{
    txClear ();

    while (true)
    {
        back (TX_WHITE);

        if (txMouseX () >= 650 && txMouseX () <= 750 && txMouseY () >= 25 && txMouseY () <= 75)
        {
            back (TX_BROWN);

            if (txMouseButtons () & 1) return;
        }
    }
}

void settingsLoop ()
{
    txClear ();

    while (true)
    {
        back (TX_WHITE);

        if (txMouseX () >= 650 && txMouseX () <= 750 && txMouseY () >= 25 && txMouseY () <= 75)
        {
            back (TX_BROWN);

            if (txMouseButtons () & 1) return;
        }
    }
}
