// Promise: 비동기를 위한 객체

// 알고 가야하는것 resolve와 reject란 이름의 콜백함수는 각각 then과 catch와 대응한다.
function fn() {
  return new Promise((resolve, reject) => reject('에러발생'));
}
try {
  fn()
    .then((v1) => {
      const result1 = v1 + 1;
      return result1;
    })
    .then((v2) => {
      const result2 = v2 + 1;
      return result2;
    })
    .then((v3) => {
      const result3 = v3 + 1;
      return result3;
    })
    .then((v4) => {
      console.log(v4); // 13
    });
} catch {
  (error) => {
    console.error(error); // 오류를 처리하는 데 사용할 코드를 작성
  };
}

// 체이닝 발생시 병렬적으로 처리하기 위한 예약어: all, race, allSettled(주로 여러 promise객체에서 발생하면서 발생하는 딜레이 해결)
function getA() {
  return new Promise((resolve) => {
    // 1초후 A 반환
    setTimeout(() => {
      resolve('A');
    }, 1000);
  });
}

function getB() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve('B'); // 5초후 B 반환
    }, 5000);
  });
}

function getError() {
  return Promise.reject(new Error('error')); // error라는 에러 메세지 반환
}

Promise.race([getA(), getB()]).then((result) => {
  console.log(result);
}); // 가장 빠른 A가 1초 후 출력

Promise.all([getA(), getB()]).then((result) => {
  console.log(result);
}); // 5초후  [ 'A', 'B' ] 출력 (원래라면 A가 1초후 B가 1초+5초 후 실행되어 총 6초가 걸림

Promise.allSettled([getA(), getB(), getError()])
  .catch(console)
  .then((result) => {
    console.log(result);
  });

/**
   * [
    { status: 'fulfilled', value: 'A' },
    { status: 'fulfilled', value: 'B' },
    {
      status: 'rejected',
      reason: Error: error
    }
  ]
   */

// 비동기적 코드를 동기적으로 깔끔하게 보이게 하기
function getA() {
  return new Promise((resolve) => {
    // 1초후 A 반환
    setTimeout(() => {
      resolve('A');
    }, 1000);
  });
}

function getB() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve('B'); // 5초후 B 반환
    }, 5000);
  });
}

async function getAandB() {
  const a = await getA(); // getA가 작업 수행 후 A를 a에 할당
  const b = await getB(); // getB가 작업 수행 후 B를 b에 할당
  return [a, b]; // 배열로써 A와 B를 반환
}

getAandB().then((result) => console.log(result)); // ['A', 'B']
