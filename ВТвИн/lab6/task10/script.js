// Найти элемент по id
let boatContainer = document.getElementById('boatContainer');
let sendBtn = document.getElementById('sendBtn');
let mast = document.getElementById('mast');
let sailLeft = document.getElementById('sailLeft');
let sailRight = document.getElementById('sailRight');

// Флаг, чтобы повторный клик не перезапускал анимацию
let isSailing = false;

// Назначить обработчик клика на кнопку
sendBtn.onclick = function() {
    if (isSailing) return;
    isSailing = true;

    // Шаг 1: превращаем кнопку в корпус яхты и меняем надпись
    sendBtn.classList.add('boat-hull');
    sendBtn.textContent = 'Поплыли!';

    // Шаг 2: через 300 мс поднимаем и выравниваем мачту
    setTimeout(function() {
        mast.classList.add('raised');
    }, 300);

    // Шаг 3: через 850 мс раскрываем левый и правый паруса
    setTimeout(function() {
        sailLeft.classList.add('open');
        sailRight.classList.add('open');
    }, 850);

    // Шаг 4: через 1400 мс отправляем всю яхту за правый край экрана
    setTimeout(function() {
        boatContainer.classList.add('sail-away');
    }, 1400);
};