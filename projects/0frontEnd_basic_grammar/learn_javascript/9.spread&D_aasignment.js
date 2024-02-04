// iterable protocol을 따를 경우 쓰는 연산자: spread

add = (a, b, c) => a + b + c;
const arr1 = [1, 2, 3];
console.log(add(...arr1));

const obj1 = {
  key1: 'apple',
  key2: 'banana',
};

const obj2 = {
  key1: 'grape',
  key2: 'blueberry',
};

const obj3 = { ...obj1, ...obj2 };
console.log(obj3);

// 구조분해할당

const point = [1, 2, 3];
const [x, y, z] = point;
console.log(x);
console.log(y);
console.log(z);

const student = {
  age: 19,
  name: '김다연',
  from: 'seoul, ROK',
  feature: '귀여움',
};
function display({ age, name, from, feature }) {
  console.log('나이가?', age);
  console.log('이름이?', name);
  console.log('사는곳?', from);
  console.log('얼굴은?', feature);
}

display(student);
