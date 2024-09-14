// 단축평가: 이미 조건에 부합하는 경우 더이상 표현식을 평가하지 않음
// 활용연산자: 논리연산자(단일부호 비트연산자 제외)
const obj1 = {name:'김병호'};
const obj2 = {name:'안철수'};
let result = obj1 && obj2 // and연산자는 모두 검사하기 때문에 obj2까지 검사하고 obj2가 변수에 담김
console.log(result);
result = obj1 || obj2 // or연산자는 하나라도 true면 true기 때문에 obj1이 true이므로 obj1이 변수에 담김
console.log(result);

// 단축평가활용예: null과 undefined 확인할 때
const obj3 = undefined;
const isItUndefined = obj3 && obj1; // &&는 앞이 falshy한 값이면 바로 할당가능하므로 이런식으로 활용
console.log(isItUndefined);

// 예시2: 파라미터 기본값 

function print(message = 'hi') {
    const text = message || 'Hello';
    console.log(text);
  }
  // 인자를 전달하지 않거나, undefined을 전달한 경우: 기본값 출력
  print(); // hi
  print(undefined); // hi
  // 전달한 값이 falshy 한 경우: || 연산에 따른 기본값을 따른다
  print(null); // Hello
  print(0); // Hello

