'use strict';

document.addEventListener('DOMContentLoaded', function () {
  const navMenu = document.querySelector('.header__menu');
  const navToggle = document.querySelector('.header__toggle');
  const headerLogo = document.querySelector('.header__logo');
  const header = document.querySelector('#header');
  let isTransparent = false;

  function toggleMenu() {
    if (window.innerWidth <= 768) {
      navMenu.classList.toggle('open');
      if (headerLogo) {
        const isHidden = headerLogo.style.display === 'none';
        headerLogo.style.display = isHidden ? 'flex' : 'none';
      }
      isTransparent = !isTransparent;
      header.style.opacity = isTransparent ? 0.7 : 1;
    }
  }

  navToggle.addEventListener('click', () => {
    toggleMenu();
  });

  navMenu.addEventListener('click', () => {
    toggleMenu();
  });
});

const goHome = document.querySelector('#goHome');
const home = document.querySelector('#home');
const homeHeight = home.getBoundingClientRect().height;
document.addEventListener('scroll', () => {
  if (window.scrollY > homeHeight) {
    goHome.classList.add('displayGoHome');
  } else {
    goHome.classList.remove('displayGoHome');
  }
});
