function calcularMCD(a, b) {
  while (b !== 0) {
    let temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

function calcularMCM(a, b, mcd) {
  return (a * b) / mcd;
}

function mostrarMCD() {
  let inicio = Math.floor(Math.random() * (100 - 50 + 1)) + 50;
  let fin = Math.floor(Math.random() * (500 - 100 + 1)) + 100;

  let mcd = calcularMCD(inicio, fin);

  document.getElementById("resultado-mcd").innerHTML = `
      <p>Número inicial: ${inicio}</p>
      <p>Número final: ${fin}</p>
      <p>MCD: ${mcd}</p>
  `;
}

function mostrarMCM() {
  let inicio = Math.floor(Math.random() * (100 - 50 + 1)) + 50;
  let fin = Math.floor(Math.random() * (500 - 100 + 1)) + 100;

  let mcd = calcularMCD(inicio, fin);

  let mcm = calcularMCM(inicio, fin, mcd);

  document.getElementById("resultado-mcm").innerHTML = `
      <p>Número inicial: ${inicio}</p>
      <p>Número final: ${fin}</p>
      <p>MCD: ${mcd}</p>
      <p>MCM: ${mcm}</p>
  `;
}
