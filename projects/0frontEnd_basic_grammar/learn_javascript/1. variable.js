// 변수 예약어

// var
var test;
console.log(test); // var 는 초기화 명시안해주면 undefined로 초기화
var a = 0;
var a = 2; // 재선언 가능
a = 3;
console.log(a);

// let
let b = 2;
b = 1; // 재할당만 가능
console.log(b);

// coonst
const c = 0; // 재할당 및 재선언 불가능
console.log(c);

//primitive type data

// num
let integer = 0;
console.log(integer);

// string
let string = '하이';
console.log(string);
string = "'안녕'";
console.log(string);

let string2 = '안녕';
let greetings = string + string2;
console.log(greetings);

greetings = `안녕세요 ${string2}
반가워요`;
console.log(greetings);

// boolean
let d = true;
let e = false;
console.log(a);
console.log(b);

//falshy
console.log(!!0);
console.log(!!'');
console.log(!!undefined);
console.log(!!null);

//truthy
console.log(!!1);
console.log(!!'text');
console.log(!!{});
console.log(!!Infinity);

// null&undefined
let f;
console.log(f); // 메모리 공간확보 x

let g = null;
console.log(g); // 메모리에 공간은 존재하다 값이 비어있음

let object1 = {
  name: 'banana',
  color: 'yellow',
};

console.log(object1);
console.log(object1.name);
console.log(object1.color);

// typeof operator
console.log(typeof object1);
console.log(typeof a);
console.log(typeof b);
console.log(typeof c);
console.log(typeof d);
console.log(typeof e);
console.log(typeof g);
