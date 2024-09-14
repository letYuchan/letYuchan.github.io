// 함수의 통제권을 호출자가 갖도록 하는 리터럴
function* fn(){
    yield 1;
    yield 2;
    return 3; // 여기서 함수 종료
    yield 4;
}

const generator = fn();
console.log(generator.next());
console.log(generator.next());
console.log(generator.next());
console.log(generator.next());



