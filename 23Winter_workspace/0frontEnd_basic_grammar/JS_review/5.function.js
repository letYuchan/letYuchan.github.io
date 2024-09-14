// 함수의 선언과 호출
function add(num1, num2) {
    return num1 + num2;
}

const result = add(1, 2);
console.log(result);

function implicityReturn() { } 

console.log(implicityReturn()); // 암묵적으로 return값이 없다면 undefined를 반환

function sub(num1 = 0, num2 = 0) { // 기본파라미터 설정가능, 단 우선순위는 호출 시 전달해준 인자의 값이 우선
    return num1 - num2;
}

console.log(sub()); // 0

function shoppingList(...items) { // 파라미터의 개수를 세기 힘들때 사용하는 rest 매개변수
    console.log("구매 목록: ");
    for (let item of items) {
        console.log("-" + item);
    }
}

shoppingList("사과", "바나나", "땔기");

console.log(add()); // 기본파라미터가 설정되지 않은 함수에 인자를 넘겨주지 않는다면 undefined가 넘어가게 되고 결국 NaN가 반환

// 함수의 표현식1: 무명함수
let addFunction = function (a, b) {
    return a + b;
}
console.log(addFunction(2, 4));

// 함수의 표현식2: 화살표함수
let mulFunction = (a, b) => a * b;
console.log(mulFunction(3, 4));