// 제너레이터 구현하기
function* fn() {
  yield 1;
  yield 2;
  yield 3;
}

const generator = fn();
console.log(generator);
console.log(generator.next()); // { value: 1, done: false }
console.log(generator.next()); // { value: 2, done: false }
console.log(generator.next()); // { value: 3, done: false }
console.log(generator.next()); // { value: undefined, done: true}

// return 활용하기
function* fn2() {
  yield 1;
  yield 2;
  return 3; // 이것을 만나면 이 아래로는 실행 x -> 순회 끝나버림
  yield 4;
}

const generator2 = fn2();

console.log(generator2.next()); // { value: 1, done: false }
console.log(generator.next()); // { value: 2, done: false }
console.log(generator.next()); // { value: 3, done: true }
console.log(generator.next()); // { value: undefined, done: true }

function* generatorFunction() {
  try {
    yield 1;
    yield 2;
  } catch (e) {
    yield `Error: ${e}`;
  }
}

const generator2 = generatorFunction();
console.log(generator2.next()); // { value: 1, done: false }

try {
  generator2.throw('Something went wrong'); // 'throw'를 통해 예외 발생
} catch (e) {
  console.log(e); // 외부에서 예외를 캐치하여 처리
}

console.log(generator2.next()); // { value: 'Error: Something went wrong', done: false }
console.log(generator2.next()); // { value: undefined, done: true }
