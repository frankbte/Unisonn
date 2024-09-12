function ponerFormato() {
  document.getElementById("formulario").style.backgroundColor = "#f0f8ff";
  document.getElementById("nombre").style.fontWeight = "bold";
  document.getElementById("clave").style.fontStyle = "italic";
  document.getElementById("mensaje").textContent = "";
}

function borrarTodo() {
  document.getElementById("formulario").style.display = "none";
  document.getElementById("botones").style.display = "none";
  document.getElementById("mensaje").textContent = "Acceso No Permitido";
}

function mostrarTodo() {
  document.getElementById("formulario").style.display = "block";
  document.getElementById("mensaje").textContent = "";
}

function noTocar() {
  alert("¡Advertencia! No deberías haber tocado este botón.");
}
