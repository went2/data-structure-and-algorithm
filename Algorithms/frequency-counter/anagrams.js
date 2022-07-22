/**
 * function validAnagram(str1: string, str2: string): boolean
 * return true if str2 is an anagram of str1.
 * cinema is anagram of iceman
 *
 * eg:
 * validAnagram('', ''); // true
 * validAnagram('aaz', 'zza'); // false
 * validAnagram('anagram', 'nagaram'); // true
 * validAnagram('qwerty', 'qeywrt'); // true
 */

// 分析：第二个 string 中出现的字符种类与数量是否与第一个相同

function validAnagram(str1, str2) {
  if (str1 === '' && str2 === '') return true;

  let freqCounter1 = {};
  let freqCounter2 = {};

  for (let char of str1) {
    freqCounter1[char] = (freqCounter1[char] || 0) + 1;
  }
  for (let char of str2) {
    freqCounter2[char] = (freqCounter2[char] || 0) + 1;
  }

  for (let key in freqCounter1) {
    if (!(key in freqCounter2)) return false;
    if (freqCounter1[key] !== freqCounter2[key]) return false;
  }
  return true;
}

console.log(validAnagram('', '')); // true
console.log(validAnagram('aaz', 'zza')); // false
console.log(validAnagram('anagram', 'nagaram')); // true
console.log(validAnagram('qwerty', 'qeywrt')); // true