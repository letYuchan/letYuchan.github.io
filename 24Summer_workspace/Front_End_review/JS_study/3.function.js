function  add(num1, num2){
    return num1 + num2;
}
const result = add(1,2);
console.log(result);
// rest 매개변수: 넘겨주는 인자 수를 세기 힘들때 사용
function addAll(...nums){ 
    let result = 0;
    for(let num of nums){ // 인자를 배열에 보관
        result+=num;
    }
    return result;
}

const result2 = addAll(1,2,3,4,5,6,7,8,9,10);
console.log(result2);


// anonymous func
let sub = function(a, b){
    return a-b;
}
console.log(sub(3,4));

// arrow func
mul = (a, b) => {
    return a*b;
}
console.log(mul(3,3));

// multidemension func: 인자로 함수를 받거나 함수를 반환하는 함수
function calculator(a, b, action){
    let result = action(a,b);
    return result;
}

console.log(calculator(10,20,add));


