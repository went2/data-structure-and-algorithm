/**
 * function insertionSort(arr: number[]): number[]
 */

function insertionSort(arr) {
    const len = arr.length;

    for (let i = 0; i < len; i++) {
        for (let j = i + 1; j > 0; j--) { // 依次和左边已排序的进行比较
            if (arr[j] < arr[j - 1]) {
                [arr[j], arr[j - 1]] = [arr[j - 1], arr[j]];
            }
        }
    }
    console.log(arr);
    return arr;
}

insertionSort([12, 2, 45, 55, 63, 1, -88, -3, 43, 5, 86]);
insertionSort([10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1]);