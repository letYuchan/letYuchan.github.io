// arithmetic operators

console.log(2 + 1);
console.log(2 - 1);
console.log(2 * 1);
console.log(2 / 1);
console.log(2 & 1); //나머지연산
console.log(2 ** 1); //거듭제곱

// unary operators

let a = 1;
a = -1;
a = +1;

let b = true;
console.log(!b); //!: 부정연산자
console.log(+false); // 0 = false
console.log(+true); // 1 = true
console.log(+undefined); //NaN: Not a Number

// assignment operators ex) a+=1 -> like a = a + 1
let c = 1;
console.log(c); // 1
c += 2;
console.log(c); // 3
c -= 2;
console.log(c); // 1
c *= 2;
console.log(c); // 2
c /= 2;
console.log(c); // 1
c %= 2;
console.log(c); // 1
c ** 2;
console.log(c); // 1

// in/decrement operators: 연산 기준은 해당 코드가 ;에 의해 끝난 후 혹은 전
let d = 1;
console.log(d);
d++; // 뒤에 붙이면 ; 후에 증감
console.log(d);
d--;
console.log(d);

// relational operators, 결과값은 true or false
console.log(1 > 2);
console.log(1 < 2);
console.log(1 >= 1);
console.log(1 <= 1);

// equality operators, 결과값은 true or false

// ==: 같냐, !=: 다르냐, ===: 타입까지 같냐, !==: 타입과 값 모두 다르냐
console.log(2 == 2); // true
console.log(2 != 2); // false
console.log(2 != 3); // true
console.log(2 == '2'); // true, type은 다르지만 값은 같으므로 주의하자
console.log(2 === '2'); // false
console.log(true == 1); // true, true는 1로도 나타낼 수 있다
console.log(true === 1); // false
console.log(true !== 0); // true
