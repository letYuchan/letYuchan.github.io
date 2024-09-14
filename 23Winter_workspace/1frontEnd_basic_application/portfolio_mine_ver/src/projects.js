'use strict';

const categories = document.querySelector('.work__categories');
const projects = document.querySelectorAll('.work__project');
categories.addEventListener('click', (event) => {
  const filter = event.target.dataset.category;
  if (filter == undefined) {
    return;
  }
  projects.forEach((project) => {
    if (filter === 'all' || filter === project.dataset.type) {
      project.style.display = 'block';
    } else {
      project.style.display = 'none';
    }
  });
});
