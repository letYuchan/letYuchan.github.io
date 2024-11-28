

// 랜덤 버튼 클릭 시 랜덤으로 카드 선택하여 모달 띄우기
document.querySelector('.randomQ').addEventListener('click', () => {
    // 모든 멤버 카드 중에서 랜덤으로 하나 선택
    const memberCards = document.querySelectorAll('.member_card');
    const randomIndex = Math.floor(Math.random() * memberCards.length);  // 랜덤 인덱스 생성
    const randomCard = memberCards[randomIndex];  // 랜덤 카드 선택
    const memberName = randomCard.innerText;  // 선택된 카드의 이름 가져오기

    // 모달에 멤버 이름 넣기
    document.getElementById('memberName').innerText = memberName;

    // 모달 띄우기
    document.getElementById('memberModal').style.display = 'flex';
});

// 기존 멤버 카드 클릭 시 모달 띄우기 (변경 없음)
document.querySelectorAll('.member_card').forEach(card => {
    card.addEventListener('click', () => {
        const memberName = card.innerText;  // 클릭된 카드의 텍스트 값 가져오기
        document.getElementById('memberName').innerText = memberName;
        document.getElementById('memberModal').style.display = 'flex';
    });
});

// 제출 버튼 클릭 시 서버로 데이터 전송
document.getElementById('questionForm').addEventListener('submit', async (event) => {
    event.preventDefault();  // 폼의 기본 제출 동작 막기

    const questionText = document.getElementById('questionText').value;  // 질문 내용 가져오기
    const memberName = document.getElementById('memberName').innerText;  // 질문할 멤버 이름 가져오기

    try {
        // 서버로 POST 요청 보내기
        const response = await fetch('https://your-server-url.com/api/questions', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                member: memberName,
                question: questionText
            })
        });

        // 요청 성공 시 모달 닫기
        if (response.ok) {
            alert('질문이 성공적으로 전송되었습니다.');
            document.getElementById('memberModal').style.display = 'none';
            document.getElementById('questionText').value = '';  // 텍스트 입력 초기화
        } else {
            throw new Error('질문 전송에 실패했습니다. 다시 시도해 주세요.');
        }
    } catch (error) {
        console.error('오류 발생:', error);
        alert(`오류: ${error.message}`);
        document.getElementById('memberModal').style.display = 'none';
    }
});

// 취소 버튼 클릭 시 모달 닫기
document.querySelector('.cancel_button').addEventListener('click', () => {
    document.getElementById('memberModal').style.display = 'none';
});
