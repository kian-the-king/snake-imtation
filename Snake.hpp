#ifndef _SNAKE
#define _Snake

#include<iostream>
#include<vector>
#include<ctime>
#include<random>

class Snake // this class is for scake movements 
{
    private:
        std::vector<std::vector<int>> position; // this vetore will save random numbers
        std::default_random_engine engine; // this engine will make random number
        char dir; // this is for direction
    public:
        Snake(); // function that produce random number
        void move(); // function that move in field
        void show(); // function that show field
        void counter(int); // this function is for several move
        void copy_way(std::vector<std::vector<int>>& copy); // this function will save movments for comparison with player
};


#endif