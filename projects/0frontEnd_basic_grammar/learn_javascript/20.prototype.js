// 최상위 prototype Object
const obj = { name: '김다연', age: 19 };
console.log(Object.keys(obj));
console.log(Object.values(obj));
console.log(Object.entries(obj));

// prototype에 메소드 추가
function ExampleFunction() {}

ExampleFunction.prototype.someMethod = function () {
  console.log('This is a this.someMethod');
};

const exampleObject = new ExampleFunction();
exampleObject.someMethod();

// what is constructor porperty
function Person(name) {
  this.name = name;
}

const person = new Person('Alice');

console.log(person.constructor === Person); // 출력: true

// prototype-chain
function Person(name) {
  this.name = name;
}

Person.prototype.greet = function () {
  console.log(`안녕하세요, 저는 ${this.name}입니다.`);
};

const person2 = new Person('Alice');
person2.greet(); // 출력: 안녕하세요, 저는 Alice입니다.

// property descriptor
const obj2 = { name: '김철수', age: 23 };
const descriptors = Object.getOwnPropertyDescriptors(obj2);

Object.keys(descriptors).forEach((key) => {
  console.log(`Property: ${key}, Descriptor: `, descriptors[key]);
});

Object.defineProperty(obj2, 'name', {
  value: '김영희',
  writable: false,
  enumerable: true,
  configurable: true,
});

console.log(Object.getOwnPropertyDescriptor(obj2, 'name'));
// class 상속을 생성자함수로 구현
function Fruits(name, color, taste) {
  this.name = name;
  this.color = color;
  this.taste = taste;
}

Fruits.prototype.intro = function () {
  console.log('해당 과일을 소개합니다');
};

function FruitsPlus(name, color, taste, origin) {
  Fruits.call(this, name, color, taste);
  this.origin = origin;
}

FruitsPlus.prototype = Object.create(Fruits.prototype);
const fruit = new FruitsPlus('banana', 'yellow', 'sweet', 'PHY');
fruit.intro();
console.log(fruit);

console.log(fruit instanceof Fruits); // 상속여부 확인

// assign 함수 활용: property 복붙
const target = { a: 1, b: 2 };
const source1 = { b: 4, c: 5 };
const source2 = { d: 7 };

let result = Object.assign(target, source1, source2);
console.log(target); // { a: 1, b: 4, c: 5, d: 7 }
console.log(result); // { a: 1, b: 4, c: 5, d: 7 }

const source3 = { b: 4, c: 5, nestedObject: { key1: 'a', key2: 'b' } };
result = Object.assign(target, source3);
console.log(result);
