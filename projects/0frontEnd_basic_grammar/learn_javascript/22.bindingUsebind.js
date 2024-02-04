// 이를 해결하기위한 방법1: 수동적으로 해주기
function SayHi(name, hi) {
  this.name = name;
  this.hi = function () {
    console.log(`안녕 ${this.name}아! `);
  };
  this.hi = this.hi.bind(this);
}

function SayBye(name, bye) {
  this.name = name;
  this.bye = function () {
    console.log(`잘가 ${this.name}아! `);
  };
  this.bye = this.bye.bind(this);
}

const fn1 = new SayHi('민수');
const fn2 = new SayBye('수진');

fn1.hi = fn2.bye;
console.log(fn1.hi()); // 잘가 수진
