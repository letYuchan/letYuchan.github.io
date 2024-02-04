// 방법2: arrow함수
function SayHi(name, hi) {
  this.name = name;
  this.hi = () => {
    console.log(`안녕 ${this.name}아! `);
  };
}

function SayBye(name, bye) {
  this.name = name;
  this.bye = () => {
    console.log(`잘가 ${this.name}아! `);
  };
}

const fn1 = new SayHi('민수');
const fn2 = new SayBye('수진');

fn1.hi = fn2.bye;
console.log(fn1.hi()); // 잘가 수진
