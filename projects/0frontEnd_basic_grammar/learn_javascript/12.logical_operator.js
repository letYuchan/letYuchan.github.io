// 조건식(true or false)으로 활용되는 논리연산자
const obj1 = { num: 13, name: '김철수' };
const obj2 = { num: 15, name: '안철수' };
if (obj1 && obj2) {
  console.log('두 obj는 true이다.'); // 두 obj는 true이다.
}

//short-cut evaluation으로 활용되는 논리연산자
let result = obj1 && obj2; // &&: 둘다 true여야함 -> obj2까지 검사
console.log(result);
result = obj1 || obj2; // ||: 하나만 true여도 true -> obj1은 true니깐 전체적으로 true
console.log(result);
