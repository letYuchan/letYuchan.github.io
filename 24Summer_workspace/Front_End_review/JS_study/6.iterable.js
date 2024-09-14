// iteration protocol = iterable protocal + iterator protocol
const iterableObj = {
    [Symbol.iterator](){ // iterable protocal
        let index = 0;
        const data = [1,2,3];

        return { // iterator protocol
            next(){
                if(index < data.length){
                    return {value: data[index++], done:false};
                }else{
                    return {value: undefined, done: true};
                }
            }
        };
    }
}

for(const item of iterableObj){
    console.log(item);
    
}

// iteration 규격을 따르면 for..of 연산자 사용가능
const array = [1,2,3];
for(const item of array){
    console.log(item);
    
}
for(const item of array.keys()){
    console.log(item); // 0 1 2
}

for(const item of array.values()){
    console.log(item); // 1 2 3
}

for(const item of array.entries()){ // 묶음 전달
    console.log(item); // [0,1] [1,2] [2,3]
}

// iterator 객체를 활용한 수동출력
const array2 = [4,5,6];
let iterator = array2.values();
console.log(iterator.next());
console.log(iterator.next().value);
console.log(iterator.next().value);
console.log(iterator.next().value);
console.log(iterator.next().done);

// spread 연산
function add(...nums){
    let sum = 0;
    for(let num of nums){
        sum +=num;
    }
    return sum;
}
const arr = [1,2,3,4,5,6,123,41,124,1234,51]
let result = add(...arr);
console.log(result);



