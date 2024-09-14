// 논리연산자는 때론 short-circuit evaluation으로써 작용하기도 함

// 1. 단순한 조건식으로 표현되어지는 식
let obj1 = { num: 17, name: '김철수' };
let obj2 = { num: 20, name: '안철수' };
if (obj1 && obj2) {
    console.log("두 오브젝트는 존재합니다");
}
else {
    console.log("두 오브젝트 중 최소 하나 이상 비어있습니다");
}

// 2. 단축평가로써 활용되어지는 논리연산자
let result = obj1 && obj2 // obj2가 할당되어짐 -> &&는 둘다 true여야함 따라서 obj1를 검사한 후 true이므로 obj2까지 검사
console.log(result);
result = obj1 || obj2 // obj1이 할당되어짐 -> || 연산자는 하나라도 true면 참인데, 이미 obj1이 true라서 뒷부분을 검사하지 않음(단축평가 진행)
console.log(result);


// 그러면 이를 활용해볼까?

// 1. 어떤 flag변수가 truthy한 값이라면 특정한 기능 동작시키기
function changeNum(student) {
    student.num += 1;
}

function addNum(studnet) {
    studnet.num = 10;
}

obj1.num && changeNum(obj1);
console.log(obj1); // 17+1
obj2.none || addNum(obj2);
console.log(obj2); // num: 10

// 2. undefiend이나 null을 확인할 때(null과 undefined는 false)
obj1 = undefined;
const valueOfobj1 = obj1 && obj1.num;
console.log(valueOfobj1);

obj2 = null
const valueOfobj2 = obj2 || 30
console.log(valueOfobj2);
