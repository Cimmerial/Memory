#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>
#include <thread> //this_thread::sleep_for   (this_thread::sleep_for(chrono::seconds(5));)
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_BRIGHT_BLACK "\x1b[90m"

/* spade is "\u2660"
club is "\u2663"
heart is "\u2665"
diamond is "\u2666" */
using namespace std;
string charrot;
int dummy, dummy2;
string hallo[54];
string shilt[54];

int deck[54] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};

void pageClear()
{
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
}

bool arrayTF[54] = {
    // array to flip cards
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
};

bool sisterArrayTF[54] = {
    // array to remove cards
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
};

void shuffle(int deck[], int len)
{
    int tempy;
    int randomIndex;
    for (int i = 0; i < len; i++)
    {
        randomIndex = rand() % len;
        tempy = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = tempy;
    }
}

bool gameEnd() // if all cards gone, game ends
{
    if (sisterArrayTF[0] == false && sisterArrayTF[20] == false && sisterArrayTF[39] == false &&
        sisterArrayTF[1] == false && sisterArrayTF[21] == false && sisterArrayTF[40] == false &&
        sisterArrayTF[2] == false && sisterArrayTF[22] == false && sisterArrayTF[41] == false &&
        sisterArrayTF[3] == false && sisterArrayTF[23] == false && sisterArrayTF[42] == false &&
        sisterArrayTF[4] == false && sisterArrayTF[24] == false && sisterArrayTF[43] == false &&
        sisterArrayTF[5] == false && sisterArrayTF[25] == false && sisterArrayTF[44] == false &&
        sisterArrayTF[6] == false && sisterArrayTF[26] == false && sisterArrayTF[45] == false &&
        sisterArrayTF[7] == false && sisterArrayTF[27] == false && sisterArrayTF[46] == false &&
        sisterArrayTF[8] == false && sisterArrayTF[28] == false && sisterArrayTF[47] == false &&
        sisterArrayTF[9] == false && sisterArrayTF[29] == false && sisterArrayTF[48] == false &&
        sisterArrayTF[10] == false && sisterArrayTF[30] == false && sisterArrayTF[49] == false &&
        sisterArrayTF[11] == false && sisterArrayTF[31] == false && sisterArrayTF[50] == false &&
        sisterArrayTF[12] == false && sisterArrayTF[32] == false && sisterArrayTF[51] == false &&
        sisterArrayTF[13] == false && sisterArrayTF[33] == false && sisterArrayTF[52] == false &&
        sisterArrayTF[14] == false && sisterArrayTF[34] == false && sisterArrayTF[53] == false &&
        sisterArrayTF[15] == false && sisterArrayTF[35] == false && sisterArrayTF[16] == false &&
        sisterArrayTF[36] == false && sisterArrayTF[17] == false && sisterArrayTF[37] == false &&
        sisterArrayTF[18] == false && sisterArrayTF[38] == false && sisterArrayTF[19] == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string colorizeCardRed(string input, bool truefalse)
{
    if (truefalse == true)
    {
        return ANSI_COLOR_RED + input + ANSI_COLOR_RESET;
    }
    else
    {
        return ANSI_COLOR_BRIGHT_BLACK + input + ANSI_COLOR_RESET;
    }
}

string colorizeBlack(string input)
{
    return ANSI_COLOR_BLACK + input + ANSI_COLOR_RESET;
}

string colorizeBlue(string input)
{
    return ANSI_COLOR_BLUE + input + ANSI_COLOR_RESET;
}

void cardArray(int deck[], int len)
{

#pragma region "Variable control statements"
    for (int x = 0; x < len; x++)
    {
        if (arrayTF[x]) //
        {
            if (deck[x] == 0)
            {
                hallo[x] = " " + string("\u2660") + "A" + string("\u2660") + " ";
                shilt[x] = "A";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 0)
            {
                hallo[x] = "     ";
            }
        }
        else if (!arrayTF[x])
        {
            if (deck[x] == 0)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 1)
            {
                hallo[x] = " " + string("\u2660") + "K" + string("\u2660") + " ";
                shilt[x] = "K";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 1)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 1)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 2)
            {
                hallo[x] = " " + string("\u2660") + "Q" + string("\u2660") + " ";
                shilt[x] = "Q";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 2)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 2)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 3)
            {
                hallo[x] = " " + string("\u2660") + "J" + string("\u2660") + " ";
                shilt[x] = "J";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 3)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 3)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 4)
            {
                hallo[x] = " " + string("\u2660") + "9" + string("\u2660") + " ";
                shilt[x] = "9";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 4)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 4)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 5)
            {
                hallo[x] = " " + string("\u2660") + "8" + string("\u2660") + " ";
                shilt[x] = "8";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 5)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 5)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 6)
            {
                hallo[x] = " " + string("\u2660") + "7" + string("\u2660") + " ";
                shilt[x] = "7";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 6)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 6)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 7)
            {
                hallo[x] = " " + string("\u2660") + "6" + string("\u2660") + " ";
                shilt[x] = "6";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 7)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 7)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 8)
            {
                hallo[x] = " " + string("\u2660") + "5" + string("\u2660") + " ";
                shilt[x] = "5";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 8)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 8)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 9)
            {
                hallo[x] = " " + string("\u2660") + "4" + string("\u2660") + " ";
                shilt[x] = "4";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 9)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 9)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 10)
            {
                hallo[x] = " " + string("\u2660") + "3" + string("\u2660") + " ";
                shilt[x] = "3";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 10)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 10)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 11)
            {
                hallo[x] = " " + string("\u2660") + "2" + string("\u2660") + " ";
                shilt[x] = "2";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 11)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 11)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 12)
            {
                hallo[x] = " " + string("\u2663") + "A" + string("\u2663") + " ";
                shilt[x] = "A";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 12)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 12)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 13)
            {
                hallo[x] = " " + string("\u2663") + "K" + string("\u2663") + " ";
                shilt[x] = "K";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 13)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 13)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 14)
            {
                hallo[x] = " " + string("\u2663") + "Q" + string("\u2663") + " ";
                shilt[x] = "Q";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 14)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 14)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 15)
            {
                hallo[x] = " " + string("\u2663") + "J" + string("\u2663") + " ";
                shilt[x] = "J";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 15)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 15)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 16)
            {
                hallo[x] = " " + string("\u2663") + "9" + string("\u2663") + " ";
                shilt[x] = "9";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 16)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 16)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 17)
            {
                hallo[x] = " " + string("\u2663") + "8" + string("\u2663") + " ";
                shilt[x] = "8";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 17)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 17)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 18)
            {
                hallo[x] = " " + string("\u2663") + "7" + string("\u2663") + " ";
                shilt[x] = "7";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 18)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 18)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 19)
            {
                hallo[x] = " " + string("\u2663") + "6" + string("\u2663") + " ";
                shilt[x] = "6";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 19)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 19)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 20)
            {
                hallo[x] = " " + string("\u2663") + "5" + string("\u2663") + " ";
                shilt[x] = "5";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 20)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 20)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 21)
            {
                hallo[x] = " " + string("\u2663") + "4" + string("\u2663") + " ";
                shilt[x] = "4";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 21)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 21)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 22)
            {
                hallo[x] = " " + string("\u2663") + "3" + string("\u2663") + " ";
                shilt[x] = "3";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 22)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 22)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 23)
            {
                hallo[x] = " " + string("\u2663") + "2" + string("\u2663") + " ";
                shilt[x] = "2";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 23)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 23)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 24)
            {
                hallo[x] = " " + string("\u2665") + "A" + string("\u2665") + " ";
                shilt[x] = "A";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 24)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 24)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 25)
            {
                hallo[x] = " " + string("\u2665") + "K" + string("\u2665") + " ";
                shilt[x] = "K";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 25)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 25)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 26)
            {
                hallo[x] = " " + string("\u2665") + "Q" + string("\u2665") + " ";
                shilt[x] = "Q";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 26)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 26)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 27)
            {
                hallo[x] = " " + string("\u2665") + "J" + string("\u2665") + " ";
                shilt[x] = "J";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 27)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 27)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 28)
            {
                hallo[x] = " " + string("\u2665") + "9" + string("\u2665") + " ";
                shilt[x] = "9";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 28)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 28)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 29)
            {
                hallo[x] = " " + string("\u2665") + "8" + string("\u2665") + " ";
                shilt[x] = "8";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 29)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 29)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 30)
            {
                hallo[x] = " " + string("\u2665") + "7" + string("\u2665") + " ";
                shilt[x] = "7";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 30)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 30)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 31)
            {
                hallo[x] = " " + string("\u2665") + "6" + string("\u2665") + " ";
                shilt[x] = "6";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 31)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 31)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 32)
            {
                hallo[x] = " " + string("\u2665") + "5" + string("\u2665") + " ";
                shilt[x] = "5";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 32)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 32)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 33)
            {
                hallo[x] = " " + string("\u2665") + "4" + string("\u2665") + " ";
                shilt[x] = "4";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 33)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 33)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 34)
            {
                hallo[x] = " " + string("\u2665") + "3" + string("\u2665") + " ";
                shilt[x] = "3";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 34)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 34)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 35)
            {
                hallo[x] = " " + string("\u2665") + "2" + string("\u2665") + " ";
                shilt[x] = "2";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 35)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 35)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 36)
            {
                hallo[x] = " " + string("\u2666") + "A" + string("\u2666") + " ";
                shilt[x] = "A";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 36)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 36)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 37)
            {
                hallo[x] = " " + string("\u2666") + "K" + string("\u2666") + " ";
                shilt[x] = "K";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 37)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 37)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 38)
            {
                hallo[x] = " " + string("\u2666") + "Q" + string("\u2666") + " ";
                shilt[x] = "Q";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 38)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 38)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 39)
            {
                hallo[x] = " " + string("\u2666") + "J" + string("\u2666") + " ";
                shilt[x] = "J";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 39)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 39)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 40)
            {
                hallo[x] = " " + string("\u2666") + "9" + string("\u2666") + " ";
                shilt[x] = "9";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 40)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 40)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 41)
            {
                hallo[x] = " " + string("\u2666") + "8" + string("\u2666") + " ";
                shilt[x] = "8";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 41)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 41)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 42)
            {
                hallo[x] = " " + string("\u2666") + "7" + string("\u2666") + " ";
                shilt[x] = "7";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 42)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 42)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 43)
            {
                hallo[x] = " " + string("\u2666") + "6" + string("\u2666") + " ";
                shilt[x] = "6";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 43)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 43)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 44)
            {
                hallo[x] = " " + string("\u2666") + "5" + string("\u2666") + " ";
                shilt[x] = "5";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 44)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 44)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 45)
            {
                hallo[x] = " " + string("\u2666") + "4" + string("\u2666") + " ";
                shilt[x] = "4";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 45)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 45)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 46)
            {
                hallo[x] = " " + string("\u2666") + "3" + string("\u2666") + " ";
                shilt[x] = "3";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 46)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 46)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 47)
            {
                hallo[x] = " " + string("\u2666") + "2" + string("\u2666") + " ";
                shilt[x] = "2";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 47)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 47)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 48)
            {
                hallo[x] = " " + string("10") + string("\u2660") + " ";
                shilt[x] = "0";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 48)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 48)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 49)
            {
                hallo[x] = " " + string("10") + string("\u2663") + " ";
                shilt[x] = "0";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 49)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 49)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 50)
            {
                hallo[x] = " " + string("10") + string("\u2665") + " ";
                shilt[x] = "0";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 50)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 50)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 51)
            {
                hallo[x] = " " + string("10") + string("\u2666") + " ";
                shilt[x] = "0";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 51)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 51)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 52)
            {
                hallo[x] = " J:( ";
                shilt[x] = "X";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 52)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 52)
            {
                hallo[x] = charrot;
            }
        }
        if (arrayTF[x]) //
        {
            if (deck[x] == 53)
            {
                hallo[x] = " J:) ";
                shilt[x] = "X";
            }
        }
        else if (!sisterArrayTF[x])
        {
            if (deck[x] == 53)
            {
                hallo[x] = "     ";
            }
        }
        else
        {
            if (deck[x] == 53)
            {
                hallo[x] = charrot;
            }
        }
    }
