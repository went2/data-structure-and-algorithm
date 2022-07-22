/**
 * same(arr1: number[], arr2: number[]): boolean;
 * retuens true if every value in arr2 has corresponding value squared of arr1.
 * the frequency of values must be the same
 *
 * same([1,2,3], [4,1,9]) // true
 * same([1,2,3], [1,9]) // false
 * same([1,2,1], [4,4,1]) // false (must be the same frequency)
 */

// first try: find and delete
// 遍历数组1，查找数组2中是否有对应的平方值，有则移除，遍历结束返回true。
function same(arr1, arr2) {
  const l1 = arr1.length, l2 = arr2.length;
  if (l1 !== l2) return false;

  for (let i = 0; i < l1; i++) {
    let index2 = arr2.findIndex(e => e === arr1[i] ** 2);

    if (index2 !== -1) {
      arr2.splice(index2, 1);
    }
    else return false;
  }
  return true;
}

console.log(same([1, 2, 3], [4, 1, 9]));
console.log(same([1, 2, 3], [1, 9]));
console.log(same([1, 2, 1], [4, 4, 1]));