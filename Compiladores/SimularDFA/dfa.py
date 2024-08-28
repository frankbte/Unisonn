# Definición de la tabla de transición y los estados de aceptación
tablaTransicion = [
    [1, -1, -1],  # Estado 0: Transiciones para el primer octeto
    [1, 2, -1],   # Estado 1: Transiciones para el segundo octeto
    [3, -1, -1],  # Estado 2: Transiciones para el tercer octeto
    [3, -1, -1]   # Estado 3: Transiciones para el cuarto octeto (estado de aceptación)
]

estadosAceptacion = [False, False, False, True]  # El estado 3 es de aceptación

# Función para simular el DFA
def simulaDFA(input_string):
    state = 0
    octet_value = ""
    octet_count = 0
    for symbol in input_string:
        if estadosAceptacion[state]:
            return True
        if symbol.isdigit():
            octet_value += symbol
            if int(octet_value) > 255:
                return False  # Número fuera de rango
        elif symbol == '.':
            if not octet_value or octet_count == 3:
                return False  # Octeto vacío o demasiados octetos
            octet_value = ""
            octet_count += 1
        else:
            return False  # Caracter no válido
    if octet_count != 3:
        return False  # No hay suficientes octetos
    if not octet_value or int(octet_value) > 255:
        return False  # Último octeto vacío o fuera de rango
    return True

# Función para leer direcciones IP desde un archivo
def leer_direcciones_desde_archivo(archivo):
    with open(archivo, 'r') as file:
        for line in file:
            ip_address = line.strip()
            if simulaDFA(ip_address):
                print("La dirección IP '{}' es válida.".format(ip_address))
            else:
                print("La dirección IP '{}' no es válida.".format(ip_address))

# Ejemplo de uso
archivo = "direcciones.txt"  # Nombre del archivo que contiene las direcciones IP
leer_direcciones_desde_archivo(archivo)
