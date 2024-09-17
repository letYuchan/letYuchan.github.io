'use strict';

document.addEventListener('DOMContentLoaded', function(){
    /* toggle */
    if(window.innerWidth <= 768){
        const navMenu = document.querySelector('.header__menu');
        const navToggle = document.querySelector('.header__toggle');
        const header = document.querySelector('#header');
        let isTransparent = false;
    
        function toggleMenu() {
            isTransparent = !isTransparent;
            if (isTransparent) {
                header.style.opacity = 0.7;
                navMenu.style.display = 'flex';
            } else {
                header.style.opacity = 1;
                navMenu.style.display = 'none';
    
            }
        }
    
        navToggle.addEventListener('click', () => {
            toggleMenu();
        })
    
        navMenu.addEventListener('click', () => {
            toggleMenu();
        })
    }  
    /* aside */
    const goHome = document.querySelector('#goHome');
    const home = document.querySelector('#home');
    const homeHeight = home.getBoundingClientRect().height;
    
    document.addEventListener('scroll', () => {
        console.log('scrollY:', window.scrollY, 'homeHeight:', homeHeight); // 스크롤 높이와 homeHeight 확인
        if(window.scrollY > homeHeight) {
            goHome.style.display = 'flex';
        } else {
            goHome.style.display = 'none';
        }
    });
    
    /* history section */ 
const historyChild = document.querySelector('.history__child');
const historyAdol = document.querySelector('.history__adol');
const historyAdult = document.querySelector('.history__adult');
const buttonChild = document.querySelector('.buttonChild');
const buttonAdol = document.querySelector('.buttonAdol');
const buttonAdult = document.querySelector('.buttonAdult');
const categoryChild = document.querySelector('.category__child');
const categoryAdol = document.querySelector('.category__adol');
const categoryAdult = document.querySelector('.category__adult');

    buttonChild.addEventListener('click', ()=>{
        historyChild.style.display = 'block';
        historyAdol.style.display = 'none';
        historyAdult.style.display = 'none';
        categoryChild.classList.add('history__active');
        categoryAdol.classList.remove('history__active');
        categoryAdult.classList.remove('history__active');
    })
    buttonAdol.addEventListener('click', ()=>{
        historyChild.style.display = 'none';
        historyAdol.style.display = 'block';
        historyAdult.style.display = 'none';
        categoryChild.classList.remove('history__active');
        categoryAdol.classList.add('history__active');
        categoryAdult.classList.remove('history__active');
    })
    buttonAdult.addEventListener('click', ()=>{
        historyChild.style.display = 'none';
        historyAdol.style.display = 'none';
        historyAdult.style.display = 'block';
        categoryChild.classList.remove('history__active');
        categoryAdol.classList.remove('history__active');
        categoryAdult.classList.add('history__active');
    })
})







   

