#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

using namespace std;
int rows = 3, col =3;
class Ticktoktoe
{
private:

    int board[3][3];

public:

    Ticktoktoe(){
        for(int i = 0; i < rows; i++ ){
            for(int j = 0; j < col; j++){
                board[i][j] = 0;
            }
        }
    }

    void showboard(){
        cout << "   \t\t\t\tGame Board \n\n";
        for(int i = 0; i < rows; i++ ){
            cout << "\t\t\t";
            for(int j = 0; j < col; j++){
                if(board[i][j] != 0){
                    if(board[i][j] == 1){
                        cout << setw(5) << left << "X";
                    }
                    else{
                        cout << setw(5) << left << "O";
                    }

                }
                else{
                    if(i == 0 && j == 0){
                        cout << setw(5) << left << "1";
                    }
                    else if(i == 0 && j == 1){
                        cout << setw(5) << left << "2";
                    }
                    else if(i == 0 && j == 2){
                        cout << setw(5) << left << "3";
                    }
                    else if(i == 1 && j == 0){
                        cout << setw(5) << left << "4";
                    }
                    else if(i == 1 && j == 1){
                        cout << setw(5) << left << "5";
                    }
                    else if(i == 1 && j == 2){
                        cout << setw(5) << left << "6";
                    }
                    else if(i == 2 && j == 0){
                        cout << setw(5) << left << "7";
                    }
                    else if(i == 2 && j == 1){
                        cout << setw(5) << left << "8";
                    }
                    else if(i == 2 && j == 2){
                        cout << setw(5) << left << "9";
                    }
                }

                if(j < col - 1){
                    cout << setw(5) << left << " |";
                }
            }
            if(i < rows - 1){
            cout << "\n\t\t\t-----------------------" << endl;
        }
        }
        cout << endl << endl;
    }

    bool isfull(){
        int count_c=0;
      for(int i =0; i < rows ; i++){
        for(int j =0; j < col; j++){
            if(board[i][j] !=0)
                count_c++;
        }
      }
      if(count_c == 9){
        return true;
      }
      return false;
    }

