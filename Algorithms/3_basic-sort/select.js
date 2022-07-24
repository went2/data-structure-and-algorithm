/**
 * function selectSort(arr: number[]): number[]
 * 选择排序，每轮遍历，将最小的值放到最前面
 */

function selectSort(arr) {
    const len = arr.length;
    for (let i = 0; i < len; i++) { // 控制遍历轮次
        let minIndex = i;

        for (let j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 每轮遍历结束后才知道该轮的最小值是几号
        // swap
        [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    }

    console.log(arr);
    return arr;
}

// pratices on the next day
function selectSort2(arr) {
    const len = arr.length;
    let minIndex;

    for (let i = 0; i < len; i++) {
        minIndex = i; // 每轮开始时，将首位设为最小值开始比较
        for (let j = i + 1; j < len; j++) { // 比较是为了获得本轮最小值的index
            if (arr[j] < arr[i]) {
                minIndex = j;
            }
        }
        // swap
        [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    }
    console.log(arr);
    return arr;
}

selectSort2([12, 2, 45, 55, 63, 1, -88, -3, 43, 5, 86]);
selectSort2([10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1]);