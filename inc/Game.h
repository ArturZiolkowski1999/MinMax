# pragma once
# include <array>
# include <iostream>

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

    while(is_game_active){
        this->player_move();
        this->ai_move();
        this->is_game_active = this->validate_win_condition();
    } 
}

template <uint16_t size, uint16_t win_condition>
void Game<size, win_condition>::ai_move(){

   
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
    for (int column = size; column > win_condition-1; --column){
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

