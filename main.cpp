#include<iostream>
#include"Snake.hpp"
#include<random>
#include<vector>
#include <windows.h>
#include <fstream>

#define GREEN "\e[0;32m"
#define White "\e[0m"
#define RED "\e[0;31m"
#define GRAY "\e[0;30m"

using namespace std;

void print_map(char map[10][10]){
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if(map[i][j] == 'O'){
                cout << GREEN << map[i][j] << White << "|";
            }
            else if(map[i][j] == 'P'){
                cout << RED << map[i][j] << White << "|";
            }
            else{
                cout<< map[i][j]<< "|";
            }
        }
        cout << endl;
    }
    
}

void reset_map(char map[10][10]){
    for (size_t i = 0; i < 10; i++){
        for (size_t j = 0; j < 10; j++)
        {
            map[i][j] = ' ';
        } 
    }
}

bool match(const vector<vector<int>>& snake_move, const vector<vector<int>> player_move){
    for (size_t i = 0; i < snake_move.size(); i++){
        if (snake_move[i][0] != player_move[i][0] || snake_move[i][1] != player_move[i][1]){
            return false;
        }
    }
    return true;
}

int play()
{
    string playerName;
    cout<< "Enter your name : \n"<< endl;
    cin >> playerName;
    Sleep(400);
    cout << "Welcom "<< playerName<<endl;
    int level = 2; 
    char map[10][10];
    int score = 0;
    while (true)
    {
        vector<vector<int>> snake_move;
        vector<vector<int>> player_move;
        Snake snake;
        snake.counter(level);
        reset_map(map);

        snake.copy_way(snake_move);
        for (auto temp : snake_move){
            map[temp[0]][temp[1]] = 'O';
            print_map(map);
            Sleep(500);
            system("CLS");
        }

        print_map(map);
        Sleep(2000);
        system("CLS");
        cout << White<< "Your turn!" << endl << "w : up , s : down, a : left , d : right" << endl;
        reset_map(map);
        map[snake_move[0][0]][snake_move[0][1]] = 'P';
        player_move.push_back(snake_move[0]);
        print_map(map);
        char dir;
        int last_move[2];
        for (size_t i = 0; i < level - 1; i++){
            last_move[0] = player_move[player_move.size()-1][0];
            last_move[1] = player_move[player_move.size()-1][1];
            vector<int>temp;
            cin >> dir;
            switch (dir)
            {
            case 'w':
                if (last_move[0] > 0){
                        temp.push_back(last_move[0] - 1);
                        temp.push_back(last_move[1]);
                    }
                break;
            case 's':
                if (last_move[0] < 9){
                        temp.push_back(last_move[0] + 1);
                        temp.push_back(last_move[1]);
                    }
                break;
            case 'a':
                if (last_move[1] > 0){
                        temp.push_back(last_move[0]);
                        temp.push_back(last_move[1] - 1);
                    }
                break;
            case 'd':
                if (last_move[1] < 9){
                        temp.push_back(last_move[0]);
                        temp.push_back(last_move[1] + 1);
                    }
                break;
            default:
                i--;
                cout << "only w,s,a,d are true Entry! try again"<<endl;
                break;
            }
            system("CLS");
            player_move.push_back(temp);
            map[temp[0]][temp[1]] = 'P';
            print_map(map);
        }

        if (match(snake_move, player_move)){
            Beep(400,500);
            cout << "win!!!" <<endl;
            score += level;
            level++;
        }
        else{
            Beep(600,500);
            Beep(500,500);
            Beep(400,500);
            cout << "Game over!!!" <<endl;
            break;
        }
    }
    ofstream myFile("details.txt");
    if (myFile.fail())
    {
        cout << "faild!!";
        return 1;
    }
    myFile<<"name: "<< playerName<<"\t" <<"score: " << score<< endl;
    cout << "score: "<<score << endl;
    myFile.close();
}
void intro()
{
    cout << RED << "welcom to the"<< GREEN<<" Snake"<< White <<" imitation" << RED << " game!!!!"<< endl<< endl<< GRAY;
    cout << "Play : 1"<< endl;
    cout << "Help : 2"<< endl;
    cout << "Exit : 3 "<< endl;
    
}

void menu(int choice)
{
    
    switch (choice)
    {
    case 1:
        play();
        break;
    case 2:
    cout << "Hello!! \n this is a very simple game ! \nyou must just do what snake do !\n with w: up s: down d: right a: left \n"<< endl;
    int choice1;
    intro();
    cin >> choice1;
    menu(choice1);
        break;
    case 3:
        exit;
        break;
    default:
        break;
    }
}

int main(){
    
    int choice; // youser choice, number between 1 to 3
    intro(); // call intro function and intro
    cin >> choice; // get number
    menu(choice); // give the number to menu function


    
    return 0;
}