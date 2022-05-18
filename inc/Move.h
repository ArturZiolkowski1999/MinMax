# pragma once

class Move {
public:
int score;
int column;
int row;

Move(int score){
    this->score = score;
    this->column = 0;
    this->row = 0;
};
Move(){
    this->score = 0;
    this->column = 0;
    this->row = 0;
}
};
