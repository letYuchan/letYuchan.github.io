// iteration protocol 이해하기

const iterableObj = {
    [Symbol.iterator]() { // Symbol.iterator == iterable protocol
        let index = 0;
        const data = [1, 2, 3];
        return { // iterator protocol
            next() {
                if (index < data.length) {
                    return { value: data[index++], done: false };
                }
                else {
                    return { value: undefined, done: true };
                }
            }
        }
    }
}

for (const item of iterableObj) { // for..of 연산
    console.log(item);
}

const array = [1,2,3]
let iterator = array.values();
console.log(iterator.next());
console.log(iterator.next().value);
console.log(iterator.next().value);
console.log(iterator.next().value); // undefined -> 순회 끝
console.log(iterator.next().done); // true -> 순회여부 o
console.log(iterator.next().value);


