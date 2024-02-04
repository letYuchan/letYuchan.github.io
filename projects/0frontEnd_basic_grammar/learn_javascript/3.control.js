//제어문: 흐름을 통제하고 제어하는 최소 실행 단위

//조건문 if
let a = 3;
if (a === 2) {
  console.log('a는 2입니다');
} else {
  console.log('a는 2가 아닙니다.');
}

// 조건문 ternary operator
let fruit = 'apple';

let correct =
  fruit === 'apple' ? console.log("It's apple") : console.log('not apple');
console.log(fruit);

// 조건문  switch
let color = 4;
switch (color) {
  case 1:
    color = '노랑';
    break;
  case 2:
    color = '빨강';
    break;
  case 3:
    color = '파랑';
    break;
  case 4:
    color = '초록';
    break;
  default:
    console.log('해당없음');
}

console.log(color);

// 반복문 for(초기식;조건식;증감식)
for (let i = 0; i < 10; i++) {
  console.log(i);
}

for (let i = 0; i < 10; i++) {
  if (i == 8) {
    continue;
    console.log('hidden message');
  }
  console.log(i);
}
//무한루프 for(;;)
let i = 0;
for (;;) {
  if ((i = 10)) {
    break;
  }
  console.log(i);
  i++;
}
i = 0;
// 반복문 while
let b = 3;
while (b < 5) {
  console.log(b);
  console.log('b는 5보다 작습니다.');
  b++;
}

// 무한루프
while (true) {
  console.log(i);
  if (i === 100) {
    break;
  }
  i++;
}

// 반복문  do while: 반드시 한번은 문장을 실행한다.
i = 0;
console.log('0부터 100까지 출력');
do {
  console.log(i);
  if (i === 100) {
    break;
  }
  i++;
} while (true);

// 논리연산자: 주로 제어문 조건식으로 사용 -> true or false
let num = 8;
if (num >= 0 && num < 9) {
  console.log('0보다 크거나 같고 9보다 작은 숫자입니다');
}
// 0보다 크거나 같고 9보다 작은 숫자입니다

if (num >= 0 || num > 20) {
  console.log('0보다 크거나 같고 9보다 작은 숫자입니다');
}
// 0보다 크거나 같고 9보다 작은 숫자입니다

if (num != 9) {
  console.log('0보다 크거나 같고 9보다 작은 숫자입니다');
}
// 0보다 크거나 같고 9보다 작은 숫자입니다

if (!!num == true) {
  console.log('이 값은 참입니다');
}

console.log(!'text'); // false
console.log(!!'text'); // true
