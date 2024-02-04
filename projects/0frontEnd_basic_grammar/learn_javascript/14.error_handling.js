// JSDoc: 함수 설명을 위한 주석처리

/**
 * 두 인자를 더한 값을 반환하는 더하기 함수
 * @param {*} a 더해질 변수1
 * @param {*} b 더해질 변수2
 * @returns a+b
 */
function add(a, b) {
  return a + b;
}

// 에러처리(error handling)
function readFile(path) {
  throw new Error('파일 경로를 찾을 수 없음');
  return '파일의내용';
}

function processFile(path) {
  let content;
  try {
    content = readFile(path);
  } catch (error) {
    console.log(error);
    content = '오류발생';
  } finally {
    console.log('파일을 닫습니다.'); // 파일을 닫습니다.
  }
  const result = '파일내용:' + content;
  return result;
}

const result = processFile('경로');
console.log(result); // 파일내용: 오류발생

// error bubbleling

function a() {
  throw new Error('에러발생');
}

function b() {
  try {
    a();
  } catch (error) {
    console.log('에러처리 c한테 throw'); // 에러처리 c한테 throw
    throw error;
  }
}

function c() {
  b();
}

try {
  c();
} catch (error) {
  console.log('에러처리 완료'); // 에러처리 완료
}
