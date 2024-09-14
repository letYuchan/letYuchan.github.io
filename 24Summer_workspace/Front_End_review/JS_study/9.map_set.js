// set: 중복불가능한 순회가능 객체(순서가 없음 == 인덱스 없음)
const set1 = new Set();
set1.add(1);
set1.add(2);
set1.add(3);
set1.add(3); // 중복원소 삽입
set1.forEach((item)=>console.log(item));

let _a = {name: 'a', age: 23};
let _b = {name: 'b', age: 25};
const set2 = new Set([_a, _b]);
console.log(set2);

// map: key와 value를 갖는 객체, 단 key type으로 어느타입이든 가능, 순회가능
const key1 = 'key1';
const key2 = 'key2';
const map1 = new Map([
  [key1, 'value1'],
  [key2, 'value2'],
]);
console.log(map1.size);
console.log(map1.has(key1));
map1.forEach((value, key) => console.log(key, value)); // 순서가 뒤바뀜
console.log(map1.keys());
console.log(map1.values());
console.log(map1.entries());
console.log(map1.get(key2));
console.log(map1.delete(key2));
console.log(map1.clear());






