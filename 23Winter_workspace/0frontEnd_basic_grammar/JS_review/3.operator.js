//산술연산자

console.log(5 + 2);
console.log(5 - 2);
console.log(5 * 2);
console.log(5 / 2);
console.log(5 % 2);
console.log(5 ** 2);
console.log(Math.pow(5, 3));

// 단항연산자
let a = 0;
a = -5;
console.log(a);
a = +5;
console.log(a);

// 단항연산자를 num이 아닌 type에 쓴다면? falshy => 0 / truth => 1
console.log(+true); // 1
console.log(+false); // 0
console.log(+undefined); // NaN

// 할당연산자
let b = 0;
b += 3;
console.log(b);
for (let i = 0; i < 5; i++) {
    b -= 5;
    console.log(b);
}

// 증감연산자
let c = 0;
console.log(c++); // 0
console.log(c); // 1
console.log(++c); // 2

// 비교연산자: 결과값은 boolean
console.log(3 > 2);
console.log(3 < 2);
console.log(3 <= 3);
console.log(3 >= 2);

// 동등 비교관계 연산자: 여기서 주목해야할 건 === -> typer과 value가 모두 같아야 true
console.log(2 == '2');
console.log(2 === '2');
console.log(true == 1);
console.log(true === 1);
console.log(2!=3);