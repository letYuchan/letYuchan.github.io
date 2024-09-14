let a = 3;
console.log(a); // copy by value

let student = {
    name: '김철수',
    age: 10
};
console.log(student); // copy by reference(address of memory)

// primitive type
// num
let integer = 123;
console.log(integer);
let double = 1.23;
console.log(double);

let binary = 0b1101;
console.log(binary);
let octal = 0o173;
console.log(octal);
let hex = 0x7b;
console.log(hex);

const bigInt = 12341234132412341234123412341234n;

// string
let id = "'철수'";
let str = '안녕하세요';
console.log(str);
let greetings; 
greetings = `'안녕!, ${id}
반갑습니다.`;

// boolean
let truth = true;
let falshy = false;
console.log(truth);
console.log(falshy);

// null: 명시적으로 값이 비어있음을 의미
let nullean = null;
console.log(!!nullean); // !!연산자: 값이 false인지 true인지 판단


// undefined: 초기화 여부 확인을 위한 값으로, 값이 할당되지 않았음을 의미
let undefinean = undefined; 
console.log(!!undefinean);


// object type
// object

let apple = {
    color : 'red',
    name : 'apple',
    taste: 'sweet'
};

console.log(apple);
console.log(apple.color);
console.log(apple.name);
console.log(apple.taste);











