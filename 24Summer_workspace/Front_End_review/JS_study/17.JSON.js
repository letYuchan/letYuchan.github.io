const student = {
    name : '조유찬',
    num : 21101231,
    rank: 16,
    intro : () => console.log('컴퓨터공학과 2학년입니다.')
}

const studentJson = JSON.stringify(student); // 객체의 문자화 -> 서버로 데이터 전송시
console.log(studentJson);
const studentObj = JSON.parse(studentJson); // 문자의 객체화 -> 서버에서 JS로 받아와 활용할 때
console.log(studentObj);


