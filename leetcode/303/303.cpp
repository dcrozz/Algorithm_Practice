/*
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 */

class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        for ( int num : nums)
        {
            sums.push_back(sums.back() + num);
        }
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
