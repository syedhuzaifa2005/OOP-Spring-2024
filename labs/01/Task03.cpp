#include <iostream>
using namespace std;

void twoSum(const int nums[], int length, int target, int& index1, int& index2) {
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (nums[i] + nums[j] == target) {
                index1 = i;
                index2 = j;
                return;
            }
        }
    }

    index1 = -1;
    index2 = -1;
}

int main() {
    int length = 0;
    cout<< "Enter the size of the array: ";
    cin>> length;
	int nums[length];
	int target = 0;
	cout<< "Enter the target number: ";
	cin>> target;
	for(int i = 0; i < length; i++){
		cout<<"Enter "<<i+1<<" element: ";
		cin>> nums[i];
	}
	
    int index1, index2;
    twoSum(nums, length, target, index1, index2);

    if (index1 != -1 && index2 != -1) {
        std::cout << "Output: [" << index1 << ", " << index2 << "]" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
