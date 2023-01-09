#include<iostream>
#include"Snake.hpp"

using namespace std;

Snake::Snake(){  // snake function of snake class , for snakes random movements with random engine and vectors
    int seed = static_cast<unsigned int>(time(nullptr)); // random engine give random number
    default_random_engine engine2(seed);
    engine = engine2;
    uniform_int_distribution<unsigned int> randInt(0,9);
    vector<int> temp;
    temp.push_back(randInt(engine)); // vector for saving number for movement
    temp.push_back(randInt(engine));
    position.push_back(temp);
    dir = ' ';
}

void Snake::move(){ // move function of snake class get random number and use for movments
    bool done = false;
    uniform_int_distribution<unsigned int> randInt(0,3);
    vector<int>temp;
    int last_move[2];
    last_move[0] = position[position.size()-1][0];
    last_move[1] = position[position.size()-1][1];
    while(!done){
        int direction = randInt(engine);
        switch (direction) // movment choice 
        {
            case 0: // move to the right
                if (last_move[0] > 0 && dir != 'd'){ 
                    temp.push_back(last_move[0] - 1);
                    temp.push_back(last_move[1]);
                    dir = 'u';
                    done = true;
                }
                break;            
            case 1: // move to the 
                if (last_move[0] < 9 && dir != 'u'){
                    temp.push_back(last_move[0] + 1);
                    temp.push_back(last_move[1]);
                    dir = 'd';
                    done = true;
                }
                break; 
            case 2:
                if (last_move[1] > 0 && dir != 'r'){
                    temp.push_back(last_move[0]);
                    temp.push_back(last_move[1] - 1);
                    dir = 'l';
                    done = true;
                }
                break;            
            case 3:
                if (last_move[1] < 9 && dir != 'l'){
                    temp.push_back(last_move[0]);
                    temp.push_back(last_move[1] + 1);
                    dir = 'r';
                    done = true;
                }
                break; 

        }
    }
    position.push_back(temp);
}

void Snake::show(){
    for (auto temp : position){
        cout << " i : " << temp[0] << "  j : " << temp[1] <<endl;
    }
    
}

void Snake::counter(int step){
    for (size_t i = 0; i < step - 1 ; i++){
        move();
    }
    
}

void Snake::copy_way(std::vector<std::vector<int>>&copy){
    for (auto vec: position){
       copy.push_back(vec); 
    }
    
}