#include <iostream>
#include <fstream>
#include <stack>

int findMin(int size, int *howManyPosters, int heightAlreadyChecked) {
    int min = INT16_MAX;
    for (int i = 0; i < size; ++i) {
        if (howManyPosters[i] < min && howManyPosters[i] > heightAlreadyChecked)
            min = howManyPosters[i];
    }
    return min;
}

int main() {
    static int howManyBuildings;
    int howManyPosters = 0;

    std::ifstream input("pla10b.in");

    input >> howManyBuildings;

    int heights[howManyBuildings];

    for (int i = 0; i < howManyBuildings; i++) {
    input >> heights[i];
    input >> heights[i];
    }

    std::stack<int> nonPlacedYetPosters;

    for (int i = 0; i < howManyBuildings; ++i) {
        if (i > 0) {
            if (heights[i - 1] < heights[i]) {
                nonPlacedYetPosters.push(heights[i]);
            }

            while (nonPlacedYetPosters.size() && (heights[i] < nonPlacedYetPosters.top()) > 0) {
                nonPlacedYetPosters.pop();
                howManyPosters++;
            }
        } else {
            nonPlacedYetPosters.push(heights[0]);
        }

    }


    std::cout << howManyPosters;
}
