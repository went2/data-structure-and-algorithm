/**
 * function sumZero(arr: number[]): number[] | undefined
 * given a sorted array of intgers, find the first pair where the sum is 0.
 * return the array of the pair or undefined if a pair does note exit.
 * 
 * eg.
 * sumZero([-3, -2, -1,0,1,2,3]) // [-3,3]
 * sumZero([-1,0,1,2,3]) // [-1,1]
 * sumZero([0,1,2,3]) // undefined
 */

// nested loop version
// 拿第一个数依次加上剩下的数，看是否等于0；拿第二数依次加剩下的数，看是否是0...
function sumZero1(arr) {
  const len = arr.length;

  for (let i = 0; i < len; i++) {
    for (let j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] === 0) {
        console.log([arr[i], arr[j]]);
        return [arr[i], arr[j]];
      }
    }
  }
  return;
}

// use double pointer to loop
// 首尾互加，大于0，右边的 pointer 向左移，继续加；
function sumZero2(arr) {
  let left = 0;
  let right = arr.length - 1;
  while (left < right) {
    let sum = arr[left] + arr[right];
    if (sum === 0) {
      return [arr[left], arr[right]];
    } else if (sum > 0) {
      right--;
    } else {
      left++;
    }
  }
}

sumZero1([-3, -2, -1, 0, 1, 2, 3]);
sumZero1([-1, 0, 1, 2, 3]);
sumZero1([0, 1, 2, 3]);

