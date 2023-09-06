import pathlib
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np

# Font settings
mpl.rcParams['mathtext.fontset'] = 'cm'

file_path = pathlib.Path('./bin/number_of_comparaciones.txt')
with open(file_path) as f:
    lines = f.readlines()
    numbers = [int(line) for line in lines]

fig, ax = plt.subplots()
x = np.arange(1, 1e7, 1e4)

ax.plot(x, numbers, label=r'Numero de Comparaciones')
ax.legend()
fig.savefig('./img/p2-1.png', transparent=False, dpi=200)
ax.clear()

ax.plot(x, x**2, label=r'$n^2$')
ax.legend()
fig.savefig('./img/p2-2.png', transparent=False, dpi=200)
ax.clear()

ax.plot(x, numbers, label=r'Numero de Comparaciones')
ax.plot(x, x**2, label=r'$n^2$')
ax.legend()
fig.savefig('./img/p2-3.png', transparent=False, dpi=200)
ax.clear()

ax.plot(x, numbers, label=r'Numero de Comparaciones')
ax.plot(x, x**2, label=r'$n^2$')
ax.plot(x, x, label=r'$n$')
ax.plot(x, x*np.log(x), label=r'$n\log(n)$')
ax.legend()
fig.savefig('./img/p2-4.png', transparent=False, dpi=200)
ax.clear()

n = 10
x = np.arange(1, 1e4 * n, 1e4)
ax.plot(x, numbers[:n], label=r'Numero de Comparaciones')
ax.plot(x, x**2, label=r'$n^2$')
ax.plot(x, x, label=r'$n$')
ax.plot(x, x*np.log(x), label=r'$n\log(n)$')
ax.legend()
fig.savefig('./img/p2-5.png', transparent=False, dpi=200)
ax.clear()
