// 콜백함수: 일단 틀만 만들어놓고 인자로 함수를 넘겨주면 그 함수의 기능을 하는 함수

const add = (a,b) => a+b;
const multiply = (a, b) => a*b;

function calculator(a,b,action){
    let result = action(a,b); // action이란 콜백함수선언
    console.log(result); // action은 특정함수의 래퍼런스(주소값)을 가짐
}

calculator(1,2,add); // action이란 함수에 add함수의 주소값을 전달
calculator(1,2,multiply); // action이란 함수에 multiply함수의 주소값을 전달