// JSON: 서버와 클러이언트간 통신을 위한 object type의 text formet

const student = {
  age: 19,
  name: '김다연',
  studentId: 20604,
  rank: '전교일등입니다',
  intro: () => console.log('저는 귀여운 김다연입니다만?'),
};

console.log(student.intro());
const sendToServer = JSON.stringify(student); // 직렬화 -> 텍스트화
console.log(sendToServer);

const sendToClient = JSON.parse(sendToServer); // 역직렬화 -> 오브젝트화
console.log(sendToClient);
