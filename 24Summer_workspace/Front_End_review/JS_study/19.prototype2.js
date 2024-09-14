// 최상위 프로토타입  Object의 static 함수
// 객체 생성
let obj = { name: '김철수', age: 23 };

// 객체의 모든 속성에 대한 프로퍼티 디스크립터 가져오기
let descriptors = Object.getOwnPropertyDescriptors(obj);

Object.keys(descriptors).forEach(key => {
  console.log(`Property: ${key}, Descriptor: `, descriptors[key]);
});

// 'name' 속성의 디스크립터 변경 (writable, enumerable, configurable 모두 false로 설정)
Object.defineProperty(obj, 'name', {
    value: '김철수',
    writable: false,
    enumerable: false,
    configurable: false,
});

// 'name' 속성의 새로운 디스크립터 확인
let nameDescriptor = Object.getOwnPropertyDescriptor(obj, 'name');

console.log(`Updated Descriptor for 'name': `, nameDescriptor);

// 변경된 객체의 모든 속성에 대한 디스크립터 다시 확인
descriptors = Object.getOwnPropertyDescriptors(obj);

Object.keys(descriptors).forEach(key => {
    console.log(`Property: ${key}, Descriptor: `, descriptors[key]);
});

// class 상속을 생성자함수로 구현
// call: == super()
// create(): == extend
// instanceeof: 상속여부 확인

function Person(name, age, job){
    this.name = name;
    this.age = age;
    this.job = job;
}

Person.prototype.intro = function(){
    console.log("이 사람을 소개하겠습니다!");
}

function PersonDetail(name, age, job, salary){
    Person.call(this, name, age, job);
    this.salary = salary;
}

PersonDetail.prototype = Object.create(Person.prototype);
const person1 = new PersonDetail('김철수', 20, '대학생', 4000);
console.log(person1);
person1.intro();

console.log(person1 instanceof Person);
console.log(person1 instanceof Object);

