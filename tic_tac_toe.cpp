#include <bits/stdc++.h>
using namespace std;

char USER = 'x';
char AI = 'o';

class game
{
protected:
    int points;
    char table[9];

public:
    game()
    {
        points = 0;
        for (int i = 0; i < 9; i++)
            table[i] = '1' + i;
    }
    void resetGame()
    {
        points = 0;
        for (int i = 0; i < 9; i++)
            table[i] = '1' + i;
    }
    void resetTable()
    {
        for (int i = 0; i < 9; i++)
            table[i] = '1' + i;
    }
    void display()
    {
        cout << "================= your points: " << points << " =================" << endl;
        for (int i = 1; i <= 9; i++)
            cout << table[i - 1] << ((i - 1) % 3 == 2 ? "\n" : " | ");
    }

    void check()
    {
        // =====================================
        // to check for colums and rows
        for (int i = 0; i < 3; i++)
            if (table[i] == table[i + 1] && table[i] == table[i + 2])
            {
                if (table[i] == USER)
                {
                    points++;
                    resetTable();
                }
                else if (table[i] == AI)
                {
                    points--;
                    resetTable();
                }
                return;
            } // for rows
            else if (table[i] == table[i + 3] && table[i] == table[i + 6])
            {
                if (table[i] == USER)
                {
                    points++;
                    resetTable();
                }
                else if (table[i] == AI)
                {
                    points--;
                    resetTable();
                }
                return;
            } // for columns
        // =====================================

        // to check for diagonals
        if (table[0] == table[4] && table[0] == table[8])
        {
            if (table[0] == USER)
            {
                points++;
                resetTable();
            }
            else if (table[0] == AI)
            {
                points--;
                resetTable();
            }
            return;
        }
        else if (table[2] == table[4] && table[2] == table[6])
        {
            if (table[2] == USER)
            {
                points++;
                resetTable();
            }
            else if (table[2] == AI)
            {
                points--;
                resetTable();
            }
            return;
        }
    }
};

class user : public game
{
public:
    void setmark()
    {
        int n;
        cout << "Which grid you choose (1 - 9): ";
        cin >> n;
        n--;
        if (n >= 0 && n < 9 && table[n] != USER && table[n] != AI) // to check if the grid is clear from marks
            table[n] = USER;
        else
        {
            cout << "Cannot place mark here!" << endl;
            return;
        }
        aiMove();
    }
    
    void aiMove()
    {
        while (1)
        {
            int n = rand() % 9;
            if (table[n] != USER && table[n] != AI)
            {
                table[n] = AI;
                return;
            }
        }
    }
};

int main()
{
    user ob1;

    int n;
    cout << "Tic tac toe game!" << endl;
    do
    {
        cout << "==============================" << endl;
        cout << "1. set mark." << endl;
        cout << "2. reset / replay." << endl;
        cout << "3. exit game." << endl;
        cout << "==============================" << endl;

        cout << "choose from the list: ";
        cin >> n;

        switch (n)
        {
        case 1:
            ob1.setmark();
            ob1.check();
            ob1.display();
            break;

        case 2:
            ob1.resetGame();
            break;
        }
    } while (n != 3);
}