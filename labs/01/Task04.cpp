#include <iostream>

using namespace std;

int maxArea(int height[], int n) {
    int maxWater = 0;

    for (int left = 0; left < n - 1; left++) {
        for (int right = left + 1; right < n; right++) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);
        }
    }

    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, n);

    cout << "Output: " << result <<endl;

    return 0;
}
