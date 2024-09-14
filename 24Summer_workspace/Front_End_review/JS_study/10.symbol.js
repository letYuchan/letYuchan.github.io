// symbol: 상징? -> 유일무이 해짐
let key1 = Symbol('key');
let key2 = Symbol('key');
console.log(key1 == key2);

// 전역심볼: Symbol.for()
let k1 = Symbol.for('key');
let k2 = Symbol.for('key');
console.log(k1==k2);

// 코드보완성을 높여주는 symbol
console.log(Symbol.keyFor(key1));

// symbol 값 알아내기
const k3 = Symbol('안녕')
const obj = { [k3] : "hello", [Symbol('일')] : 1};
console.log(Object.getOwnPropertySymbols(obj)); // [ Symbol(안녕), Symbol(일) ]