from DirectedGraph import *


def displayPathValues(subject) :

    print('< ', end = '')

    for node in subject :
        print(node.value(), ' ', end = '')

    print('>')


#
# Build a digraph P
#

Paaa = DirectedGraph.Node('aaa')
Pbbb = DirectedGraph.Node('bbb')
Pccc = DirectedGraph.Node('ccc')
Pddd = DirectedGraph.Node('ddd')
Peee = DirectedGraph.Node('eee')
Pfff = DirectedGraph.Node('fff')

Paaa.addNeighbors(Pbbb, Pccc)
Pbbb.addNeighbors(Peee, Pddd)
Pccc.addNeighbors(Pddd)
Pddd.addNeighbors(Pfff)
Peee.addNeighbors(Pddd, Pfff)

#
# Build a digraph Q
#

Qggg = DirectedGraph.Node('ggg')
Qhhh = DirectedGraph.Node('hhh')
Qiii = DirectedGraph.Node('iii')

Qggg.addNeighbors(Qhhh)
Qhhh.addNeighbors(Qiii)
Qiii.addNeighbors(Qggg)

#
# Perform Various Searches on P and Q
#

print('DFS from Paaa for ddd:')

displayPathValues(DirectedGraph.DFS(Paaa, lambda node : node == Pddd))

print('DFS from Paaa for x:')

displayPathValues(DirectedGraph.DFS(Paaa, lambda node : node.value() == 'x'))

print('DFS from Qggg for iii:')

displayPathValues(DirectedGraph.DFS(Qggg, lambda node : node == Qiii))

print('BFS from Paaa for ddd:')

displayPathValues(DirectedGraph.BFS(Paaa, lambda node : node == Pddd))

print('BFS from Paaa for x:')

displayPathValues(DirectedGraph.BFS(Paaa, lambda node : node.value() == 'x'))

print('BFS from Qggg for iii:')

displayPathValues(DirectedGraph.BFS(Qggg, lambda node : node == Qiii))
