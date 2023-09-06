import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np

## Font settings
mpl.rcParams['mathtext.fontset'] = 'cm'

## Inciso 1

#%%
x = np.arange(100)
en = (x*x + x)/2
gn = x*x

fig1, ax1 = plt.subplots()
ax1.plot(x, en, label=r'$e(n) = \frac{n(n+1)}{2}$')
ax1.plot(x, gn, label=r'$\Theta(n)=n^2$')
ax1.legend()
fig1.savefig('./img/inciso1.png', transparent=False, dpi=200, bbox_inches="tight")

## Inciso 2
#%%
x = np.arange(100)
en = 2*x -1
gn = x
fig2, ax2 = plt.subplots()
ax2.plot(x, en, label=r'$e(n) = 2n-1$')
ax2.plot(x, gn, label=r'$\Theta(n) = n$')
ax2.legend()
fig2.savefig('./img/inciso2.png', transparent=False, dpi=200, bbox_inches='tight')