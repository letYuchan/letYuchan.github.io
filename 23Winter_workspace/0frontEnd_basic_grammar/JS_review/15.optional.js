// Optional Chaning Operator: null & undefined 확인용

// 오브젝트에서 활용
const obj1 = { num: 1, class: { professor: '이창훈' } };
let professorName = obj1?.class?.professor;
console.log(professorName);


// Nulish Coalescing Operator: 단축평가에 활용되어지는 ||에서 특별한 기능, null이나 undefined가 앞에 먼저 나오면 (falshy면) 뒤에 있는 표현식을 할당
let nullValue = null;
console.log(null ?? 10);
let falshyValue = 0;
console.log(falshyValue ?? 30);