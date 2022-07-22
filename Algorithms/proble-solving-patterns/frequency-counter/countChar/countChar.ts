// count number of charactures of a given string
// 给定一个字符串，统计其中出现的字符(英文字母、数字，不含其他字符)数量

type result = {
	[char: string]: number;
}

// function countChar(str: string): result {
// 	let result = {} as result;

// 	for(let i=0; i<str.length; i++) {
// 		let char = str[i].toLowerCase();

// 		if(isAlphaNumberic(char)) {
// 			if (result[char] > 0) {
// 				result[char]++;
// 			} else {
// 				result[char] = 1;
// 			}
// 		}

// 	}

// 	return result;
// }

function isAlphaNumberic(char: string): boolean {
	const code = char.charCodeAt(0);
	if(code >= 48 && code <= 57
		|| code >= 97 && code <= 122
		|| code >= 65 && code <= 90)
	{
		return true;
	} else return false;
}

// updated version
// use for..of instead of for loop
function countChar(str: string): result {
	let result = {} as result;

	for(let char of str) {
		if(isAlphaNumberic(char)) {
			if (result[char] > 0) {
				result[char]++;
			} else {
				result[char] = 1;
			}
		}
	}

	return result;
}