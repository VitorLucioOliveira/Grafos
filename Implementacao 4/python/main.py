from skimage import io
import matplotlib.pyplot as plt
from filter import *
from segment_graph import *
import time


def segmentacao(in_image, sigma, k, min_size):
    
    # Inicia e faz o pre-processamento da imagem
    inicio = time.time()
    altura, largura, faixa = in_image.shape
    print("Altura:  " + str(altura))
    print("Largura:   " + str(largura))
    
    # Suaviza o ruido de cada faixa de cor da imagem
    faixa_verrmelha = smooth(in_image[:, :, 0], sigma)
    faixa_verde = smooth(in_image[:, :, 1], sigma)
    faixa_azul = smooth(in_image[:, :, 2], sigma)

    
    
    # Construi o grafo
    # Cria um array de arestas, onde cada aresta é um vetor de 3 elementos
    # Vértice de origem/ Vértice de destino/ Peso da aresta
    arestas_size = largura * altura * 4
    arestas = np.zeros(shape=(arestas_size, 3), dtype=object)
    
    
    
    # Preenche o array de arestas conectando cada pixel com seus vizinhos
    num = 0
    for y in range(altura):
        for x in range(largura):
            # Conecta o pixel com seus vizinhos horizontais 
            if x < largura - 1:
                arestas[num, 0] = int(y * largura + x)
                arestas[num, 1] = int(y * largura + (x + 1))
                arestas[num, 2] = diff(faixa_verrmelha, faixa_verde, faixa_azul, x, y, x + 1, y)
                num += 1
            # Conecta o pixel com seus vizinhos verticais
            if y < altura - 1:
                arestas[num, 0] = int(y * largura + x)
                arestas[num, 1] = int((y + 1) * largura + x)
                arestas[num, 2] = diff(faixa_verrmelha, faixa_verde, faixa_azul, x, y, x, y + 1)
                num += 1
            # Conecta o pixel com seus vizinhos diagonais
            if (x < largura - 1) and (y < altura - 1):
                arestas[num, 0] = int(y * largura + x)
                arestas[num, 1] = int((y + 1) * largura + (x + 1))
                arestas[num, 2] = diff(faixa_verrmelha, faixa_verde, faixa_azul, x, y, x + 1, y + 1)
                num += 1
            # Conecta o pixel com seus vizinhos diagonais   
            if (x < largura - 1) and (y > 0):
                arestas[num, 0] = int(y * largura + x)
                arestas[num, 1] = int((y - 1) * largura + (x + 1))
                arestas[num, 2] = diff(faixa_verrmelha, faixa_verde, faixa_azul, x, y, x + 1, y - 1)
                num += 1
    
    
    # Segment
    u = segmenta_grafo(largura * altura, num, arestas, k)

    # Componentes menores que min_size são mesclados com componentes vizinhos maiores.
    for i in range(num):
        a = u.find(arestas[i, 0])
        b = u.find(arestas[i, 1])
        if (a != b) and ((u.size(a) < min_size) or (u.size(b) < min_size)):
            u.join(a, b)

    num_cc = u.num_sets()
    output = np.zeros(shape=(altura, largura, 3))

    # Cada componente recebe uma cor aleatória
    colors = np.zeros(shape=(altura * largura, 3))
    for i in range(altura * largura):
        colors[i, :] = random_rgb()
    
    # Pinta cada pixel com a cor do componente a que pertence
    for y in range(altura):
        for x in range(largura):
            comp = u.find(y * largura + x)
            output[y, x, :] = colors[comp, :]

    # Calcula o tempo de execução
    elapsed_time = time.time() - inicio
    print(
        "Execution time: " + str(int(elapsed_time / 60)) + " minute(s) and " + str(
            int(elapsed_time % 60)) + " seconds")

    # Mostra a imagem original e a segmentada
    imagem = plt.figure()
    a = imagem.add_subplot(1, 2, 1)
    plt.imshow(in_image)
    a.set_title('Imagem Original')
    a = imagem.add_subplot(1, 2, 2)
    output = output.astype(int)
    plt.imshow(output)
    a.set_title('Imagem Segmentada')
    plt.show()


if __name__ == "__main__":
    sigma = 0.5
    k = 500 # quanto maior o valor de 𝑘, menor será o número de componentes
    min = 50
    input_path = "data/gengar.jpg"

    # Loading the image
    input_image = io.imread(input_path)
    print("Loading is done.")
    print("processing...")
    segmentacao(input_image, sigma, k, min)
