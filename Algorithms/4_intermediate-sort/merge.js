/**
 * function mergeSort(arr: number[]): number[]
 * 
 */

function mergeSort(arr) {
    if (arr.length <= 1) return arr;
    const mid = Math.floor(arr.length / 2);
    const left = mergeSort(arr.slice(0, mid));
    const right = mergeSort(arr.slice(mid));
    return merge(left, right);
}

// 输入两个已排序的数组，合并它们，返回排序后的数组
// 要求时间复杂度O(n+m), 空间复杂度O(n+m),即每个item在每个数组中只被遍历一次(没有嵌套遍历)
// 要用两个 index
function merge(arr1, arr2) {
    let i = 0, j = 0;
    const len1 = arr1.length;
    const len2 = arr2.length;

    const newArr = [];

    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            newArr.push(arr1[i]);
            i++;
        } else {
            newArr.push(arr2[j]);
            j++;
        }
    }
    // 说明 arr2 已被合并，arr1 还有元素
    if (i < len1) newArr.push(...arr1.slice(i));
    else if (j < len2) newArr.push(...arr2.slice(j));
    return newArr;
}

// merge([-2, 0, 2, 5, 7, 21], [3, 5, 8, 9, 44, 67]);
// merge([-2, 0, 2, 5, 7, 21], [3, 5, 8, 9, 44, 67, 89]);
const sorted = mergeSort([44, 3, 89, 0, 5, 8, -2, -4, 9, 67, -34]);
console.log(sorted);