/**
 * function same(arr1: number[], arr2: number[]): boolean;
 * retuens true if every value in arr2 has corresponding value squared of arr1.
 * the frequency of values must be the same
 *
 * same([1,2,3], [4,1,9]) // true
 * same([1,2,3], [1,9]) // false
 * same([1,2,1], [4,4,1]) // false (must be the same frequency)
 */

const { calcTime } = require('../calcTime.js');

// first try: find and delete
// 遍历数组1，查找数组2中是否有对应的平方值，有则移除，遍历结束返回true。
// 嵌套循环 O(n^2)
function same1(arr1, arr2) {
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

// 使用 object
// 多个独立的 loop 比多个嵌套的 loop 好，前者按加法算复杂度，后者按乘法算
function same2(arr1, arr2) {
	if (arr1.length !== arr2.length) return false;
	let frequencyCounter1 = {};
	let frequencyCounter2 = {};

	for (let value of arr1) {
		frequencyCounter1[value] = (frequencyCounter1[value] || 0) + 1;
	}
	for (let value of arr2) {
		frequencyCounter2[value] = (frequencyCounter2[value] || 0) + 1;
	}

	for (let key in frequencyCounter1) {
		if (!(key ** 2 in frequencyCounter2)) return false;
		if (frequencyCounter1[key] !== frequencyCounter2[key ** 2]) return false;
	}
	return true;
}


calcTime(same1, 'same1')([1, 2, 3], [4, 1, 9]);
calcTime(same2, 'same2')([1, 2, 3], [4, 1, 9]);

calcTime(same1, 'same1')([1, 2, 3], [1, 9]);
calcTime(same2, 'same2')([1, 2, 3], [1, 9]);

calcTime(same1, 'same1')([1, 2, 3, 4, 5, 9, 8], [4, 1, 9, 25, 16, 64, 81]);
calcTime(same2, 'same2')([1, 2, 3, 4, 5, 9, 8], [4, 1, 9, 25, 16, 64, 81]);
