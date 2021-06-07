#include <bits/stdc++.h>
using namespace std;

bool ac(int a, char cells[]);
void Tic_Tac_Toe(char cells[]);
char winner(char cells[]);

int main(void)
{
    // phoenix();
    char player1, player2;
    do
    {
        cout << "Do you want to play (X) or (O) : ";
        cin >> player1;
    } while (tolower(player1) != 'x' && tolower(player1) != 'o');
    if (tolower(player1) == 'x')
        player2 = 'O', player1 = 'X';
    else
        player2 = 'X', player1 = 'O';
    int end = 0;
    char cells[10];
    for (int i = 1; i < 10; i++)
        cells[i] = i + '0';
    do
    {
        Tic_Tac_Toe(cells);
        int choice;
        do
        {
            if (end % 2 == 0)
                cout << "Player1 : choose number from 1 to 9 to play : ";
            else
                cout << "Player2 : choose number from 1 to 9 to play : ";
            cin >> choice;
        } while (!ac(choice, cells));
        if (end % 2 == 0)
            cells[choice] = player1;
        else
            cells[choice] = player2;
        end++;
        if (winner(cells) == player1)
        {
            Tic_Tac_Toe(cells);
            cout << "Player1 (" << player1 << ") Wins!!!";
            break;
        }
        else if (winner(cells) == player2)
        {
            Tic_Tac_Toe(cells);
            cout << "Player2 (" << player2 << ") Wins!!!";
            break;
        }
    } while (end != 9);
}

char winner(char cells[])
{
    for (int i = 1; i < 8; i += 3)
    {
        if (cells[i] == cells[(i + 1)] && cells[(i + 2)] == cells[i])
            return cells[i];
        if (cells[9 % i + 1] == cells[(9 % i + 1) + 3] && cells[(9 % i + 1) + 3] == cells[(9 % i + 1) + 6])
            return cells[9 % i + 1];
    }
    if (cells[1] == cells[5] && cells[5] == cells[9])
        return cells[1];
    if (cells[3] == cells[5] && cells[5] == cells[7])
        return cells[3];

    return 'z';
}

bool ac(int choice, char cells[])
{
    return (choice >= 1 && choice <= 9 && tolower(cells[choice]) != 'x' && tolower(cells[choice]) != 'o');
}

void Tic_Tac_Toe(char cells[])
{
    system("cls");
    cout << "+-----------+\n";
    cout << "| " << cells[1] << " | " << cells[2] << " | " << cells[3] << " |\n";
    cout << "|-----------|\n";
    cout << "| " << cells[4] << " | " << cells[5] << " | " << cells[6] << " |\n";
    cout << "|-----------|\n";
    cout << "| " << cells[7] << " | " << cells[8] << " | " << cells[9] << " |\n";
    cout << "+-----------+\n";
}
