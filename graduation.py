class ConjuntoDisjunto:
    def __init__(self, tamanho):
        self.pais = [-1] * tamanho
        self.grupos = tamanho

    def encontrar(self, indice):
        if self.pais[indice] < 0:
            return indice
        self.pais[indice] = self.encontrar(self.pais[indice])
        return self.pais[indice]

    def tamanho(self, indice):
        return -self.pais[self.encontrar(indice)]

    def conectar(self, indice1, indice2):
        indice1, indice2 = self.encontrar(indice1), self.encontrar(indice2)
        if indice1 == indice2:
            return False
        if self.tamanho(indice1) > self.tamanho(indice2):
            indice1, indice2 = indice2, indice1
        self.pais[indice2] += self.pais[indice1]
        self.pais[indice1] = indice2
        self.grupos -= 1
        return True

    def grupos_restantes(self):
        return self.grupos


def main():
    n, _, k = map(int, input().split())
    cd = ConjuntoDisjunto(k)
    for coluna in zip(*(input() for _ in range(n))):
        for a, b in zip(coluna, coluna[1:]):
            cd.conectar(ord(a)-65, ord(b)-65)
    print(cd.grupos_restantes())


if __name__ == "__main__":
    main()

