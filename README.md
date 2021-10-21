# Dactylo-chute
Mini projet de FISE1 à Télécom Saint-Etienne

## UML diagrams
Possibilité d'afficher des diagrames uml ici même en générant avec [stackedit](
(stackedit.io) ) , cf [Mermaid](https://mermaidjs.github.io/).

```mermaid
sequenceDiagram
Alice ->> Bob: Hello Bob, how are you?
Bob-->>John: How about you John?
Bob--x Alice: I am good thanks!
Bob-x John: I am good thanks!
Note right of John: Bob thinks a long<br/>long time, so long<br/>that the text does<br/>not fit on a row.

Bob-->Alice: Checking with John...
Alice->John: Yes... John, how are you?
```

...et des flow chart:

```mermaid
graph LR
A[Square Rect] -- Link text --> B((Circle))
A --> C(Round Rect)
B --> D{Rhombus}
C --> D
```
