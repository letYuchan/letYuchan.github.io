// 배열 생성1: 생성자함수
let array1 = Array(3);
console.log(array1);

// static 함수
let array2 = Array.of(1, 2);
console.log(array2);

let array3 = [1, 2, 3];
console.log(array3);

// 배여 복사
array3 = Array.from(array2);
console.log(array3);

// 아이템 참조 그리고 추가와 삭제
array4 = ['apple', 'banana', 'orange', 'grape'];
console.log(array4.indexOf('apple'));

array4.pop();
console.log(array4);

let item1 = array4.shift();
console.log(item1);
console.log(array4);

let array5 = array1.concat(array4);
console.log(array5);

let array6 = [1, 2, 3, 4, 5, 6, 7, 8, 9];
let array7 = array6.slice(2, 6); // 자르고 새로운 배여로 탄생
console.log(array7);

let array8 = ['one', 'two', 'three', 'four'];
array8.splice(1, 1, 'not num'); // (아 안댁스부터, 얼만큼 삭제할지 정하고, 그 뒤에 샐로운 아이템을 추가)
console.log(array8);

// 배열의 고차함수
const numbers = [1, 3, 5, 6, 16, 7, 4, 7];
numbers.sort((a, b) => a - b); // 오름차순
console.log(numbers);
numbers.sort((a, b) => b - a); // 내림차순
console.log(numbers);

const numbers2 = [1, 3, 5, 6, 2, 7, 8, 9, 12];

let newNumbers2 = numbers2.filter((item) => item > 5); // 5이상의 item으로 새로운 배열 생성
console.log(newNumbers2);
