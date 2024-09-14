// 조건문: if
let a = 1;
if (a === 2) {
    console.log("a는 2입니다");
}
else if (a === 1){
    console.log("a는 1입니다");
}
else {
    console.log("a는 1도, 2도 아닙니다");
}

// 조건문: 삼항 조건 연산자
let fruit = 'apple';
fruit === 'apple' ? console.log("It\'s an apple") : console.log("It\'s not an apple");

// 조건문: switch

let b = 4;
switch (b) {
    case 1:
        console.log("월요일입니다");
        break;
    case 2:
        console.log("화요일입니다");
        break;
    case 3:
        console.log("수요일입니다");
        break;    
    case 4:
        console.log("목요일입니다");
        break;
    case 5:
        console.log("금요일입니다");
        break;
    case 6:
        console.log("토요일입니다");
        break;
    case 7:
        console.log("일요일입니다");
        break;
}

// 반복문: for
for (let i = 0; i < 5; i++){
    console.log(i);
}

for (let i = 1; i < 10; i++){
    for (let j = 1; j < 10; j++){
        console.log(i + " * " + j + " = " + i*j);
    }
}

// 반복문: while
let num = 5;
while (num >= 0) {
    console.log(num);
    num--;
}

// 반복문: do while
let num2 = 7
do {
    console.log(num2);
    num2--;
}
while (num2 >= 0);

// 제어문의 조건식에서 쓰이는 논리연산자
let num3 = 10;
if (!!num3 == true) {
    console.log("num3는 true인 값을 가집니다");
}

if (num3 >= 0 && num3 <= 10) {
    console.log("num3는 0에서 10사이의 값입니다");
}

if (num3 == 10 || num3 == 5) {
        console.log("num3는 10이거나 5입니다");
}

