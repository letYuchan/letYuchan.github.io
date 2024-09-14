// 동기(synchronous): 작업을 순차적으로 처리 -> 무거운 작업시 지연발생
// 비동기(asynchronous): 작업을 병렬적으로 처리 -> 작업시간 효율화

// 동기작업 수행
function a() {
    return 1;
}

function b(){
    return a() + 1;
}

function c(){
    return b() + 1;
}

const result = c();
console.log(result);
// c -> b -> a

// 동기적 처리
function execute(){
    console.log('1'); // 1. 1출력
    setTimeout(()=>{
        console.log('2'); // 2. 2초 뒤 2가 출력되므로
        
    }, 2000);
    console.log('3'); // 3. 3이 출력된 후 2초후 2 출력
    
    
}
execute();

