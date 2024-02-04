// 옵셔널 체이닝 오퍼레이터 사용: like &&
const obj1 = { num: 1 };
let num = obj1?.num; // like obj1 && obj1.num
console.log(num);

// 널리시 콜레싱 오퍼레이터 사용: 앞에 값이 undefined거나 null인 경우만 뒤에 식을 실행
num = 0;
console.log(num || '-1'); // -1
console.log(num ?? '-1'); // 0 -> ??는 앞에 값이 null이거나 undefined일때만 뒤 식을 출력

//함수로 해보자
function print(text = '안 비었습니다') {
  const message = text ?? 'null or undefined';
  console.log(message);
}

print();
print(undefined);
print(null);
print(0);
