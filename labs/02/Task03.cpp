/*
Programmer: Syed Huzaifa Ali
Roll no: 23K-0004
Description: Achieving a target sum from the elements of an array using recursions
*/


#include <iostream>

using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum);

int main(){
    int arr[] = {3, 4, 6, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 8;
    
    if(hasSubsetSum(arr, size, targetSum)){
        cout<< "Subset with target sum " << targetSum << " exists" << endl;
    }
    else{
        cout<< "Subset with target sum " << targetSum << " doesnot exist" << endl;
    }

    return 0;
}


bool hasSubsetSum(int arr[], int size, int targetSum){
    if(targetSum == 0){
        return true;
    }
    if(size == 0  &&  targetSum != 0){
        return false;
    }

    if(arr[size - 1] > targetSum){
        return hasSubsetSum(arr, size - 1, targetSum);
    }
    else{
        return hasSubsetSum(arr, size - 1, targetSum)  ||
               hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]);
    }
}




