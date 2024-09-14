// 배열생성법
let array1 = new Array(1,2,3); // 생성자함수
let array2 = Array.of(4,5,6); // static 함수
let array3 = [7,8,9]; // 
console.log(array1);
console.log(array2);
console.log(array3);

let copy_arr =  [0, 0, 0];
array1 = Array.from(copy_arr);
console.log(array1);

// 인덱스 접근
for(let i = 0; i<array1.length;i++){
    console.log(array1[i]);  
}

//배열관련 함수들
let arr = new Array(10);
for(let i = 0; i<10;i++){
    arr.push(i);
}
console.log(Array.isArray(arr)); // 이 객체가 배열이 맞니?
console.log(arr.indexOf(3)); // 해당 아이템의 인덱스 위치
arr.splice(0, 5, 'a'); // 해당하는 범위만큼 삭제 후 원하는 아이템 추가
arr.pop(); // 맨 뒤 아이템 삭제
console.log(arr.length); // 배열길이 확인
for(let i = 0;i<arr.length;i++){
    console.log(arr[i]);
    
}

arr = array1.slice(0, 2);
console.log(arr);
arr = array2.reverse();
console.log(arr);

// 배열의 고차함수
// 배열 순회
array2.forEach(function(value, index, array){
    console.log('--------');
    console.log(value);
    console.log(index);
    console.log(array);
})
// 찾기
let array4 = [1,8,5,3,6,2,9,10]
console.log(array2.find((value)=>value ==3));
array4.sort((a,b)=>a-b); // 오름차순 정렬
console.log(array4);













