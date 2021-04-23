#include <iostream>
#include "ttt.hpp"

int main() {
    std::vector<char> grid = {'1', '2', '3','4', '5', '6','7','8', '9'};
    bool game_ended = false;
    int spaces_left = 9;
    int winner = 0;
    int player = 1;
    int choice;
   
    
    while (!game_ended) {
        display_grid(grid);
        std::cout << "Player " << player << "'s turn. press the number of the position you want to confiscate.\n";
        choice = get_choice(grid);
        grid[choice - 1] = player==1?'O':'X';

        winner = check_winner(grid, player);
        if (winner != 0) {
            game_ended = true;
        } else {
            player = player ==1? 2:1;
            spaces_left--;
            game_ended = spaces_left >= 1? false:true;
        }
    }
    display_grid(grid);
    if (winner == 0) {
        std::cout << "It's a draw!\n";
    } else {
        std::cout << "Player " << winner << " won the game!\n\n";
    }
    return 0;
}