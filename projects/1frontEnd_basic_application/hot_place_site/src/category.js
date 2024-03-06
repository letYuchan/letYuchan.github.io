'use strict';

//category 버튼 기능
const categoriesH = document.querySelector('.categoriesH');
const categoriesK = document.querySelector('.categoriesK');
const categoriesG = document.querySelector('.categoriesG');

const sitesH = document.querySelectorAll('.resH');
const sitesK = document.querySelectorAll('.resK');
const sitesG = document.querySelectorAll('.resG');

categoriesH.addEventListener('click', (event) => {
  const filter = event.target.dataset.category;
  if (filter == undefined) {
    return;
  }
  sitesH.forEach((site) => {
    if (filter === 'allH' || filter === site.dataset.site) {
      site.style.display = 'block';
    } else {
      site.style.display = 'none';
    }
  });
});

categoriesK.addEventListener('click', (event) => {
  const filter = event.target.dataset.category;
  if (filter == undefined) {
    return;
  }
  sitesK.forEach((site) => {
    if (filter === 'allK' || filter === site.dataset.site) {
      site.style.display = 'block';
    } else {
      site.style.display = 'none';
    }
  });
});

categoriesG.addEventListener('click', (event) => {
  const filter = event.target.dataset.category;
  if (filter == undefined) {
    return;
  }
  sitesG.forEach((site) => {
    if (filter === 'allG' || filter === site.dataset.site) {
      site.style.display = 'block';
    } else {
      site.style.display = 'none';
    }
  });
});
