'use strict';

const categories = document.querySelector('.work__categories'); // work__kinds요소를 참조한다. (자식요소까지 접근가능).
const projects = document.querySelectorAll('.work__project'); // 각각의 work__link들을 links라는 이름아래 배열로 가져옴
categories.addEventListener('click', (event) => {
  // work__kinds 영역을 클릭하면(이벤트가 발생하면) 콜백함수의 첫번째 매개변수에 event object가 전달
  //
  const filter = event.target.dataset.category; // 이벤트가 발생한 요소로부터 반환된 event객체의 target안 dataset안 category라는 key값에 대한 value를 filter변수에 할당. 여기서 target이란 실제 이벤트가 발생한 요소를 나타낸다.
  if (filter == undefined) {
    // kinds의 영역은 work__link외의 padding도 포함하므로, 요소가 존재하지 않는 공간을 클릭해도 이벤트가 발생한다.
    return; // 이때 undefined를 반환하는데 이럴경우에 대비해 콜백함수를 종료한다(이에 대한 이벤트발생은 필요없으니).
  }
  projects.forEach((project) => {
    // 배열로받아온 work__link들을 forEach를 사용해 순회한다. 이때 각 배열속 element를 link라는 매개변수로 받아옴
    if (filter === 'all' || filter === project.dataset.type) {
      // 일단 data-category의 값이 all인지 먼저 확인한다. (all은 전부 나타내야하는데 각각의 work__link의 type속성은 front, back, grammar밖에 없음, all 존재하지 않음)
      project.style.display = 'block'; // 'ALL'버튼을 누르면 filter에는 all이 할당되므로 모든 블럭이 보인다. 그 뒤의 조건은 data-type과 filter의 data-category값을 비교하는 조건인데, 이에 해당하는 work__link만 block처리하고 아닌 요소는 none처리를 한다.
    } else {
      project.style.display = 'none';
    }
  });
});
