// 옵셔널체이닝: 앞서배운 short-circuit evalution에서 사용되는 &&의 역할의 업그레이드버전
// null과 undefined 확인용
const obj1 = {num:1};
var num = obj1?.num; // == num = obj1 && obj1.num
console.log(num);

// 객체에서의 심화활용 -> 결국엔 코드 간결화와 연관있는 연산자임
const obj2 = {num:1, class : {professor : '이길흥'}};
let professorName = obj2?.class?.professor;
console.log(professorName);

// Nullish Coalescing Operator: literal -> ??, ||여 앞부분이 falshy일때 숏서킷평가가 진행된다면 여기서 더 제한하여 null과 undefined의 경우에만 작동하도록 조작
var num = 0;
console.log(num || '-1'); // 앞이 falshy한 값이므로 뒤를 출력
console.log(num ?? '-1'); // 앞이 falshy여도 null이나 undefined가 아니므로 앞이 출력




