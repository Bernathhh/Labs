// Найти элемент по id
let container = document.getElementById('container');

// Назначить обработчик клика на контейнер
container.onclick = function(event) {
    // Найти ближайшую кнопку удаления с классом 'remove-button'
    let removeBtn = event.target.closest('.remove-button');
    
    if (!removeBtn) return;

    // Найти ближайшую родительскую карточку сообщения и удалить её
    let pane = removeBtn.closest('.pane');
    pane.remove();
};