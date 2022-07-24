/**
 * function bubbleSort(arr: number[]): number[]
 * 冒泡排序：两两比较，大的沉底
 */

// v1
function bubbleSort1(arr) {
    const len = arr.length;

    for (let i = len; i > 0; i--) {
        for (let j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
            }
        }
    }
    console.log(arr);
    return arr;
}

// v2
// 上面一种实现每次排序需要的时间是固定的，遇到那些差不多排好序的数组，怎么节省，少做比较？
// 增加一个变量 noSwaps 每一轮(共len-1轮)开始时设为 true，如果有一轮没有任何 swap，说明已经排好序，直接结束循环
function bubbleSort2(arr) {
    const len = arr.length;
    let noSwaps;

    for (let i = len; i > 0; i--) { // 控制轮次
        noSwaps = true;
        for (let j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
                noSwaps = false;
            }
        }

        if (noSwaps) break;
    }
    console.log(arr);
    return arr;
}

// practices
function bubbleSort3(arr) {
    const len = arr.length;
    let noSwaps;

    for (let i = len - 1; i > 0; i--) {
        noSwaps = true;
        for (let j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]
                noSwaps = false;
            }
        }
        if (noSwaps) break;
    }
    console.log(arr);
    return arr;
}

bubbleSort3([12, 2, 45, 55, 63, 1, -88, -3, 43, 5, 86]);