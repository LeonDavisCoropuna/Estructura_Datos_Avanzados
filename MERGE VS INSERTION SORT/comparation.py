import matplotlib.pyplot as plt

# Lee los datos del primer archivo

archivo1 = 'data/merge.txt'
with open(archivo1, 'r') as file1:
    tiempos1 = [float(line.strip()) for line in file1]

# Lee los datos del segundo archivo
archivo2 = 'data/insertion.txt'
with open(archivo2, 'r') as file2:
    tiempos2 = [float(line.strip()) for line in file2]

# Crea el gráfico comparativo
plt.figure(figsize=(10, 6))  # Ajusta el tamaño de la figura según tus preferencias

etiquetas = ['10', '200', '1000', '5000', '10000','20000','50000']  # Array de etiquetas para el eje X

plt.plot(etiquetas, tiempos1, label='MergeSort', marker='o',)  # Primer conjunto de datos
plt.plot(etiquetas, tiempos2, label='InsertionSort', marker='s')  # Segundo conjunto de datos

plt.xlabel('Nro de Datos')  # Etiqueta del eje X
plt.ylabel('Tiempo (segundos)')  # Etiqueta del eje Y
plt.title('MergeSort vs InsertionSort')  # Título del gráfico
plt.legend()  # Muestra la leyenda

plt.grid(True)  # Muestra una cuadrícula en el gráfico

plt.tight_layout()  # Ajusta el diseño para que se ajuste correctamente

# Guarda el gráfico en un archivo de imagen (opcional)
plt.savefig('result.png')

# Muestra el gráfico
plt.show()
