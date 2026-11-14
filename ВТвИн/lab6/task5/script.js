// Найти элемент по id
let textInput = document.getElementById('textInput');
let mirrorText = document.getElementById('mirrorText');

// Назначить обработчик события 'input' на поле ввода
textInput.oninput = function() {
    // Записываем текущее значение из поля ввода (textInput.value) внутрь элемента <span>
    mirrorText.textContent = textInput.value;
};