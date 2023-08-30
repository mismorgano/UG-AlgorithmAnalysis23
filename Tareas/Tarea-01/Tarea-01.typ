#set document(title: "Tarea 1 STL", author: "Antonio Barragán Romero")
#set text(font: (" Computer Modern", "JetBrains Mono"))

#align(center, text(17pt)[
  *Tarea 1 STL*
])
#align(center)[
  Antonio Barragán Romero\
  #link("antonio.barragan@cimat.mx")
]

== Problema 1 (Flechas y Zombies)

En este caso utilize una priority queue `priority_queue<int, vector<int>, greater<int>>` para guardar las flechas
pues 
permite conocer el top en #link("https://en.cppreference.com/w/cpp/container/priority_queue/top")[tiempo constante] 
$O(1)$,
además que agrega en #link("https://en.cppreference.com/w/cpp/container/priority_queue/push")[tiempo logaritmico] $O(log(n))$.

== Problema 2 (Alimentos)

Dadas las condiciones del problema, requeriamos una estructura que almacenara elementos del tipo clave-valor,
que pudiera actualizarlos y eliminarlos dada una clave, por lo cual escoger un map tenia sentido. 
Entonces escogí `map<string, int>`, sin embargo esto se mantiene ordenado dado el `string` y se requeria que 
fuese mediante el valor(`ìnt`). Una forma de arreglar esto hubiera sido recorrer toda la estructura y mantener
una variable `max` o algo por el estilo, lo cual haria la operación $O(n)$.


