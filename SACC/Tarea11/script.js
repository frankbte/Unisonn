const textInput = document.getElementById("textInput");
const submitButton = document.getElementById("submitButton");
const tabla = document.getElementById("tabla");

let valorUsuario = [];

textInput.addEventListener("input", function () {
  submitButton.disabled = textInput.value.length === 0;
});

submitButton.addEventListener("click", function () {
  agregarInput();
});

function agregarInput() {
  const inputValue = textInput.value.trim();
  if (inputValue) {
    valorUsuario.push(inputValue);
    textInput.value = "";
    submitButton.disabled = true;

    actualizarTabla();
  }
}

function actualizarTabla() {
  tabla.innerHTML = "";

  const numElementos = valorUsuario.length;
  const tamañoTabla = Math.ceil(Math.sqrt(numElementos));

  let indice = 0;

  for (let i = 0; i < tamañoTabla; i++) {
    const fila = document.createElement("tr");
    for (let j = 0; j < tamañoTabla; j++) {
      const celda = document.createElement("td");
      if (indice < numElementos) {
        celda.textContent = valorUsuario[indice];
        indice++;
      }
      fila.appendChild(celda);
    }
    tabla.appendChild(fila);
  }
}