    void switchturn(int player, int number){
        if(player == 1){
            cout << "Player 1::\n";
         INPUT2:
          int r, c, turn;
            cout << "Enter Cell No (1--9) : ";
            cin >> turn;
            while(turn < 0 || turn > 9){
            cout << "Error !! Enter in (1-9): ";
            cin >> turn;
            }
            switch (turn){
            case 1:
                r = 0;
                c = 0;
                break;

            case 2:
                r = 0;
                c = 1;
                break;

            case 3:
                r = 0;
                c = 2;
                break;

            case 4:
                r = 1;
                c = 0;
                break;

            case 5:
                r = 1;
                c = 1;
                break;

            case 6:
                r = 1;
                c = 2;
                break;

            case 7:
                r = 2;
                c = 0;
                break;

            case 8:
                r = 2;
                c = 1;
                break;

            case 9:
                r = 2;
                c = 2;
                break;
            }
            if(board[r][c] != 0){
                cout << "Already Filled Try Again : " << endl;
                goto INPUT2;
            }
                board[r][c] = 1;
      }

        if(number == 2 && player == 2){
            cout << "Player 2::\n";
         INPUT:
          int r, c, turn;
            cout << "Enter Cell No (1--9) : ";
            cin >> turn;
            while(turn < 0 || turn > 9){
            cout << "Error !! Enter in (1-9): ";
            cin >> turn;
            }
            switch (turn){
            case 1:
                r = 0;
                c = 0;
                break;

            case 2:
                r = 0;
                c = 1;
                break;

            case 3:
                r = 0;
                c = 2;
                break;

            case 4:
                r = 1;
                c = 0;
                break;

            case 5:
                r = 1;
                c = 1;
                break;

            case 6:
                r = 1;
                c = 2;
                break;

            case 7:
                r = 2;
                c = 0;
                break;

            case 8:
                r = 2;
                c = 1;
                break;

            case 9:
                r = 2;
                c = 2;
                break;
            }
            if(board[r][c] != 0){
                cout << "Already Filled Try Again : " << endl;
                goto INPUT;
            }
            board[r][c] = 2;
      }

   else if(number == 1 && player == 2){
        int check1 = 0 ,check2 = 0, temp = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 2){
                    temp = 1;
                    break;
                }
            }
        }

        if(temp == 0){
           // cout << "In temp 0 " << endl;
            if(board[1][1] == 0){
                board[1][1] = 2;
                return;
            }
            else if(board[0][0] == 0){
                board[0][0] = 2;
                return;
            }
          }

            for(int i = 0; i < rows; i++){
              for(int j =0; j< col; j++){
                if(board[i][j] == 1){
                    if(j == 0 && board[i][j+1] == 1 && board[i][j+2] == 0){
                        //cout << "In 1 1" << endl;
                        board[i][j+2] = 2;
                        check1 = 1;
                        break;
                    }
                    if(j == 2 && board[i][j-1] == 1 && board[i][j-2] == 0){
                        //cout << "In 1 2" << endl;
                        board[i][j-2] = 2;
                        check1 = 1;
                        break;
                    }
                    if(i == 0 && board[i+1][j] == 1 && board[i+2][j] == 0){
                        //cout << "In 1 3" << endl;
                        board[i+2][j] = 2;
                        check1 = 1;
                        break;
                    }
                    if(i == 2 && board[i-1][j] == 1 && board[i-2][j] == 0){
                       // cout << "In 1 4" << endl;
                        board[i-2][j] = 2;
                        check1 = 1;
                        break;
                    }
                    if(i == 0 && j == 0 && board[i+1][j+1] == 1 && board[i+2][j+2] == 0){
                        //cout << "In 1 5" << endl;
                        board[i+2][j+2] = 2;
                        check1 = 1;
                        break;
                    }
                    if(i == 0 && j == 2 && board[i+1][j-1] == 1 && board[i+2][j-2] == 0){
                        //cout << "In 1 6" << endl;
                        board[i+2][j-2] = 2;
                        check1 = 1;
                        break;
                    }
                    if(i == 2 && j == 0 && board[i-1][j+1] == 1 && board[i-2][j+2] == 0){
                        //cout << "In 1 7" << endl;
                        board[i-2][j+2] = 2;
                        check1 = 1;
                        break;
                    }
                    if(i == 2 && j == 2 && board[i-1][j-1] == 1 && board[i-2][j-2] == 0){
                        //cout << "In 1 8" << endl;
                        board[i-2][j-2] = 2;
                        check1 = 1;
                        break;
                    }
                }
             }
           }

           if(check1 == 0){
            //cout << "In check 0 " << endl;
            for(int i =0; i < rows; i++){
              for(int j =0; j< col; j++){
                if(board[i][j] == 2){
                    if(j == 0 && board[i][j+1] == 2 && board[i][j+2] == 0){
    //                   cout << "Why here ??" << endl;
    //                    cout << "In 2 1" << endl;
                        board[i][j+2] = 2;
                        check2 = 1;
                        return;
                    }
                   else if(j == 2 && board[i][j-1] == 2 && board[i][j-2] == 0){
                    //    cout << "In 2 2" << endl;
                        board[i][j-2] = 2;
                        check2 = 1;
                        return;
                    }
                  else if(i == 0 && board[i+1][j] == 2 && board[i+2][j] == 0){
                        //cout << "In 2 3" << endl;
                        board[i+2][j] = 2;
                        check2 = 1;
                        return;
                    }
                   else if(i == 2 && board[i-1][j] == 2 && board[i-2][j] == 0){
                       // cout << "In 2 4" << endl;
                        board[i-2][j] = 2;
                        check2 = 1;
                        return;
                    }
                   else if(i == 0 && j == 0 && board[i+1][j+1] == 2 && board[i+2][j+2] == 0){
                       // cout << "In 2 5" << endl;
                        board[i+2][j+2] = 2;
                        check2 = 1;
                        return;
                    }
                   else if(i == 0 && j == 2 && board[i+1][j-1] == 2 && board[i+2][j-2] == 0){
                       // cout << "In 2 6" << endl;
                        board[i+2][j-2] = 2;
                        check2 = 1;
                        return;
                    }
                   else if(i == 2 && j == 0 && board[i-1][j+1] == 2 && board[i-2][j+2] == 0){
                      //  cout << "In 2 7" << endl;
                        board[i-2][j+2] = 2;
                        check2 = 1;
                        return;
                    }
                   else if(i == 2 && j == 2 && board[i-1][j-1] == 2 && board[i-2][j-2] == 0){
                       // cout << "In 2 8" << endl;
                        board[i-2][j-2] = 2;
                        check2 = 1;
                        return;
                    }
                }
             }
           }
      //  cout << "outer loop out " << endl;

            if(check2 == 0){
            //  cout << "In check 2 == 0" << endl;
                for(int i =0; i < rows; i++){
                    for(int j =0; j< col; j++){
                        if(board[i][j] == 0){
                        // cout << "In 3 1" << endl;
                            board[i][j] = 2;
                            return;
                        }
                    }
                }
            }
        }
    }
}

    bool iswon(){
        int p1 = 0,p2 = 0;
        for(int i =0; i < rows; i++){
            for(int j =0; j< col; j++){
                if(board[i][j] == 1){
                    if(j == 0 && board[i][j+1] == 1 && board[i][j+2] == 1){
                        //cout << "In 1st" << endl;
                        p1 = 1;
                    }
                    if(j == 2 && board[i][j-1] == 1 && board[i][j-2] == 1){
                        //cout << "In 2st" << endl;
                        p1 = 1;
                    }
                    if(i == 0 && board[i+1][j] == 1 && board[i+2][j] == 1){
                       // cout << "In 3st" << endl;
                        p1 = 1;
                    }
                    if(i == 2 && board[i-1][j] == 1 && board[i-2][j] == 1){
                      //  cout << "In 4st" << endl;
                        p1 = 1;
                    }
                    if(i == 0 && j == 0 && board[i+1][j+1] == 1 && board[i+2][j+2] == 1){
                      //  cout << "In 5st" << endl;
                        p1 = 1;
                    }
                    if(i == 0 && j == 2 && board[i+1][j-1] == 1 && board[i+2][j-2] == 1){
                      //  cout << "In 6st" << endl;
                        p1 = 1;
                    }
                    if(i == 2 && j == 0 && board[i-1][j+1] == 1 && board[i-2][j+2] == 1){
                       // cout << "In 7st" << endl;
                        p1 = 1;
                    }
                    if(i == 2 && j == 2 && board[i-1][j-1] == 1 && board[i-2][j-2] == 1){
                     //   cout << "In 8st" << endl;
                        p1 = 1;
                    }
                }

                if(board[i][j] == 2){
                    if(j == 0 && board[i][j+1] == 2 && board[i][j+2] == 2){
                      //  cout << "In 1st" << endl;
                        p2 = 1;
                    }
                    if(j == 2 && board[i][j-1] == 2 && board[i][j-2] == 2){
                       // cout << "In 2st" << endl;
                        p2 = 1;
                    }
                    if(i == 0 && board[i+1][j] == 2 && board[i+2][j] == 2){
                      //  cout << "In 3st" << endl;
                        p2 = 1;
                    }
                    if(i == 2 && board[i-1][j] == 2 && board[i-2][j] == 2){
                      //  cout << "In 4st" << endl;
                        p2 = 1;
                    }
                    if(i == 0 && j == 0 && board[i+1][j+1] == 2 && board[i+2][j+2] == 2){
                      //  cout << "In 5st" << endl;
                        p2 = 1;
                    }
                    if(i == 0 && j == 2 && board[i+1][j-1] == 2 && board[i+2][j-2] == 2){
                        //cout << "In 6st" << endl;
                        p2 = 1;
                    }
                    if(i == 2 && j == 0 && board[i-1][j+1] == 2 && board[i-2][j+2] == 2){
                        //cout << "In 7st" << endl;
                        p2 = 1;
                    }
                    if(i == 2 && j == 2 && board[i-1][j-1] == 2 && board[i-2][j-2] == 2){
                      //  cout << "In 8st" << endl;
                        p2 = 1;
                    }
                }
            }
        }

        if(p1 == 1 && p2 ==1){
            cout << "Game Draw !! " << endl;
            return true;
        }
        if(p1 == 1 && p2 == 0){
            cout << "PLAYER 1 Won the game !! " << endl;
            return true;
        }
        if(p1 == 0 && p2 == 1){
            cout << "PLAYER 2 Won the game !! " << endl;
            return true;
        }
       return false;
    }

    void start(){
        int player;
        TEAM:
        cout << "Enter No of players : ";
        cin >> player;
        while(player < 1 || player >2)
            goto TEAM;

        int dis = 0;
        showboard();
        while(isfull() == false || iswon() == false){
            switchturn(1, player);
            system("cls");
            showboard();

            if(iswon()){
                return;
            }
            if(isfull()){
                cout << "Game Draw.. "  << endl;
                return;
            }
            switchturn(2, player);
            if(player == 1){
                //system("pause");
                cout << "Ummm, So I should Place at " << endl;
                Sleep(800);
                cout << "Okay !! Here you go " << endl;
                Sleep(900);
            }

            system("cls");
            showboard();

            if(iswon()){
                return;
            }

            if(isfull()){
                cout << "Game Draw.. "  << endl;
                return;
            }
        }
        return;
    }

};
int main()
{

        Ticktoktoe Game;
        Game.start();

    cout << endl;
    cout << "\n\t\t\t------------" << endl;
    cout << "\t\t\t GAME ENDED " << endl;
    cout << "\t\t\t------------" << endl;
    cout << "\t\tDeveloped By Muhammad Yasir " << endl;

    return 0;
}
