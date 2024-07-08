import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad
from statsmodels.graphics.tsaplots import plot_acf

# Funciones de onda teóricas
def phi_200_teorica(r):
    return (1.0 / (4 * np.sqrt(2 * np.pi))) * (2 - r) * np.exp(-r / 2)

def phi_21m1_teorica(r):
    return (1.0 / (8 * np.sqrt(6 * np.pi))) * r * np.exp(-r / 2)

# Leer los datos del archivo
samples_200 = np.loadtxt('samples_200.txt')
samples_21m1 = np.loadtxt('samples_21m1.txt')

# Filtrar los valores negativos (en caso de que existan)
samples_200 = samples_200[samples_200 >= 0]
samples_21m1 = samples_21m1[samples_21m1 >= 0]

# Función para normalizar la distribución teórica
def normalizar(func, r_min, r_max):
    integral, _ = quad(func, r_min, r_max)
    return lambda r: func(r) / integral

# Normalizar las funciones de densidad de probabilidad teóricas
phi_200_norm = normalizar(lambda r: phi_200_teorica(r)**2, 0, 20)
phi_21m1_norm = normalizar(lambda r: phi_21m1_teorica(r)**2, 0, 20)

# Crear el histograma de las muestras para Phi_200
plt.figure(figsize=(10, 6))
count, bins, ignored = plt.hist(samples_200, bins=50, density=True, alpha=0.6, color='b', edgecolor='black', label='Muestras')

# Calcular la distribución teórica normalizada para Phi_200
r = np.linspace(0, max(samples_200), 100)
p = phi_200_norm(r)

# Graficar la distribución teórica normalizada para Phi_200
plt.plot(r, p, 'r--', linewidth=2, label='Distribución teórica normalizada')

# Añadir títulos y etiquetas para Phi_200
plt.title('Histograma de los valores de $r$ y comparación con la distribución teórica normalizada para $\Phi_{200}$')
plt.xlabel('$r$ (unidades de $a_0$)')
plt.ylabel('Densidad de probabilidad')
plt.legend()
plt.grid(True)

# Mostrar el gráfico para Phi_200
plt.show()

# Crear el histograma de las muestras para Phi_21m1
plt.figure(figsize=(10, 6))
count, bins, ignored = plt.hist(samples_21m1, bins=50, density=True, alpha=0.6, color='b', edgecolor='black', label='Muestras')

# Calcular la distribución teórica normalizada para Phi_21m1
r = np.linspace(0, max(samples_21m1), 100)
p = phi_21m1_norm(r)

# Graficar la distribución teórica normalizada para Phi_21m1
plt.plot(r, p, 'r--', linewidth=2, label='Distribución teórica normalizada')

# Añadir títulos y etiquetas para Phi_21m1
plt.title('Histograma de los valores de $r$ y comparación con la distribución teórica normalizada para $\Phi_{21-1}$')
plt.xlabel('$r$ (unidades de $a_0$)')
plt.ylabel('Densidad de probabilidad')
plt.legend()
plt.grid(True)

# Mostrar el gráfico para Phi_21m1
plt.show()

# Crear el gráfico de traza para Phi_200
plt.figure(figsize=(10, 6))
plt.plot(samples_200, alpha=0.6)
plt.title('Gráfico de Traza de la Cadena de Markov para $\Phi_{200}$')
plt.xlabel('Iteración')
plt.ylabel('$r$ (unidades de $a_0$)')
plt.grid(True)
plt.show()

# Crear el gráfico de traza para Phi_21m1
plt.figure(figsize=(10, 6))
plt.plot(samples_21m1, alpha=0.6)
plt.title('Gráfico de Traza de la Cadena de Markov para $\Phi_{21-1}$')
plt.xlabel('Iteración')
plt.ylabel('$r$ (unidades de $a_0$)')
plt.grid(True)
plt.show()

# Calcular y graficar la autocorrelación para Phi_200
plot_acf(samples_200, lags=100)
plt.title('Autocorrelación de la Cadena de Markov para $\Phi_{200}$')
plt.show()

# Calcular y graficar la autocorrelación para Phi_21m1
plot_acf(samples_21m1, lags=100)
plt.title('Autocorrelación de la Cadena de Markov para $\Phi_{21-1}$')
plt.show()
