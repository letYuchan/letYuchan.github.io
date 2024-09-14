// 배열의 아이템이나 객체의 요소들을 개별변수로 분해시키는것 
const person = {name: '조유찬', age: 23};
function display({name,age}){
    console.log('이름', name);
    console.log('나이', age);
}

display(person);