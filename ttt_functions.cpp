#include <iostream>
#include <vector>

void display_grid(std::vector<char> grid) {
std::cout << "   |   |   \n";
    std::cout << " " << grid[0] << " | " << grid[1] << " | " << grid[2] << " \n";
    std::cout << "   |   |   \n";
    std::cout << "-----------\n";
    std::cout << "   |   |   \n";
    std::cout << " " << grid[3] << " | " << grid[4] << " | " << grid[5] << " \n";
    std::cout << "   |   |   \n";
    std::cout << "-----------\n";
    std::cout << "   |   |   \n";
    std::cout << " " << grid[6] << " | " << grid[7] << " | " << grid[8] << " \n";
    std::cout << "   |   |   \n";
std::cout << "\n\n";
}

int check_winner(std::vector<char> grid, int player) {
    std::vector<std::vector<int>> winconditions = { {0, 1, 2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {1,4,8}, {2,4,6} };
    for (int i = 0; i < winconditions.size(); i++) {
        if (grid[winconditions[i][0]]!= ' ' && grid[winconditions[i][0]] == grid[winconditions[i][1]] && grid[winconditions[i][0]] == grid[winconditions[i][2]]) {
            return player;
        }
    }
    return 0;
}

int get_choice(std::vector<char> grid) {
    int choice = 0;
    std::cin >> choice;
    std::cout << "current choice: " << choice <<"\n";
    if (choice > 9 || choice < 1 || grid[choice-1] == 'O' || grid[choice-1] == 'X') {
        std::cout << "\n\nInvalid choice, please, choose again.\n";
        display_grid(grid);
        while (choice > 9 || choice < 1 || grid[choice-1] == 'O' || grid[choice-1] == 'X') {
            std::cin >> choice;
        }
    }
    return choice;
}