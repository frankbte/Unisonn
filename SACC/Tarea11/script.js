const textInput = document.getElementById("textInput");
const submitButton = document.getElementById("submitButton");

let arreglo = [];

textInput.addEventListener("input", function () {
  submitButton.disabled = textInput.value.length === 0;
});

function agregarElemento(inputValue) {
  const li = document.createElement("li");
  li.textContent = inputValue;
  document.getElementById("historial").appendChild(li);
}

submitButton.addEventListener("click", function () {
  agregarInput(textInput);
});

function agregarInput(input) {
  const inputValue = textInput.value.trim();
  if (inputValue) {
    arreglo.push(inputValue);
    textInput.value = "";
    submitButton.disabled = true;

    agregarElemento(inputValue);
  }
}
