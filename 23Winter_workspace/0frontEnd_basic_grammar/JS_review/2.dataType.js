// primitive type: num, string, boolean, null, undefined, symbol
let num = 123
let string = "'hi'"
let double = 1.2
let boolean = true
// primitive -> call by value
console.log(num);
console.log(string);
console.log(double);
console.log(boolean);

// Falshy: 거짓인 값
 // !!연산자: 값이 참인지 거짓인지 판단해주는 연산자
console.log(!!0); 
console.log(!!-0);
console.log(!!'');
console.log(!!null);
console.log(!!undefined);

// Truthy: 참인 값
console.log(!!1);
console.log(!!-1);
console.log(!!'Text');
console.log(!!{});
console.log(!!Infinity);

// object type: function, object

let apple = {
    color: 'red',
    taste: 'sweet',
    name: 'apple'
}

console.log(apple); // { name: 'apple', color: 'red', taste: 'sweet' }
console.log(apple.name); // apple
console.log(apple.color); // red
console.log(apple.taste); // sweet


// typeof: 값이나 변수가 무슨 자료형인지 출력
let variable;
console.log(typeof variable);

variable = '';
console.log(typeof variable);

variable = 3.5314;
console.log(typeof variable);

variable = false;
console.log(typeof variable);

variable = function () { };
console.log(typeof variable);

variable = Symbol();
console.log(typeof variable);

variable = {};
console.log(typeof variable);