#pragma endregion
    cout << endl;
    cout << colorizeBlack("  |") << colorizeBlue("  1  ") << colorizeBlack("|") << colorizeBlue("  2  ") << colorizeBlack("|") << colorizeBlue("  3  ") << colorizeBlack("|") << colorizeBlue("  4  ") << colorizeBlack("|") << colorizeBlue("  5  ") << colorizeBlack("|") << colorizeBlue("  6  ") << colorizeBlack("|") << colorizeBlue("  7  ") << colorizeBlack("|") << colorizeBlue("  8  ") << colorizeBlack("|") << colorizeBlue("  9  ") << colorizeBlack("|") << endl;
    cout << colorizeBlack("--*-----*-----*-----*-----*-----*-----*-----*-----*-----*") << endl;
    cout << colorizeBlue("A ") << colorizeBlack("|") << colorizeCardRed(hallo[0], arrayTF[0]) << colorizeBlack("|") << colorizeCardRed(hallo[1], arrayTF[1]) << colorizeBlack("|") << colorizeCardRed(hallo[2], arrayTF[2]) << colorizeBlack("|") << colorizeCardRed(hallo[3], arrayTF[3]) << colorizeBlack("|") << colorizeCardRed(hallo[4], arrayTF[4]) << colorizeBlack("|") << colorizeCardRed(hallo[5], arrayTF[5]) << colorizeBlack("|") << colorizeCardRed(hallo[6], arrayTF[6]) << colorizeBlack("|") << colorizeCardRed(hallo[7], arrayTF[7]) << colorizeBlack("|") << colorizeCardRed(hallo[8], arrayTF[8]) << colorizeBlack("|") << endl;
    cout << colorizeBlack("--*-----*-----*-----*-----*-----*-----*-----*-----*-----*") << endl;
    cout << colorizeBlue("B ") << colorizeBlack("|") << colorizeCardRed(hallo[9], arrayTF[9]) << colorizeBlack("|") << colorizeCardRed(hallo[10], arrayTF[10]) << colorizeBlack("|") << colorizeCardRed(hallo[11], arrayTF[11]) << colorizeBlack("|") << colorizeCardRed(hallo[12], arrayTF[12]) << colorizeBlack("|") << colorizeCardRed(hallo[13], arrayTF[13]) << colorizeBlack("|") << colorizeCardRed(hallo[14], arrayTF[14]) << colorizeBlack("|") << colorizeCardRed(hallo[15], arrayTF[15]) << colorizeBlack("|") << colorizeCardRed(hallo[16], arrayTF[16]) << colorizeBlack("|") << colorizeCardRed(hallo[17], arrayTF[17]) << colorizeBlack("|") << endl;
    cout << colorizeBlack("--*-----*-----*-----*-----*-----*-----*-----*-----*-----*") << endl;
    cout << colorizeBlue("C ") << colorizeBlack("|") << colorizeCardRed(hallo[18], arrayTF[18]) << colorizeBlack("|") << colorizeCardRed(hallo[19], arrayTF[19]) << colorizeBlack("|") << colorizeCardRed(hallo[20], arrayTF[20]) << colorizeBlack("|") << colorizeCardRed(hallo[21], arrayTF[21]) << colorizeBlack("|") << colorizeCardRed(hallo[22], arrayTF[22]) << colorizeBlack("|") << colorizeCardRed(hallo[23], arrayTF[23]) << colorizeBlack("|") << colorizeCardRed(hallo[24], arrayTF[24]) << colorizeBlack("|") << colorizeCardRed(hallo[25], arrayTF[25]) << colorizeBlack("|") << colorizeCardRed(hallo[26], arrayTF[26]) << colorizeBlack("|") << endl;
    cout << colorizeBlack("--*-----*-----*-----*-----*-----*-----*-----*-----*-----*") << endl;
    cout << colorizeBlue("D ") << colorizeBlack("|") << colorizeCardRed(hallo[27], arrayTF[27]) << colorizeBlack("|") << colorizeCardRed(hallo[28], arrayTF[28]) << colorizeBlack("|") << colorizeCardRed(hallo[29], arrayTF[29]) << colorizeBlack("|") << colorizeCardRed(hallo[30], arrayTF[30]) << colorizeBlack("|") << colorizeCardRed(hallo[31], arrayTF[31]) << colorizeBlack("|") << colorizeCardRed(hallo[32], arrayTF[32]) << colorizeBlack("|") << colorizeCardRed(hallo[33], arrayTF[33]) << colorizeBlack("|") << colorizeCardRed(hallo[34], arrayTF[34]) << colorizeBlack("|") << colorizeCardRed(hallo[35], arrayTF[35]) << colorizeBlack("|") << endl;
    cout << colorizeBlack("--*-----*-----*-----*-----*-----*-----*-----*-----*-----*") << endl;
    cout << colorizeBlue("E ") << colorizeBlack("|") << colorizeCardRed(hallo[36], arrayTF[36]) << colorizeBlack("|") << colorizeCardRed(hallo[37], arrayTF[37]) << colorizeBlack("|") << colorizeCardRed(hallo[38], arrayTF[38]) << colorizeBlack("|") << colorizeCardRed(hallo[39], arrayTF[39]) << colorizeBlack("|") << colorizeCardRed(hallo[40], arrayTF[40]) << colorizeBlack("|") << colorizeCardRed(hallo[41], arrayTF[41]) << colorizeBlack("|") << colorizeCardRed(hallo[42], arrayTF[42]) << colorizeBlack("|") << colorizeCardRed(hallo[43], arrayTF[43]) << colorizeBlack("|") << colorizeCardRed(hallo[44], arrayTF[44]) << colorizeBlack("|") << endl;
    cout << colorizeBlack("--*-----*-----*-----*-----*-----*-----*-----*-----*-----*") << endl;
    cout << colorizeBlue("F ") << colorizeBlack("|") << colorizeCardRed(hallo[45], arrayTF[45]) << colorizeBlack("|") << colorizeCardRed(hallo[46], arrayTF[46]) << colorizeBlack("|") << colorizeCardRed(hallo[47], arrayTF[47]) << colorizeBlack("|") << colorizeCardRed(hallo[48], arrayTF[48]) << colorizeBlack("|") << colorizeCardRed(hallo[49], arrayTF[49]) << colorizeBlack("|") << colorizeCardRed(hallo[50], arrayTF[50]) << colorizeBlack("|") << colorizeCardRed(hallo[51], arrayTF[51]) << colorizeBlack("|") << colorizeCardRed(hallo[52], arrayTF[52]) << colorizeBlack("|") << colorizeCardRed(hallo[53], arrayTF[53]) << colorizeBlack("|") << endl;
    cout << colorizeBlack("--*-----*-----*-----*-----*-----*-----*-----*-----*-----*") << endl;
}

