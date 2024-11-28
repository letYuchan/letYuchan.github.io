const proxyUrl = "https://api.allorigins.win/get?url=";
const apiUrl = "http://3.39.224.92:8080/api/user/signup";

document.addEventListener("DOMContentLoaded", ()=>{
    const signupForm = document.querySelector("form");
    signupForm.addEventListener("submit", handleSignup);
})

// 회원가입 성공/실패 함수 -> 직접적인 요청은 singup()에서 다룸
async function handleSignup(event){
    event.preventDefault();

    // 서버에 요청할 요소들을 생성한다
    const email = document.getElementById("id").value;
    const password1 = document.getElementById("pw").value;
    const password2 = document.getElementById("pwCheck").value;
    const username = document.getElementById("userName").value;

    // 패스워드와 패스워드확인의 값이 같은지 확인
    if(password1!=password2){
        alert("패스워드가 틀립니다.");
        return;
    }

    try{
        const response = await signup(email, password1, password2, username);
        if(!response.success){
            alert("회원가입에 실패했습니다: "+response.message);
        } else {
            alert("회원가입 성공!");
            window.location.href = "./login.js";
        }

    } catch (errorText) {
        console.log("에러: " + errorText);
        alert("회원가입 중 에러가 발생했습니다. 다시 시도해주세요.")
    }
}

// 실질적으로 서버에 회원가입 요청을 전송하는 함수
async function signup(email, password1, password2, username){
    const url = proxyUrl + encodeURIComponent(apiUrl);
    const body = JSON.stringify({
        email: email.value,
        password1: password1.value,
        password2: password2.value,
        usename: username.value
    });

    try{
        const response = await fetch(url, {
            method: "POST",
            header: {"Content-Type": "application/json"},
            body: body
        })

        // HTTP 통신에러에 대한 처리(패치실패)
        if(!response.ok){
            const errorMessage = `HTTP: 에러: ${response.status}`;
            console.error(errorMessage);
            throw new Error(errorMessage);
        }

        const responseData = await response.json(); // 본문을 JSON으로 파싱
        console.log("서버 응답: ", responseData); // 여기까진 패치는 성공(서버와의 통신 성공)

        return responseData;
        } catch(error) {
            console.error("서버와 통신 중 에러: " + error);
            throw error;
        }
}


    


