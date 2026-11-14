// Найти элемент по id
let largeImg = document.getElementById('largeImg');
let thumbs = document.getElementById('thumbs');

thumbs.onclick = function(event) {
    // ищем ближайшего предка <a>
    let thumbnail = event.target.closest('a');

    if (!thumbnail) return;

    event.preventDefault();

    // Подставить в большое изображение путь (src) из атрибута href нажатой ссылки
    largeImg.src = thumbnail.href;

    // Обновить всплывающую подсказку (title) большого изображения
    largeImg.title = thumbnail.title;
};