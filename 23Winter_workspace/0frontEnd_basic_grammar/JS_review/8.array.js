// 배열: 여러 데이터를 순차적으로 보관할 수 있는 자료구조

// 배열생성법1: 생성자함수
let array1 = new Array(5);
for (let i = 0; i < 5; i++){
    array1[i] = i;
    console.log(array1[i]);
}

// 배열생성법2: static 함수
let array2 = Array.of('a', 'b', 'c');
for (let i = 0; i < array2.length; i++){
    console.log(array2[i]);
}

// 배열생성법3: 배열리터럴 이용
let array3 = [false, false, true];
for (let i = 0; i < array3.length; i++){
    console.log(array3[i]);
}

// 배열을 복사하는 법: from()
array3 = Array.from(array1);
for (let i = 0; i < array3.length; i++){
    console.log(array3[i]);
}

// from을 객체처럼 활용한다면?
array2 = Array.from({
    0: '안', // 인덱스 0에 '안'이란 value를 넣어줌
    1: '녕', // 마찬가지
    length: 2, // 사이즈 지정은 필수
})
console.log(array2);

// 아이템 추가와 삭제
console.log(Array.isArray(array3)); // 해당 객체가 배열인지 묻는 함수
console.log(array2.indexOf('안')); // 해당하는 값의 인덱스를 찾기
console.log(array2.push('하세요')); // 맨 뒤 아이템 추가
console.log(array2);
console.log(array2.pop()); // 맨 뒤 아이템 삭제
console.log(array2);
console.log(array2.shift()); // 맨 앞 아이템 삭제
console.log(array2);

console.log(array3);
array3.reverse(); // 아이템 정렬을 반대로
console.log(array3);
array4 = [90, 2130, 1230, [123, 51235]];
console.log(array4);
array5 = array4.flat(); //배열의 중첩을 해제시킴, default: 1
console.log(array5);

array6 = array3.concat(array5); // 배열을 이어붙임
console.log(array6);

array7 = array6.slice(0, 3); // 배열을 잘라냄
console.log(array7);


// 배열의 고차함수: 고차함수란 함수를 인자로 받거나 반환하는 함수

// 배열순회: forEach()
array1.forEach(function (num) {
    console.log(num * num);
});

// 배열맵핑: map()
array1_tripleMul = array1.map((item) => item * 3);
for (let i = 0; i < array1.length; i++){
    console.log(array1_tripleMul[i]);
}

// 배열정렬: sort()
const numbers = [1,3,5,6,2,0,10,9];
numbers.sort((a, b)=> a- b);//순차적으로 2개씩 비교
console.log(numbers); //오름차순
numbers.sort((a, b)=> b- a);
console.log(numbers); //내림차순

