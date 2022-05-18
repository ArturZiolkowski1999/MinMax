# pragma once
# include <array>
# include <vector>
# include <limits>
# include <iostream>
# include <Move.h>


enum end_game_conditiond{
    GAME_IS_ACTIVE = 0,
    PLAYER_WIN = 1,
    AI_WIN = 2,
    TIE = 3
};

/// x is x; o is o; ' ' is empty
template <uint16_t size, uint16_t win_condition>
class Game {
private:
    std::array<std::array<char, size>, size> board;
    
    void ai_move();
    // 0- is player, 1 is ai
    Move get_best_move(int player, int depth);
    
    bool validate_input(int &column, int &row);
    bool is_game_active;
public:
    Game();
    void display();
    void game_loop();

    void player_move();
    end_game_conditiond validate_win_condition();

};


template <uint16_t size, uint16_t win_condition>
Game<size, win_condition>::Game(){

    if (win_condition > size){
        throw std::invalid_argument("You can not construct a game smaller than win_conditionn");
    } 

    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            this->board[i][j] = ' ';
        }
    }

    this->is_game_active = true;
}


template <uint16_t size, uint16_t win_condition>
void Game<size, win_condition>::display(){

    for (int i = 0; i < size; ++i){

        for (int j = 0; j < size; ++j){
            std::cout << '|' << this->board[i][j];
            if (j==size-1) std::cout << '|';
        }

        std::cout << std::endl;

        for (int j = 0; j < size; ++j){
            std::cout << "--";
        }

        std::cout << std::endl;
    }
}

template <uint16_t size, uint16_t win_condition>
void Game<size, win_condition>::player_move(){
    int column;
    int row;
    bool input_mode = true;

    while(input_mode){
        try{
            std::cout << "give column number 0 - " << size-1 << ":" <<std::endl;
            std::cin >> column;
            std::cout << "give row number 0 - " << size-1 << ":" <<std::endl;
            std::cin >> row;
            input_mode = this->validate_input(column, row);

        }
        catch (std::invalid_argument& e){
            std::cout << "invalid inputs, try again" << std::endl;
            continue;
        }
    }
    this->board[row][column] = 'x';
}

template <uint16_t size, uint16_t win_condition>
bool Game<size, win_condition>::validate_input(int &column, int &row){
    if (column < 0 || column > size) throw std::invalid_argument("incorect argument");
    if (row < 0 || row > size) throw std::invalid_argument("incorect argument");

    if (this->board[row][column] != ' ') throw std::invalid_argument("non empty square");
    return false;
}

template <uint16_t size, uint16_t win_condition>
void Game<size, win_condition>::game_loop(){

    this->ai_move();
    this->display();
    while(is_game_active){
        this->player_move();
        if(this->validate_win_condition() == GAME_IS_ACTIVE){
            this->is_game_active = true;
        }else{
            this->is_game_active = false;
            break;
        }



        this->ai_move();
        this->display();
        if(this->validate_win_condition() == GAME_IS_ACTIVE){
            this->is_game_active = true;
        }else{
            this->is_game_active = false;
            break;
        }
    } 
    std::cout << "the end";
}

template <uint16_t size, uint16_t win_condition>
void Game<size, win_condition>::ai_move(){
    int depth;
    if (size == 3){
        depth = 11;
    }else if(size < 6){
        depth = 4;
    }else{
        depth = 3;
    }
    Move move = get_best_move(1, depth);
    this->board[move.row][move.column] = 'o';
   
}

