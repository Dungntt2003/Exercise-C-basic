#include <stdbool.h>
#include <stdio.h>

bool canRemoveOneElement(int nums[], int n) {
    if (n < 2) {
        return true;
    }
	int i; 
    bool removed = false;
    for ( i = 1; i < n; i++) {
        if (nums[i] <= nums[i - 1]) {
            if (removed) {
                return false;
            }

            if (i == 1 || nums[i] > nums[i - 2]) {
                removed = true;
            } else if (i == n - 1 || nums[i + 1] > nums[i - 1]) {
                removed = true;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int nums[] = {1, 3,2,1};  // Ví d? m?ng nums
    int n = sizeof(nums) / sizeof(nums[0]);

    if (canRemoveOneElement(nums, n)) {
        printf("Co the tao duoc day tang nghiem ngat bang cach loai bo khong qua mot phan tu.\n");
    } else {
        printf("Khong the tao duoc day tang nghiem ngat bang cach loai bo khong qua mot phan tu.\n");
    }

    return 0;
}

