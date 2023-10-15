#set document(title: "Tarea 4", author: "Antonio Barragán Romero")
#set text(font: ("New Computer Modern", "JetBrains Mono"))
#set par(justify: true)

#align(center, text(17pt)[
    *Análisis de Algoritmos y Matemáticas Discretas* \
    *Tarea 4*
])
#align(center, text(15pt)[Antonio Barragán Romero])

== Analisis de complejidad de MO-LTE

Sea $N$ la cantidad de elementos en nuestro arreglo y  $Q$ la cantidad de queries. Como se vio en clase el 
Algoritmo de Mo contesta las queries en cierto orden y para ello lo que hace es que mantiene 
un arreglo $[l, r]$,que se"expande" o se "contrae" (al pasar de una querie a otra), el cual
matiene la respuesa para ese intervalo.
Entonces la complejidad depende de que tanto $[l, r]$ se "expande" o se "contrae", ademas de la complejidad de 
obtener la respuesta.

Para contar la cantidad de numeros o iguales a cierta $M$ en cierto $[l, r]$, lo que haremos sera tener un arreglo $[0, 10^6]$ el 
cual contara las repeticiones de cada numero en $[l, r]$. 
Entonces cuando requiramos la cantidad de numeros menores o iguales a cierta $M$ en $[l, r]$, simplemente tendremos que 
sumar la cantidad de repeticiones en $[0, M]$. Por ello usaremos un `Fenwick Tree` #footnote[https://cp-algorithms.com/data_structures/fenwick.html],
pues nos permite calcular la suma de repeticiones en $[0, M]$ en $O(log N)$ ademas de que permite actualizar la cantidad de repetionces 
de un elemento en $O(log N)$.


// Para que $[l, r]$ mantega la respuesta usaremos un `Fenwick Tree` #footnote[https://cp-algorithms.com/data_structures/fenwick.html], 
// el cual contara las repeticiones de cada numero en $[l, r]$,
 
Como se vio en clase la complejidad esta dada por la cantidad de movientos de $l$ y de $r$ la cual , notemos ademas que anteriormente vimos que 
cada movimiento es $O(log N)$. Para contar la cantidad que se mueve el $r$, notemos que en cada bloque mueve $O(N)$, hay $sqrt(N)$ bloques 
y cada moviento cuesta $O(log N)$, entonces su complejidad es $O(N sqrt(N) log(N))$.
Para el caso de la $l$, notemos que como se ordenan por bloque se puede mover a lo mas $sqrt(N)$ y eso por cada queri, como 
cada movimiento cuesta $O(log N)$ tenemos que la complejidad es $O(Q sqrt(N)log(N))$. 
Ademas notemos que el obtener la respuesta cuesta $O(log(N))$  y eso se hace por cada queri, entonces la complejidad es $O(Q log(N))$.
En total la complejidad es $ O((N+Q)sqrt(N) log(N)) + O(Q log(N)) = O((N+Q)sqrt(N) log(N)). $
