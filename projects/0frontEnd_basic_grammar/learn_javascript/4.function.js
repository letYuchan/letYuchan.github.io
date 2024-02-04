// 함수의 선언과 호출
function dev(num1, num2) {
  return num1 / num2;
}

const result1 = dev(4, 3);
console.log(result1);

// parameter 다루기: default parameter
function add(num1 = 1, num2 = 2) {
  return num1 + num2;
}
const result = add(3, 5);
console.log(add); // 8 -> 우선순위는 인자로 넘겨주는 값이 기본 파라미터보다 더 높다

// parameter 다루기: rest 변수-> 인자들을 배열로 보관
function createShoppingList(...items) {
  console.log('구매 목록:');
  for (let item of items) {
    console.log('- ' + item);
  }
}

createShoppingList('사과', '바나나', '우유');
createShoppingList('치즈', '빵', '계란', '야채', '우유');

// 무명함수
let multi = function (a, b) {
  return a * b;
};
console.log(multi(3, 3));

// 화살표 함수
minus = (a, b) => a - b; // return 없을때만 일렇게 사용가능 아니라면 {}로 묶어야함
console.log(minus(4, 3));

//  callback function: 함수를 인자로 받는  함수
function calculator(a, b, action) {
  let result = action(a, b);
  console.log(result);
}

calculator(3, 4, add);
calculator(6, 4, dev);
