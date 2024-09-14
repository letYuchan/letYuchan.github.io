// spread: 순회 가능한 객체를 펼침(직관적으로 그냥 진짜 펼침)
function add(a, b, c){
 return a + b + c;
}

const nums = [1, 2, 3];
console.log(add(...nums)); // 6

// 구조분해(Destructing Assignment): 
const chulsu = {name: '김철수', age: 20, asset: 1000000};
function display({name, age, asset}){
    console.log('이름', name); // 이름 김철수
    console.log('나이', age); // 나이 age
    console.log('자산', asset); // 자산 1000000
}

display(chulsu);