string cardTypeVal(string &input) // validation for cardType
{
    while (input != "Charrot" && input != "Bamba" && input != "Sunny" && input != "Big Cheddah" && input != "huh" && input != "Eminem" && input != "Shattered" && input != "Slant")
    {
        cout << "That is not an option, try again" << endl;
        getline(cin, input);
    }
    return input;
}

string teamCountVal(string &input) // validation for teamCount
{
    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8" && input != "9" && input != "10")
    {
        cout << "That is not an option, try again" << endl;
        getline(cin, input);
    }
    return input;
}

string cardFlipTimeVal(string &input){
    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7")
    {
        cout << "That is not an option, try again" << endl;
        getline(cin, input);
    }
    return input;
}

string rowVal(string &input) // validation for card row selection
{
    while (input != "A" && input != "B" && input != "C" && input != "D" && input != "E" && input != "F" && input != "a" && input != "b" && input != "c" && input != "d" && input != "e" && input != "f")
    {
        cout << "That is not an option, try again" << endl;
        getline(cin, input);
    }
    return input;
}

string columnVal(string &input) // validation for card column selection
{
    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8" && input != "9")
    {
        cout << "That is not an option, try again" << endl;
        getline(cin, input);
    }
    return input;
}

void findCardOne(string row, string column)
{
    int rowNum;
    int columnNum = stoi(column);
    if (row == "A" || row == "a")
    {
        rowNum = 1;
    }
    else if (row == "B" || row == "b")
    {
        rowNum = 2;
    }
    else if (row == "C" || row == "c")
    {
        rowNum = 3;
    }
    else if (row == "D" || row == "d")
    {
        rowNum = 4;
    }
    else if (row == "E" || row == "e")
    {
        rowNum = 5;
    }
    else if (row == "F" || row == "f")
    {
        rowNum = 6;
    }

    if (rowNum == 1 && columnNum == 1)
    {
        dummy = 0;
    }
    else if (rowNum == 1 && columnNum == 2)
    {
        dummy = 1;
    }
    else if (rowNum == 1 && columnNum == 3)
    {
        dummy = 2;
    }
    else if (rowNum == 1 && columnNum == 4)
    {
        dummy = 3;
    }
    else if (rowNum == 1 && columnNum == 5)
    {
        dummy = 4;
    }
    else if (rowNum == 1 && columnNum == 6)
    {
        dummy = 5;
    }
    else if (rowNum == 1 && columnNum == 7)
    {
        dummy = 6;
    }
    else if (rowNum == 1 && columnNum == 8)
    {
        dummy = 7;
    }
    else if (rowNum == 1 && columnNum == 9)
    {
        dummy = 8;
    }
    else if (rowNum == 2 && columnNum == 1)
    {
        dummy = 9;
    }
    else if (rowNum == 2 && columnNum == 2)
    {
        dummy = 10;
    }
    else if (rowNum == 2 && columnNum == 3)
    {
        dummy = 11;
    }
    else if (rowNum == 2 && columnNum == 4)
    {
        dummy = 12;
    }
    else if (rowNum == 2 && columnNum == 5)
    {
        dummy = 13;
    }
    else if (rowNum == 2 && columnNum == 6)
    {
        dummy = 14;
    }
    else if (rowNum == 2 && columnNum == 7)
    {
        dummy = 15;
    }
    else if (rowNum == 2 && columnNum == 8)
    {
        dummy = 16;
    }
    else if (rowNum == 2 && columnNum == 9)
    {
        dummy = 17;
    }
    else if (rowNum == 3 && columnNum == 1)
    {
        dummy = 18;
    }
    else if (rowNum == 3 && columnNum == 2)
    {
        dummy = 19;
    }
    else if (rowNum == 3 && columnNum == 3)
    {
        dummy = 20;
    }
    else if (rowNum == 3 && columnNum == 4)
    {
        dummy = 21;
    }
    else if (rowNum == 3 && columnNum == 5)
    {
        dummy = 22;
    }
    else if (rowNum == 3 && columnNum == 6)
    {
        dummy = 23;
    }
    else if (rowNum == 3 && columnNum == 7)
    {
        dummy = 24;
    }
    else if (rowNum == 3 && columnNum == 8)
    {
        dummy = 25;
    }
    else if (rowNum == 3 && columnNum == 9)
    {
        dummy = 26;
    }
    else if (rowNum == 4 && columnNum == 1)
    {
        dummy = 27;
    }
    else if (rowNum == 4 && columnNum == 2)
    {
        dummy = 28;
    }
    else if (rowNum == 4 && columnNum == 3)
    {
        dummy = 29;
    }
    else if (rowNum == 4 && columnNum == 4)
    {
        dummy = 30;
    }
    else if (rowNum == 4 && columnNum == 5)
    {
        dummy = 31;
    }
    else if (rowNum == 4 && columnNum == 6)
    {
        dummy = 32;
    }
    else if (rowNum == 4 && columnNum == 7)
    {
        dummy = 33;
    }
    else if (rowNum == 4 && columnNum == 8)
    {
        dummy = 34;
    }
    else if (rowNum == 4 && columnNum == 9)
    {
        dummy = 35;
    }
    else if (rowNum == 5 && columnNum == 1)
    {
        dummy = 36;
    }
    else if (rowNum == 5 && columnNum == 2)
    {
        dummy = 37;
    }
    else if (rowNum == 5 && columnNum == 3)
    {
        dummy = 38;
    }
    else if (rowNum == 5 && columnNum == 4)
    {
        dummy = 39;
    }
    else if (rowNum == 5 && columnNum == 5)
    {
        dummy = 40;
    }
    else if (rowNum == 5 && columnNum == 6)
    {
        dummy = 41;
    }
    else if (rowNum == 5 && columnNum == 7)
    {
        dummy = 42;
    }
    else if (rowNum == 5 && columnNum == 8)
    {
        dummy = 43;
    }
    else if (rowNum == 5 && columnNum == 9)
    {
        dummy = 44;
    }
    else if (rowNum == 6 && columnNum == 1)
    {
        dummy = 45;
    }
    else if (rowNum == 6 && columnNum == 2)
    {
        dummy = 46;
    }
    else if (rowNum == 6 && columnNum == 3)
    {
        dummy = 47;
    }
    else if (rowNum == 6 && columnNum == 4)
    {
        dummy = 48;
    }
    else if (rowNum == 6 && columnNum == 5)
    {
        dummy = 49;
    }
    else if (rowNum == 6 && columnNum == 6)
    {
        dummy = 50;
    }
    else if (rowNum == 6 && columnNum == 7)
    {
        dummy = 51;
    }
    else if (rowNum == 6 && columnNum == 8)
    {
        dummy = 52;
    }
    else if (rowNum == 6 && columnNum == 9)
    {
        dummy = 53;
    }
}