template <uint16_t size, uint16_t win_condition>
end_game_conditiond Game<size, win_condition>::validate_win_condition(){
    // true -> end ga

    //1eft - right
    bool is_win = false;
    for (int column = 0; column < size-win_condition+1; ++column){
        for (int row = 0; row < size; ++row){
            if(this->board[row][column] != ' '){
                is_win = true;
                for(int k = 1; k < win_condition; ++k){
                    if (this->board[row][column] != this->board[row][column+k]){
                        is_win = false;
                    }
                }
                if (is_win){
                    if (this->board[row][column] == 'x'){
                        return PLAYER_WIN;
                    }else {
                        return AI_WIN;
                    }
                }
            }
        }
    }

    //up - down
    for (int column = 0; column < size; ++column){
        for (int row = 0; row < size-win_condition+1; ++row){
            if(this->board[row][column] != ' '){
                is_win = true;
                for(int k = 1; k < win_condition; ++k){
                    if (this->board[row][column] != this->board[row+k][column]){
                        is_win = false;
                    }
                }
                if (is_win){
                    if (this->board[row][column] == 'x'){
                        return PLAYER_WIN;
                    }else {
                        return AI_WIN;
                    }
                }
            }
        }
    }

    // verticaly 1
    for (int column = 0; column < size-win_condition+1; ++column){
        for (int row = 0; row < size-win_condition+1; ++row){
            if(this->board[row][column] != ' '){
                is_win = true;
                for(int k = 1; k < win_condition; ++k){
                    if (this->board[row][column] != this->board[row+k][column+k]){
                        is_win = false;
                    }
                }
                if (is_win){
                    if (this->board[row][column] == 'x'){
                        return PLAYER_WIN;
                    }else {
                        return AI_WIN;
                    }
                }
            }
        }
    }

    // verticaly 2
    for (int column = size; column > win_condition-2; --column){
        for (int row = 0; row < size-win_condition+1; ++row){
            if(this->board[row][column] != ' '){
                is_win = true;
                for(int k = 1; k < win_condition; ++k){
                    if (this->board[row][column] != this->board[row+k][column-k]){
                        is_win = false;
                    }
                }
                if (is_win){
                    if (this->board[row][column] == 'x'){
                        return PLAYER_WIN;
                    }else {
                        return AI_WIN;
                    }
                }
            }
        }
    }

    //is game active check
    for (int column = 0; column < size; ++column){
        for (int row = 0; row < size; ++row){
            if(this->board[row][column] == ' '){
                return GAME_IS_ACTIVE;
            }
        }
    }
    
    return TIE;
}

template <uint16_t size, uint16_t win_condition>
Move Game<size, win_condition>::get_best_move(int player, int depth){
    
    end_game_conditiond rv = this->validate_win_condition();

    int blank_spaces = 0;
    for(int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if(this->board[i][j] == ' ') blank_spaces++;
        }
    }

    int middle_bonus = 0;
    if (this->board[size/2][size/2] == 'o') middle_bonus = 4;

    if(rv == AI_WIN){
        return Move(2*blank_spaces * middle_bonus);
    }else if(rv == PLAYER_WIN){
        return Move(-2*blank_spaces);
    }else if (rv == TIE){
        return Move(0);
    }

    if (depth <= 0 ){
        return Move(0);
    }
    depth--;

    std::vector<Move> moves;
    // Do recursive
    for(int column = 0; column < size; ++column){
        for(int row = 0; row < size; ++row){
            if(this->board[row][column] == ' '){
                Move move;
                move.column = column;
                move.row = row;
                //board set value
                //if player is person
                if(player == 0){
                    this->board[row][column] = 'x';
                    move.score = get_best_move(1, depth).score;
                    moves.push_back(move);
                    this->board[row][column] = ' ';
                    
                }else{
                    this->board[row][column] = 'o';
                    move.score = get_best_move(0, depth).score;
                    moves.push_back(move);
                    this->board[row][column] = ' ';         
                }
                
            }
        }
    }
    // pick the best score
    int bestMove = 0;
    if(player == 1){
        int bestScore = INT16_MIN;
        for (int i = 0; i < moves.size(); ++i){
            if(moves[i].score > bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }else{
        int bestScore = INT16_MAX;
        for (int i = 0; i < moves.size(); ++i){
            if(moves[i].score < bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }

    }
    return moves[bestMove];
}
