# Leer los datos del archivo
sampled_points7 = []
with open('testeod.txt', 'r') as file:
    for line in file:
        sampled_points7.append(float(line.strip()))

# Crear el histograma de los puntos muestreados
plt.hist(sampled_points7, bins=50, density=True, alpha=0.6, color='g', label='Sampled distribution')

# Definir la distribución objetivo (la mezcla de dos gaussianas)
def target_distribution(x):
    return 0.5 * (1.0 / np.sqrt(2.0 * np.pi * 0.25)) * np.exp(-np.power((x - 1.0), 2) / (2 * 0.25)) \
         + 0.5 * (1.0 / np.sqrt(2.0 * np.pi * 1.0)) * np.exp(-np.power((x + 1.5), 2) / (2 * 1.0))

# Generar valores de x para la distribución objetivo
x = np.linspace(-5, 5, 1000)
y = target_distribution(x)

# Graficar la distribución objetivo
plt.plot(x, y, label='Target distribution', color='r')

# Añadir leyenda y etiquetas
plt.legend()
plt.xlabel('x')
plt.ylabel('Density')
plt.title('Metropolis-Hastings Sampling')

# Mostrar la gráfica
plt.show()