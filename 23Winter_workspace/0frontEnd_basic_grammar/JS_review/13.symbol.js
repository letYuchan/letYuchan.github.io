// symbol: 그 의미를 잘 해석해보자, 심볼 == 상징 == 유일한 것, 따라서 key값으로 주로 이용됨
let key1 = Symbol('쓸모없는 key1');
let key2 = Symbol('쓸모없는 key1');
console.log(key1);
console.log(key1 === key2); // ()안에 들어가는 문자열은 symbol(key)값을 설명해주는 역할 -> 심볼자체에 영향x -> 이 부분은 다른 심볼과 겹쳐도 상관없음

// global symbol: sytmbol.for() -> 깉은 설명 네용은 곧 같은 변수로 취급
let key3 = Symbol.for('key3===key4');
let key4 = Symbol.for('key3===key4');
console.log(key3 === key4); // true: 설명부분이 같기 때문

// symbol을 쓰는 이유: 보안성 높여줌
console.log(Symbol.keyFor(key1)); // 비전역 심볼: 설명부분 출력x -> undefined
console.log(Symbol.keyFor(key3)); // 전역 심볼: 출력o

// symbol을 쓰는 이유 for detail ver
const k1 = Symbol.for('key1');
const obj = { [k1]: 'hello', [Symbol('key')]: 'bye' };
console.log(obj);
console.log(obj[k1]); // 전
console.log(obj[Symbol('key')]); // 전역심볼이 아니니 value를 출력할 수 없어
console.log(Object.keys(obj)); // 출력안해줌 -> Symbol의 접근불가능성 특징
console.log(Object.getOwnPropertySymbols(obj)); // 정 알고싶으면 이 함수를 쓰면 돼

const array = [1, 2,1, 3, 4, 5];
let setA = new Set(array);
console.log(array);
