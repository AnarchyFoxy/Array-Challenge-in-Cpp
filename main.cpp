#include <iostream>
#include <numeric>
#include <vector>

int array_challenge(std::vector<int>& arr) {
    int sum = std::accumulate(arr.begin(), arr.end(), 0);

    int fibonacci1 = 0, fibonacci2 = 1;
    int fibonacci_sum = 0;

    while (fibonacci_sum < sum) {
        fibonacci_sum = fibonacci1 + fibonacci2;
        fibonacci1 = fibonacci2;
        fibonacci2 = fibonacci_sum;
    }

    arr[0] = fibonacci_sum - sum;
    return arr[0];
}

int main() {
    // Test the function with the example input
    std::vector<int> arr = {15, 1, 3};
    int output = array_challenge(arr);
    std::cout << output << std::endl; // Output: 2

    return 0;
}
