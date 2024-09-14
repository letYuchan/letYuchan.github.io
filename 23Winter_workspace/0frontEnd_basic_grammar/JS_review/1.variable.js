// var: 선언 및 초기화  -> 초기화 -> 할당, 재할당 및 재선언 가능
var a = 1
var a = 2 // 재선언 가능
a = 3 // 재할당 가능

console.log("var로 선언한 a의 값: ", a)

var b
console.log("var는 초기화가 undefined가 default value, b -> ", b);

for (var i = 0; i < 5; i++){
    console.log(i)
}
console.log("i는 for문이 scope일 것 같지만 실은 함수가 아닌 이상 전역변수로 작용, i -> ", i)


// let: 선언 -> TDZ -> 초기화 -> 할당, 재할당만 가능
let a2 = 1;
a2 = 2; // 재할당 가능
// let a = 3; // 재선언 불가능! 컴파일 에러 발생
console.log("a2: ", a2);
for (let i = 0; i < 5; i++){
    console.log(i);
}
// console.log(i) // 컴파일 에러! -> let은 블록스코프로 작용, 따라서 for문에서만 유효

// const: 재선언, 재할당 모두 불가능
const a3 = 9;
// const a = 3;
// a = 4 // 두 코드 모두 컴파일 에러 발생


// hoisting: 변수와 함수의 선언 부분만 해당하는 스코프의 최상단으로 끌어올리는 것

