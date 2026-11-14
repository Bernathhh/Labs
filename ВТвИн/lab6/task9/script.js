// Найти элемент по id и получить все элементы карусели
let startBtn = document.getElementById('startBtn');
let items = document.querySelectorAll('.carousel-item');

// Назначить обработчик клика на кнопку запуска карусели
let timerId = null;

let positions = ['pos-1', 'pos-2', 'pos-3'];

let step = 0;

startBtn.onclick = function() {
    // Если карусель уже запущена — ничего не делаем
    if (timerId !== null) return;

    timerId = setInterval(function() {
        step++;

        // Перебираем все 3 элемента карусели
        for (let i = 0; i < items.length; i++) {
            // Удаляем у элемента старые классы позиций
            items[i].classList.remove('pos-1', 'pos-2', 'pos-3');

            // Вычисляем новый индекс позиции по кругу
            let newPosIndex = (i + step) % positions.length;

            // Назначаем элементу класс новой позиции
            items[i].classList.add(positions[newPosIndex]);
        }
    }, 1000);
};