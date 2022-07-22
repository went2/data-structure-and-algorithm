/**
 * function countUniqueValues(arr: number[]): number
 * 
 * given a sorted array of integer, return the number of unique values in the array.
 * 
 * eg.
 * countUniqueValues([1,1,1,1,1,2]) // 2
 * countUniqueValues([1,2,3,3,3,4,7,7,12,12,13]) // 7
 * countUniqueValues([]) // 0
 * countUniqueValues([-2,-1,-1,0,1]) // 4
 */

// double pointer from left
function countUniqueValues(arr) {
	const len = arr.length;
	if (len === 0) return 0;

	const newArr = [];
	newArr.push(arr[0]);
	for (let i = 0, j = 1; j < len; j++) {
		if (arr[i] !== arr[j]) {
			i = j;
			newArr.push(arr[j])
		}
	}
	console.log(newArr.length);
	return newArr.length;
}


countUniqueValues([1, 1, 1, 1, 1, 2]) // 2
countUniqueValues([1, 2, 3, 3, 3, 4, 7, 7, 12, 12, 13]) // 7
countUniqueValues([]) // 0
countUniqueValues([-2, -1, -1, 0, 1]) // 4