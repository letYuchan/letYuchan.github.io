// 배열을 통해 iteration protocol 이해하기 + for...of 연산자 사용해보기
const array = [1, 2, 3];
for (const item of array) {
  console.log(item);
}

for (const item of array.keys()) {
  console.log(item);
}

for (const item of array.values()) {
  console.log(item);
}

for (const item of array.entries()) {
  console.log(item);
}

// iterator 객체에 속하는 next()함수로 수동으로 순회하기
array2 = [1, 2, 3];
let iterator = array2.values();
console.log(iterator.next());
console.log(iterator.next().value);
console.log(iterator.next().value);
console.log(iterator.next().value);
console.log(iterator.next().done); // 총 3개 불렀으니(1,2,3) 마지막 순회여부는 true다

// while문으로 for...if 구현하기
array3 = [1, 2, 3];
iterator = array3.values();
while (true) {
  const item = iterator.next();
  if (item.done) break;
  console.log(item.value);
}
