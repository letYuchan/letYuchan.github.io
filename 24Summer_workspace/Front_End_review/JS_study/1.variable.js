let a = 1;
var b = 2; // 특별한 초기화 값이 없다면 undefined으로 초기화
const c = 3;

// 호이스팅: 변수선언부분을 스코프 최상단으로 끌어올림
// 호이스팅의 원리에 입각한 다음 코드가 오류가 안생기는 이유
console.log(d); // 변수선언보다 앞서있지만 undefined 출력
var d = 3;

for(let i = 0;i<5;i++){
    console.log(i);
    i++;
}
console.log(i); // let과 const는 블록내부가 스코프여서 에러가발생

for(var i = 0; i<3;i++){
    console.log(i);
}
console.log(i); // var는 함수 제외 늘 전역변수로 작용하므로 에러발생x

var e = 1;
var e = 3; // var 특징: 재선언 가능
// 암튼 var는 문제가 많으니깐 let과 const만 쓰기


