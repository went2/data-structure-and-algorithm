/**
 * function maxSubarraySum(arr: number[], n: number): number
 * 
 * given an array of integers, return max sum of n consecutive elements in the array.
 * 给定一个数组及长度n，返回数组中连续个n元素相加的最大值
 * 
 * eg.
 * maxSubarraySum([1,2,5,2,8,1,5], 2); // 10
 * maxSubarraySum([1,2,5,2,8,1,5], 4); // 17
 * maxSubarraySum([4,2,1,6,2], 4); // 13
 * maxSubarraySum([], 2); // null
 */

function maxSubarraySum(arr, n) {
    const len = arr.length;
    if (n > len) return null;

    let tempSum = 0;
    let maxSum = 0;
    for (let i = 0; i < n; i++) {
        maxSum += arr[i];
    }
    tempSum = maxSum;

    for (let i = n; i < len; i++) {
        tempSum = tempSum + arr[i] - arr[i - n];
        maxSum = Math.max(tempSum, maxSum);
    }

    console.log(maxSum);
    return maxSum;
}

maxSubarraySum([1, 2, 5, 2, 8, 1, 5], 2); // 10
maxSubarraySum([1, 2, 5, 2, 8, 1, 5], 4); // 17
maxSubarraySum([4, 2, 1, 6, 2], 4); // 13
maxSubarraySum([], 2); // null