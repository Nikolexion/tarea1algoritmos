import pandas as pd
import matplotlib
import matplotlib.pyplot as plt

# open a csv file
df = pd.read_csv('data.csv')

# graphic each line
# plot(x=values, y=values, label, points marker)
plt.plot(df['n'], df['brute force'], label='Brute Force', marker='o')
plt.plot(df['n'], df['divide conquer'], label='Divide and Conquer', marker='s')

# x=labels and y=labels
plt.xlabel('Running time (nanoseconds)')
plt.ylabel('Input size (log)')

# log=scale
plt.yscale('log')

# show legend
plt.legend()

# save graphic in a file
plt.savefig('plot.png')