void findCardTwo(string row, string column)
{
    int rowNum;
    int columnNum = stoi(column);
    if (row == "A" || row == "a")
    {
        rowNum = 1;
    }
    else if (row == "B" || row == "b")
    {
        rowNum = 2;
    }
    else if (row == "C" || row == "c")
    {
        rowNum = 3;
    }
    else if (row == "D" || row == "d")
    {
        rowNum = 4;
    }
    else if (row == "E" || row == "e")
    {
        rowNum = 5;
    }
    else if (row == "F" || row == "f")
    {
        rowNum = 6;
    }

    if (rowNum == 1 && columnNum == 1)
    {
        dummy2 = 0;
    }
    else if (rowNum == 1 && columnNum == 2)
    {
        dummy2 = 1;
    }
    else if (rowNum == 1 && columnNum == 3)
    {
        dummy2 = 2;
    }
    else if (rowNum == 1 && columnNum == 4)
    {
        dummy2 = 3;
    }
    else if (rowNum == 1 && columnNum == 5)
    {
        dummy2 = 4;
    }
    else if (rowNum == 1 && columnNum == 6)
    {
        dummy2 = 5;
    }
    else if (rowNum == 1 && columnNum == 7)
    {
        dummy2 = 6;
    }
    else if (rowNum == 1 && columnNum == 8)
    {
        dummy2 = 7;
    }
    else if (rowNum == 1 && columnNum == 9)
    {
        dummy2 = 8;
    }
    else if (rowNum == 2 && columnNum == 1)
    {
        dummy2 = 9;
    }
    else if (rowNum == 2 && columnNum == 2)
    {
        dummy2 = 10;
    }
    else if (rowNum == 2 && columnNum == 3)
    {
        dummy2 = 11;
    }
    else if (rowNum == 2 && columnNum == 4)
    {
        dummy2 = 12;
    }
    else if (rowNum == 2 && columnNum == 5)
    {
        dummy2 = 13;
    }
    else if (rowNum == 2 && columnNum == 6)
    {
        dummy2 = 14;
    }
    else if (rowNum == 2 && columnNum == 7)
    {
        dummy2 = 15;
    }
    else if (rowNum == 2 && columnNum == 8)
    {
        dummy2 = 16;
    }
    else if (rowNum == 2 && columnNum == 9)
    {
        dummy2 = 17;
    }
    else if (rowNum == 3 && columnNum == 1)
    {
        dummy2 = 18;
    }
    else if (rowNum == 3 && columnNum == 2)
    {
        dummy2 = 19;
    }
    else if (rowNum == 3 && columnNum == 3)
    {
        dummy2 = 20;
    }
    else if (rowNum == 3 && columnNum == 4)
    {
        dummy2 = 21;
    }
    else if (rowNum == 3 && columnNum == 5)
    {
        dummy2 = 22;
    }
    else if (rowNum == 3 && columnNum == 6)
    {
        dummy2 = 23;
    }
    else if (rowNum == 3 && columnNum == 7)
    {
        dummy2 = 24;
    }
    else if (rowNum == 3 && columnNum == 8)
    {
        dummy2 = 25;
    }
    else if (rowNum == 3 && columnNum == 9)
    {
        dummy2 = 26;
    }
    else if (rowNum == 4 && columnNum == 1)
    {
        dummy2 = 27;
    }
    else if (rowNum == 4 && columnNum == 2)
    {
        dummy2 = 28;
    }
    else if (rowNum == 4 && columnNum == 3)
    {
        dummy2 = 29;
    }
    else if (rowNum == 4 && columnNum == 4)
    {
        dummy2 = 30;
    }
    else if (rowNum == 4 && columnNum == 5)
    {
        dummy2 = 31;
    }
    else if (rowNum == 4 && columnNum == 6)
    {
        dummy2 = 32;
    }
    else if (rowNum == 4 && columnNum == 7)
    {
        dummy2 = 33;
    }
    else if (rowNum == 4 && columnNum == 8)
    {
        dummy2 = 34;
    }
    else if (rowNum == 4 && columnNum == 9)
    {
        dummy2 = 35;
    }
    else if (rowNum == 5 && columnNum == 1)
    {
        dummy2 = 36;
    }
    else if (rowNum == 5 && columnNum == 2)
    {
        dummy2 = 37;
    }
    else if (rowNum == 5 && columnNum == 3)
    {
        dummy2 = 38;
    }
    else if (rowNum == 5 && columnNum == 4)
    {
        dummy2 = 39;
    }
    else if (rowNum == 5 && columnNum == 5)
    {
        dummy2 = 40;
    }
    else if (rowNum == 5 && columnNum == 6)
    {
        dummy2 = 41;
    }
    else if (rowNum == 5 && columnNum == 7)
    {
        dummy2 = 42;
    }
    else if (rowNum == 5 && columnNum == 8)
    {
        dummy2 = 43;
    }
    else if (rowNum == 5 && columnNum == 9)
    {
        dummy2 = 44;
    }
    else if (rowNum == 6 && columnNum == 1)
    {
        dummy2 = 45;
    }
    else if (rowNum == 6 && columnNum == 2)
    {
        dummy2 = 46;
    }
    else if (rowNum == 6 && columnNum == 3)
    {
        dummy2 = 47;
    }
    else if (rowNum == 6 && columnNum == 4)
    {
        dummy2 = 48;
    }
    else if (rowNum == 6 && columnNum == 5)
    {
        dummy2 = 49;
    }
    else if (rowNum == 6 && columnNum == 6)
    {
        dummy2 = 50;
    }
    else if (rowNum == 6 && columnNum == 7)
    {
        dummy2 = 51;
    }
    else if (rowNum == 6 && columnNum == 8)
    {
        dummy2 = 52;
    }
    else if (rowNum == 6 && columnNum == 9)
    {
        dummy2 = 53;
    }
}

