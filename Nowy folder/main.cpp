#include <iostream>
#include <fstream>

int findMin(int size, int *howManyPosters, int heightAlreadyChecked) {
    int min = INT16_MAX;
    for (int i = 0; i < size; ++i) {
        if (howManyPosters[i] < min && howManyPosters[i] > heightAlreadyChecked)
            min = howManyPosters[i];
    }
    return min;
}

int main() {
    int howManyBuildings;
    int howManyPosters = 0;

    std::ifstream input("pla4b.in");

    input >> howManyBuildings;

    int heights[howManyBuildings];

    for (int i = 0; i < howManyBuildings; i++) {
        input >> heights[i];
        input >> heights[i];
    }

    int heightAlreadyChecked = 0;
    int currentHeight = findMin(howManyBuildings, heights, heightAlreadyChecked);


    bool keepGoing = true;
    while (keepGoing) {
        int nextMin = INT16_MAX;
        keepGoing = false;
        bool inARow = false;

        for (int i = 0; i < howManyBuildings; i++) {
            if ((heights[i] == currentHeight) & !inARow) {
                howManyPosters++;
                inARow = !inARow;
            }
            if ((heights[i] < currentHeight) & inARow) {
                inARow = !inARow;
            }

            if (heights[i] > currentHeight) {
                keepGoing = true;
                if (heights[i] < nextMin)
                    nextMin = heights[i];
            }
        }
        heightAlreadyChecked = currentHeight;
        currentHeight = nextMin;
    }

    std::cout << howManyPosters;
}
