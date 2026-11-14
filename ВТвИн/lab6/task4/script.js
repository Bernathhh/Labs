// Найти элемент по id
let num1 = document.getElementById('num1');
let num2 = document.getElementById('num2');
let result = document.getElementById('result');
let btn = document.getElementById('btn');

// Назначить обработчик клика на кнопку
btn.onclick = function() {
    let sum = Number(num1.value) + Number(num2.value);

    result.textContent = sum;
};