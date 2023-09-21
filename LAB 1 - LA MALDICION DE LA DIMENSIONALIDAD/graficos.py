import matplotlib.pyplot as plt

# Leer las distancias desde el archivo de texto
with open('files/5000.txt', 'r') as archivo:
    distancias = [float(linea.strip()) for linea in archivo]

# Crear el histograma
plt.hist(distancias, bins=10, color='blue', edgecolor='black')

# Personalizar el gráfico
plt.title('MALDICION DE LA DIMENSIONALIDAD - D5000')
plt.xlabel('Distancia')
plt.ylabel('Frecuencia')
plt.grid(True)

# Mostrar el histograma
plt.show()