int main()
{
    string cardType;
    string teamCountString;
    string teamName[10];
    int teamPoints[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool keepGoing = true;

    string cardChoiceColumn, cardChoiceRow;

    string cardFlipTimeString;

    srand(time(NULL));
    shuffle(deck, 54);
#pragma region "Card type selection"
    cout << "Pick a card style: " << endl;
    cout << "*-----*           *-----*" << endl;
    cout << "| -+- | Charrot   | <=> | Bamba" << endl;
    cout << "*-----*           *-----*" << endl
         << endl;
    cout << "*-----*           *-----*" << endl;
    cout << "| {*} | Sunny     | $$$ | Big Cheddah" << endl;
    cout << "*-----*           *-----*" << endl
         << endl;
    cout << "*-----*           *-----*" << endl;
    cout << "| ??? | huh       | M&M | Eminem" << endl;
    cout << "*-----*           *-----*" << endl
         << endl;
    cout << "*-----*           *-----*" << endl;
    cout << "| }~{ | Shattered | /v/ | Slant" << endl;
    cout << "*-----*           *-----*" << endl
         << endl;

    getline(cin, cardType);
    cardTypeVal(cardType); // validates answer
    if (cardType == "Charrot")
    {
        charrot = " -+- ";
    }
    else if (cardType == "Bamba")
    {
        charrot = " <=> ";
    }
    else if (cardType == "Sunny")
    {
        charrot = " {*} ";
    }
    else if (cardType == "Big Cheddah")
    {
        charrot = " $$$ ";
    }
    else if (cardType == "huh")
    {
        charrot = " ??? ";
    }
    else if (cardType == "Eminem")
    {
        charrot = " M&M ";
    }
    else if (cardType == "Shattered")
    {
        charrot = " }~{ ";
    }
    else if (cardType == "Slant")
    {
        charrot = " /v/ ";
    }
#pragma endregion

    cout << "How many teams would you like to play with? (1-10): ";
    getline(cin, teamCountString);
    int teamCountInt = stoi(teamCountVal(teamCountString)); // validates teamCount and converts to int
    for (int i = 1; i <= teamCountInt; i++)                 // stores names into teamName
    {
        cout << "Name of team " << i << "?: ";
        getline(cin, teamName[i]);
        cout << endl;
    }

    cout << "How many seconds should the card be shown for (1-7): ";
    getline(cin, cardFlipTimeString);
    int cardFlipTimeInt = stoi(cardFlipTimeVal(cardFlipTimeString));

    while (gameEnd()) // loop until no cards left
    {
        for (int i = 1; i <= teamCountInt; i++)
        {
            pageClear();
            cardArray(deck, 54); // displays card array
            cout << "Team " << teamName[i] << ", it's your turn!" << endl;
            keepGoing = true;

            while (keepGoing == true) // continues loop until both cards are valid
            {
                cout << "Pick a card column: ";
                getline(cin, cardChoiceColumn);
                columnVal(cardChoiceColumn);
                cout << "Pick a card row: ";
                getline(cin, cardChoiceRow);
                rowVal(cardChoiceRow);
                cout << endl;

                findCardOne(cardChoiceRow, cardChoiceColumn); // finds card one and makes dummy that number

                cout << "Pick a card column: ";
                getline(cin, cardChoiceColumn);
                columnVal(cardChoiceColumn);
                cout << "Pick a card row: ";
                getline(cin, cardChoiceRow);
                rowVal(cardChoiceRow);
                cout << endl;

                findCardTwo(cardChoiceRow, cardChoiceColumn); // finds card two and makes dummy2 that number

                if (!sisterArrayTF[dummy] || !sisterArrayTF[dummy2] || dummy == dummy2)
                {
                    cout << "One or more cards you chose were invalid, choose again: " << endl;
                    keepGoing = true;
                }
                else
                {
                    keepGoing = false;
                }
            }
            arrayTF[dummy] = true;
            arrayTF[dummy2] = true; // flip cards up
            cardArray(deck, 54);
            this_thread::sleep_for(chrono::seconds(cardFlipTimeInt)); // pause for X s
            if (shilt[dummy] == shilt[dummy2])          // checks in cards are the same
            {
                sisterArrayTF[dummy] = false;
                sisterArrayTF[dummy2] = false;
                teamPoints[i] = teamPoints[i] + 2;
                i--;
            }
            arrayTF[dummy] = false;
            arrayTF[dummy2] = false; // flip cards down
        }
    }
    cout << endl
         << "GAME OVER";
    for (int i = 1; i <= teamCountInt; i++)
    {
        cout << endl
             << teamName[i] << " found " << teamPoints[i] << " cards!";
    }
} // g++ -Wall -Werror -Wpedantic -std=c++17 -o memory memory.cpp