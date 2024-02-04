// symbol: 너는 유니크해진다.

const key1 = Symbol('key'); // 이름표가 같아도 Symbol로 각각 지정해주면 두갠 다른거다
const key2 = Symbol('key');
console.log(key1 === key2);

// 전역심볼: 이름표가 같으면 너네들은 다 똑같아

const k1 = Symbol.for('key');
const k2 = Symbol.for('key');
console.log(k1 === k2); // true

// 심볼의 잉름표 알아내기
console.log(Symbol.keyFor(key1)); // 못알아냄 -> 심볼의 접근제어!
console.log(Symbol.keyFor(k1));

// obj에서 심볼 특징 살려보기(유일성, 캡슐화)
const obj = { [k1]: 'hello', [Symbol('key')]: 1 }; //변수에 담지 않고 곧바로 만들기 가능

console.log(obj); // { [Symbol(key)]: 'hello', [Symbol(key)]: 1 }
console.log(Object.keys(obj)); // []
console.log(obj[k1]); // hello
console.log(obj[Symbol('key')]); // undefined : 여기서의 key와 위에서 선언해준 key는 엄연히 다르다.
// 아까 가장 첫번째 예제에서도 같은 이름표지만 다르게 인식했잖아!

// 굳이굳이 symbol로 정의돈 key값을 알아보고싶다면?
console.log(Object.getOwnPropertySymbols(obj));
