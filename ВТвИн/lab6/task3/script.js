// Найти элемент по id
let text = document.getElementById('text');
let btn = document.getElementById('btn');

// Назначить обработчик события клика на кнопку
btn.onclick = function() {
    // Перезаписываем внутреннее HTML-содержимое
    text.innerHTML = 'Изменился и стал <b>жирный</b>!';
};