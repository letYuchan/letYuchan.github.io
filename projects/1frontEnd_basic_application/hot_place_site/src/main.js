'use strict';

// 북마크기능
document.addEventListener('DOMContentLoaded', function () {
  const bookmarkedSites = new Set();

  function addToBookmark(linkElement) {
    const bookmarkContainer = document.querySelector('.bookmark__container');

    if (bookmarkedSites.has(linkElement.href)) {
      alert('이미 북마크에 추가된 사이트입니다.');
      return;
    }

    bookmarkedSites.add(linkElement.href);

    // 새로운 북마크 아이템 생성 및 추가
    const bookmarkItem = document.createElement('a');
    bookmarkItem.href = linkElement.href;
    bookmarkItem.textContent = linkElement.getAttribute('data-name'); // 수정된 부분

    // 줄바꿈 추가
    const lineBreak = document.createElement('br');
    bookmarkContainer.appendChild(lineBreak);

    bookmarkItem.target = '_blank';
    bookmarkContainer.appendChild(bookmarkItem);

    alert('북마크에 추가되었습니다.');
  }

  function addClickEventToLinks(sectionId) {
    const section = document.getElementById(sectionId);
    const links = section.querySelectorAll('ul li a');

    links.forEach((link) => {
      link.addEventListener('click', function (event) {
        event.preventDefault();
        addToBookmark(this);
        window.open(this.href, '_blank');
      });
    });
  }

  addClickEventToLinks('hongdae');
  addClickEventToLinks('kondae');
  addClickEventToLinks('gongneung');

  // 토글버튼
  const headerTitle = document.querySelector('.header__title');
  const headerItems = document.querySelector('.header__items');
  const headerToggle = document.querySelector('.header__toggle');
  const header = document.querySelector('#header');
  let isTransparent = false;

  if (window.innerWidth <= 768) {
    function responsiveNav() {
      // flag 변수활용의 방법1: 바로 boolean값을 할당

      headerItems.classList.toggle('header__items__responsive');
      if (headerTitle) {
        // flag 변수활용의 방법2: 속성을 가지고 false와 true를 정해놓는다
        const isHidden = headerTitle.style.display === 'none';
        headerTitle.style.display = isHidden ? 'block' : 'none';
      }
      isTransparent = !isTransparent;
      header.style.opacity = isTransparent ? 0.7 : 1.0;
    }

    headerToggle.addEventListener('click', () => {
      responsiveNav();
    });

    headerItems.addEventListener('click', () => {
      responsiveNav();
    });
  }

  const bookmark = document.querySelector('#bookmark');
  const bookmarkIcon = document.querySelector('.bookmark-mark');
});
