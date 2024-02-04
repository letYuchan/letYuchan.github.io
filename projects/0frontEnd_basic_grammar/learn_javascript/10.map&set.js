// set: 중복 불가능, 배열과 다르게 no index
const obj1 = { name: '조유찬', age: 23 };
const obj2 = { name: '김다연', age: 19 };
const objs = new Set([obj1, obj2]);
console.log(objs);

console.log(objs.size);
console.log(objs.has(obj1));
for (const value of objs.values()) {
  console.log(value);
}
console.log(objs.add('They are cute'));
console.log(objs);
console.log(objs.delete('They are cute'));
console.log(objs);
console.log(objs.clear());

// Map: like object but different about functions what are used
const key1 = 'key1';
const key2 = 'key2';
const map1 = new Map([
  [key1, 'value1'],
  [key2, 'value2'],
]);
console.log(map1.size);
console.log(map1.has(key1));
map1.forEach((value, key) => console.log(key, value));
console.log(map1.keys());
console.log(map1.values());
console.log(map1.entries());
console.log(map1.get(key2));
console.log(map1.delete(key2));
console.log(map1.clear());
