// synchronous: 동기적 == 순차적으로 처리 vs asynchronous: 비동기적 == 병렬수행

// 동기적 처리
function a() {
  return 1;
}

function b() {
  return a() + 1;
}

function c() {
  return b() + 1;
}

const result = c();
console.log(result); // 3

function execute() {
  console.log('1');
  setTimeout(() => {
    console.log('2');
  }, 2000);
  console.log('3');
}
execute(); // 1 3 2
