//Leet-Code Hard Problem
//https://leetcode.com/problems/median-of-two-sorted-arrays/
//A very clever solution based upon the use of stack and exploiting the fact that both arrays/vectors are sorted

#include <iostream>
#include <vector>
#include <cmath>


class Solution {
private:
    double computeMedian(std::vector<int> &sortedArray){
        //Computing median the standard way
        if ((sortedArray.size() % 2) == 0){ //If list is made up of even number of elements
            const int index_offset_fix = 1;

            const unsigned long index_a = floor(sortedArray.size()/2.0f);
            const unsigned long index_b = index_a + 1;
            return (sortedArray[index_a-index_offset_fix] + sortedArray[index_b - index_offset_fix]) / 2.0f;
        }else{ //If list is made up of odd number of elements
            return sortedArray[floor(sortedArray.size()/2.0f)];
        }
    }

    void sortedArrayMerger(std::vector<int> &nums1, std::vector<int> &nums2, std::vector<int> &sortedArray){
        const unsigned long nums1_size = nums1.size();
        const unsigned long nums2_size = nums2.size();
        unsigned long nums1_index = 0, nums2_index = 0;
        unsigned long i = 0;

        //Merging two sorted vectors into a single large vector
        while ((nums1_index < nums1_size) && (nums2_index < nums2_size)){
            if (nums1[nums1_index] < nums2[nums2_index])
                sortedArray.at(i++) = nums1[nums1_index++];
            else
                sortedArray.at(i++) = nums2[nums2_index++];
        }

        if (nums1_index + 1 > nums1_size){ //All elements from num1_vector already sorted and are inside sortedArray, go for insertion from num2_vector
            for (unsigned long j = nums2_index; j < nums2_size; ++j)
                sortedArray.at(i++) = nums2[j];
        }else{
            for (unsigned long j = nums1_index; j < nums1_size; ++j)
                sortedArray.at(i++) = nums1[j];
        }

    }
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        //Base case check if one of the vectors is empty
        if (nums1.size() == 0) return this->computeMedian(nums2);
        if (nums2.size() == 0) return this->computeMedian(nums1);

        std::vector<int> sortedArray(nums1.size() + nums2.size());
        //Go for smart merge and then compute median
        this->sortedArrayMerger(nums1, nums2, sortedArray);

        return this->computeMedian(sortedArray);
    }
};
int main() {

    Solution _solution;
    //Init vector 1
    std::vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);

    //init vector 2
    std::vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(4);


    double median  = _solution.findMedianSortedArrays(nums1, nums2);
    std::cout << median << std::endl;
    return 0;
}
