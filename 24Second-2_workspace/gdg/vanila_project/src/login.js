const apiUrl = "http://3.39.224.92:8080/api/user/login";
// form 제출시 login 함수 실행
document.addEventListener("DOMContentLoaded", function() {
    const form = document.querySelector("form");
    form.addEventListener("submit", login);  
});

// 로그인 함수 실행
async function login(event) {
    event.preventDefault(); // 기본 폼 제출 동작 방지

    const emailVal = document.getElementById("id");
    const passwordVal = document.getElementById("pw");
    const url = apiUrl;

    // 서버에 보낼 body 정의 후 JSON으로 변경(API 명세서 확인)
    const body = JSON.stringify({
        email: emailVal.value, 
        password: passwordVal.value
    });

    console.log(body);

    try {
        
        // POST 방법으로 서버에 응답요청
        const response = await fetch(url, {
            method: "POST", 
            headers: {
                "Content-Type": "application/json" 
            },
            body: body,
            mode: 'no-cors'
        });

        console.log("HTTP Status: ", response.status); 

        // 응답상태 확인 -> 서버가 응답요청을 제대로 처리했는지를...
        if (!response.ok) {
            const errorText = await response.text();
            throw new Error(`Error: ${response.status} - ${errorText}`);
        }

        // 응답이 괜찮다면
        const data = await response.json(); // 응답의 본문을 가져옴
        console.log("응답 데이터: ", data);

        // data 성공여부에 따라(로그인이 올바르게 됐는지..)
        if (data.success) { // success는 API 설계자가 만든 함수 or property
            window.location.href = "./onboarding.html";
        } else {
            alert(data.message + " 로그인 실패! 아이디와 비밀번호를 확인하세요");
        }
    } catch (error) { // fetch 혹은 다른 코드에서의 에러 혹은 예외처리 
        console.error("에러 발생:", error);
        alert("로그인 도중 문제가 발생했습니다. 다시 시도하세요.");
    }
}


// response: 서버로부터 받은 HTTP 응답 전체를 나타내는 객체
// response.status: HTTP 상태 코드
// response.ok: 200~209 -> true, other -> false
// response.headers: 응답 헤더 정보
// response.text()/json()/blob(): 본문을 읽기 위한 객체 생성 =  data 생성

// data: 응답 본문을 가공한 실제 데이터
// data.success:

// 흐름: response -> .text(), json(), blob()해서 data 생성
