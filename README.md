# Worst implementation of Prim. Ever.

Zadanie [PL]:
Lotnisko w San Escobar pęka w szwach! To oczywiście efekt ogromnego ruchu lotniczego
z Polski, jaki nastąpił po nawiązaniu stosunków dyplomatycznych między oboma krajami. Jako
minister transportu republiki postanowiłaś wybudować nowe lotnisko dla naszych narodowych
linii lotniczych El Niño i to natychmiast. W tym celu na pas startowy zostanie przerobiony jeden z
odcinków sieci autostrad w naszym kraju. Sieć autostrad na planach ma kształt grafu, a
wierzchołkami są poszczególne miasta. Napisz algorytm, który ustali, który odcinek sieci
autostrad należy poświęcić pod pas startowy, tak aby suma odległości ze stolicy kraju, Santo
Subito, do pozostałych miast pozostała jak najmniejsza.

Highway = edge (weight = distance, >0). 
City = vertex/node.
Capital city = root.
Use Prim algorithm to find highways, which are not part of MST.

Input:
List of highways.

Output:
List of highways, which are not part of MST.

Input format:
<number of edges>
<Name of capital city>
<Name of city 1> <Name of city 2> <Weight of edge>
<Name of city 1> <Name of city 2> <Weight of edge>
  ...
<Name of city 1> <Name of city 2> <Weight of edge>
