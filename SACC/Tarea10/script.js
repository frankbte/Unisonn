function validarCampos() {
  var email = document.getElementById("email").value;
  var confirmEmail = document.getElementById("confirmEmail").value;

  var emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;

  if (email === "" || confirmEmail === "") {
    alert("Por favor, completa ambos campos.");
  } else if (!emailRegex.test(email)) {
    alert("El formato del correo electrónico es incorrecto.");
  } else if (email !== confirmEmail) {
    alert("Los correos electrónicos no coinciden.");
  } else {
    alert("La validación ha sido exitosa.");
    document.getElementById("email").value = "";
    document.getElementById("confirmEmail").value = "";
  }
}
