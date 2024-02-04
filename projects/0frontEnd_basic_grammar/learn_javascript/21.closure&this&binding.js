// closure를 활용한 데이터 은닉화
function makeCounter() {
  let count = 0;
  function increase() {
    count++;
    console.log(count);
  }
  return increase;
}

const increase = makeCounter();
increase();
increase();
increase();

// 이걸 class로 변환한다면?
class Counter {
  #count = 0;
  increase() {
    this.#count++;
    console.log(this.#count);
  }
}
const counter = new Counter();
console.log(counter);
counter.increase();
counter.increase();

// this: 가장 가까운 객체에 binding되는 참조변수
console.log(globalThis);

// binding
// 동적인 바인딩: 호출시점을 기준
function SayHi(name, hi) {
  this.name = name;
  this.hi = function () {
    console.log(`안녕 ${this.name} `);
  };
}

function SayBye(name, bye) {
  this.name = name;
  this.bye = function () {
    console.log(`잘가 ${this.name}`);
  };
}

const fn1 = new SayHi('민수');
const fn2 = new SayBye('수진');
console.log(fn1.hi()); // 안녕 민수
console.log(fn2.bye()); // 잘가 수진

fn1.hi = fn2.bye;
console.log(fn1.hi()); // 잘가 민수





