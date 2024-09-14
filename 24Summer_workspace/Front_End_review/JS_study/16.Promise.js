function fn(){
    return new Promise((resolve, reject) => resolve(10));
  }
  
  fn()
  .then((v1)=>{
    const result1 = v1 + 1;
    return result1;
  })
  .then((v2)=>{
    const result2 = v2 + 1;
    return result2;
  })
  .then((v3)=>{
    const result3 = v3 + 1;
    return result3;
  })
  .then((v4)=>{
    console.log(v4); // 13x
  })
  
  // catch 활용
//   function fn() {
//     return new Promise((resolve, reject) => reject('에러발생'));
//   }
//   try {
//     fn()
//       .then((v1) => {
//         const result1 = v1 + 1;
//         return result1;
//       })
//       .then((v2) => {
//         const result2 = v2 + 1;
//         return result2;
//       })
//       .then((v3) => {
//         const result3 = v3 + 1;
//         return result3;
//       })
//       .then((v4) => {
//         console.log(v4); // 13
//       });
//   } catch {
//     (error) => {
//       console.error(error); // 오류를 처리하는 데 사용할 코드를 작성
//     };
//   }

function runInDelay(seconds) {
    return new Promise((resolve, reject) => {
      if (!seconds || seconds < 0) {
        reject(new Error('seconds가 0보다 작음'));
      }
      setTimeout(resolve, seconds * 1000);
    });
  }
  
  runInDelay(2)
    .then(() => console.log('타이머 완료!')) // 성공시 수행할 작업
    .catch(console.error) // 에러발생시 수행할 작업
    .finally(() => console.log('끝났다!')); // 무조건 최종적으로 수행할 자업
  // 타이머 완료! 끝났다!
  