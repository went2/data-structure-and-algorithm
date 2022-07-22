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

function validAnagram1(str1, str2) {
  if (str1.length !== str1.length) return false;

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

// explicitly use for loop
function validAnagram2(str1, str2) {
  const l1 = str1.length, l2 = str2.length;
  if (l1 !== l2) return false;

  let lookup = {}

  for (let i = 0; i < l1; i++) {
    char = str1[i];
    lookup[char] ? lookup[char] += 1 : lookup[char] = 1;
  }

  for (let i = 0; i < l1; i++) {
    char = str2[i];
    if (!lookup[char]) return false;
    else lookup[char] -= 1;
  }
  return true;
}


console.log(validAnagram2('', '')); // true
console.log(validAnagram2('aaz', 'zza')); // false
console.log(validAnagram2('anagram', 'nagaram')); // true
console.log(validAnagram2('qwerty', 'qeywrt')); // true