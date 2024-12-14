from disjoint_set import *
import math
import numpy as np
import random



def segmenta_grafo(num_vertices, num_arestas, arestas, c):
    
    # Ordena as arestas do grafo pelo peso de forma NÃO-decrescente (coluna 3)
    arestas[0:num_arestas, :] = arestas[arestas[0:num_arestas, 2].argsort()]
    
    #  Inicialização do Conjunto Disjunto
    u = universe(num_vertices)
    
    #  Inicialização do vetor de limiares
    limiar = np.zeros(shape=num_vertices, dtype=float)   
    for i in range(num_vertices):
        limiar[i] = get_threshold(1, c)

    # Itinerar sobre as arestas do grafo
    for i in range(num_arestas):
        pedge = arestas[i, :]

        # Pega os componentes conectados
        c1 = u.find(pedge[0])
        c2 = u.find(pedge[1])
        
        # Se os componentes não são os mesmos e o peso da aresta que une eles é menor que o limiar junta os componentes
        if c1 != c2:
            if pedge[2] <= min(limiar[c1], limiar[c2]):
                u.join(c1, c2)
                c1 = u.find(c1)
                c2 = u.find(c2)
                limiar[c1] = pedge[2] + get_threshold(u.size(c1), c)
                limiar[c2] = limiar[c1]

    return u


def get_threshold(size, c):
    return c / size


# ao quadrado
def quadrado(value):
    return value * value


# escolhe uma cor aleatória
def random_rgb():
    rgb = np.zeros(3, dtype=int)
    rgb[0] = random.randint(0, 255)
    rgb[1] = random.randint(0, 255)
    rgb[2] = random.randint(0, 255)
    return rgb


# calcula a diferença entre a cor de dois pixels
def diff(red_band, green_band, blue_band, x1, y1, x2, y2):
    result = math.sqrt(
        quadrado(red_band[y1, x1] - red_band[y2, x2]) + quadrado(green_band[y1, x1] - green_band[y2, x2]) + quadrado(
            blue_band[y1, x1] - blue_band[y2, x2]))
    return result
