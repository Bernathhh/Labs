function func() {
    // Найти все элементы с классом "pr"
    let elements = document.querySelectorAll('.pr');

    // Перебираем найденные элементы по индексу
    for (let i = 0; i < elements.length; i++) {
        // Смена содержимого элемента (0+1)
        elements[i].innerHTML = i + 1;
    }
}