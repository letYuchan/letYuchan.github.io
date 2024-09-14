//set: 데이터집합체로 중복불가능하며 인덱스가 없는게 특징
const array =  [1, 2, 1, 3, 4, 5]; 
let setArray = new Set(array);
console.log(setArray); // {1, 2, 3, 4, 5} // 중복된 1은 제거
console.log("size: " + setArray.size);
console.log("setArray는 7을 갖고 있습니까?: " + setArray.has(7));
setArray.forEach((item) => console.log(item)); // forEach를 이용한 순회
for (const item of setArray.values()) { // for..of를 이용한 순회
    console.log(item);
}

//map: key랑 value를 갖긴함, 다만 특수한 함수를 사용
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
map1.set('key3', 'value3');
console.log(map1.entries());
console.log(map1.get(key2));
console.log(map1.delete(key2));
console.log(map1.clear());
