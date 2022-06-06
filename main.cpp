#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    int numberOfBuildings;
    int numberOfPosters = 0;

    std::cin >> numberOfBuildings;
    int previousHeight = -1;
    int currentHeight;


    std::stack<int> nonPlacedYetPosters;

    for (int i = 0; i < numberOfBuildings; ++i) {
        std::cin >> currentHeight;
        std::cin >> currentHeight;
        if (previousHeight < currentHeight) {
            nonPlacedYetPosters.push(currentHeight);
        }

        while (!nonPlacedYetPosters.empty() && (currentHeight < nonPlacedYetPosters.top())) {
            nonPlacedYetPosters.pop();
            numberOfPosters++;
        }
        if (nonPlacedYetPosters.empty() || currentHeight > nonPlacedYetPosters.top()) {
            nonPlacedYetPosters.push(currentHeight);
        }
        previousHeight = currentHeight;
    }
    std::cout << numberOfPosters + nonPlacedYetPosters.size();
}
