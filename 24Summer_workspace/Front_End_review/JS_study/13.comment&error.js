// JSDoc: 코드에 주석을 달고 문서를 생성하는데 사용되는 도구
/**
 * 
 * @param {*} a 
 * @param {*} b 
 * @returns 
 */
 function add(a,b){
    return a + b;
}

// try: 이 코드를 실행했을 때
// catch: 에러가발생한다면 잡아서 처리한다
// finally: 그러나 에러가 발생하든 말든 이 코드는 꼭 실행시킨다.

function processFile(path){
    throw new Error('파일 경로를 찾을 수 없음'); // 고의로 에러 발생시킴
    return '파일의 내용';
}

function processFile(path){
    let content;
    try{
        content = readFile(path);
    } catch(error){
        console.log(error);
        content = '오류발생';
    } finally {
        console.log('파일을 닫습니다.');
        
    }
    const result = '파일내용: ' + content;
    return result;
}

const result = processFile('경로');
console.log(result);

// error bubble up
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
  

