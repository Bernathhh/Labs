// Найти элемент по id
let progress = document.getElementById('progress');
let percentText = document.getElementById('percentText');
let btn = document.getElementById('btn');

// Назначить обработчик клика на кнопку
btn.onclick = function() {
    progress.value += 5;

    if (progress.value >= 100) {
        progress.value = 100;

        percentText.textContent = '100%. Максимум.'

        btn.hidden = true;
    } else {

        percentText.textContent = progress.value + '%';
    }
};