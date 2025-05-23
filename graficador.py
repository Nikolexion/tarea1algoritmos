import pandas as pd
import matplotlib
import matplotlib.pyplot as plt

# open a csv file
df_brute = pd.read_csv('bruteforce_256_2048_10.csv')
df_brute_better = pd.read_csv('optimized_bruteforce_256_2048_10.csv')
df_divide = pd.read_csv('divide_256_2048_10.csv')
df_divide_better = pd.read_csv('optimized_divide_256_2048_10.csv')

plt.plot(df_brute['n'], df_brute['t_mean'], label='Brute Force', marker='o', markersize = 1)
plt.plot(df_brute_better['n'], df_brute_better['t_mean'], label='Optimized Brute Force', marker='o', markersize = 1)
plt.plot(df_divide['n'], df_divide['t_mean'], label='Divide and Conquer', marker='o', markersize = 1)
plt.plot(df_divide_better['n'], df_divide_better['t_mean'], label='Optimized Divide and Conquer', marker='o', markersize = 1)

plt.xlabel('Tamaño de entrada (n)')
plt.ylabel('Tiempo de ejecución promedio (nanosegundos)')

# log=scale
plt.yscale('log')

# show legend
plt.legend()

# save graphic in a file
plt.savefig('comparativa_tiempos.png')
plt.show()
