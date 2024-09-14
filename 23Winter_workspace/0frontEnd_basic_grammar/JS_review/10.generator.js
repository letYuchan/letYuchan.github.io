// generator: 일반적으로 함수를 호출하면 제어권은 함수에게 있지만, 이를 사용하여 제어권을 호출자가 갖게 함.
// 제너레이터는 iterable protocol을 따름

function* fn() {
    yield 1; // yield -> 통제 가능한 객체를 반환
    yield 2; 
    yield 3;
    return 4; // 이 아래부턴 코드 실행x, 함수를 종료시킴
    yield 5;
}

const generator = fn();
console.log(generator); // Object [Generator]{} -> 처음에는 빈 제너레이터 객체를 할당받고
console.log(generator.next()); // { value: 1, done: false } -> next함수에 의해 yield가 반환하는 새 객체를 할당받는다
console.log(generator.next()); // { value: 2, done: false }
console.log(generator.next()); // { value: 3, done: false } -> 실제 요소가 있을 때까지 next()를 호출하면
console.log(generator.next()); // { value: undefined, done: true} // 순회가 끝났음을 알려주는 객체를 


function* fn2() {
    try {
        yield 'a';
        yield 'b';
    } catch (e) {
        yield `Error: ${e}`;
    }
}

const generator2 =fn2();
console.log(generator2.next()); // { value: 1, done: false }
generator2.throw('Something went wrong'); // 'throw'를 통해 예외 발생
console.log(generator2.next()); // { value: 'Error: Something went wrong', done: false }
console.log(generator2.next()); // { value: undefined, done: true }

function* fn3() {
    yield 1;
    const a = yield 2;
    const b = yield 3;
    const c = yield a + b;
}

const generator3 = fn3();
console.log(generator3.next(5)); // 1을 출력합니다 / 첫번째 next는 인수를 전달하지 못함 -> 애초에 이 전에 뭐가 존재하지 않으니깐
console.log(generator3.next(6)); // 2를 출력합니다 / 첫번째 yield는 변수에 담기지 않음 -> 인수전달x
console.log(generator3.next(7)); // 3을 출력합니다 / a에 7을 할당해줍니다.
console.log(generator3.next(8)); // 15를 출력합니다 / b에 8을 할당하고 a+b를 반환합니다
console.log(generator3.next(50)); // c에  50을 할당합니다 / 순회를 종료합니다
