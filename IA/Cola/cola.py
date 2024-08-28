class cola:
    def __init__(self):
        self.items = []

    def esta_vacia(self):
        return len(self.items) == 0

    def encolar(self, valor):
        self.items.append()

    def desencolar(self):
        if self.esta_vacia():
            raise IndexError("La cola esta vacia...")
        return self.items.pop(0)
    
    

        