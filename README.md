# Sculptor
Deve ser desenvolvida uma classe, denominada Sculptor, que permite a definição de objetos 3D a partir da composição de formas simples. O modelo gerado deve poder ser exportado em um formato de descrição 3D (formato OFF). 

Especificação o projeto:

   https://www.dropbox.com/s/ytsidppb8ad4s1k/sculptor-especificacao.pdf?dl=0
   
   
Links de interesse:

   http://people.sc.fsu.edu/~jburkardt/data/off/off.html


Visualizadores de arquivos .off:
    
    Windows:
        - MeshLab;
        - Roftview;
        - Blender;
    
    Mac OS:
        - MeshLab;
        - Roftview;
    
    Linux:
        - MeshLab;
        - Roftview;
        

<h3>
    <font color="#c9040a"> Descrição global do projeto </font>
</h3>

<h4>
    <font color="#c9040a"> ETAPAS DA ESCULTURA </font>
</h4>

1) Imagine o objeto [MENTALMENTE];

2) Decomponha o objeto em formas aditivas e/ou subtrativas "simples" que façam aprte da sua classe Sculptor [MENTALMENTE];

2.1) Se for o caso, defina novas primitivas para a classe Sculptor;

3) Faça o código-fonte que chama cada uma das primitivas (put__, cut__) na ordem apropriada;

4) Execute o programa, que deve gerar como resultado final um arquivo em formato .off cotendo a escultura do objeto desejado;

<h4>
    <font color="#c9040a"> EXECUÇÃO DO PROGRAMA </font>
</h4>

1) Crie uma "matriz" 3D de voxels, inicialmente com dimensões e origem nulas, para armazenar a representação discretizada do objeto;

2) Cada primtiiva de desenho (put__, cut__), ao ser executada, inclui um elemento em uma lista de formas que compõem a escultura. Formas são objetos polimórficos;

2.1) A cada forma inserida na escultura, a origem e a dimensão da matriz de voxels é ajustada, caso necessário, para conter a nova forma;

2.1.1) Para fazer os ajustes, comapre os limites da forma, dados pelos vértices do seu cubo envolvente, com os limites atuais da matriz, expandindo-os se for o caso para poder conter a nova forma;

2.1.1.1) Para formas rotacionadas, a determnação dos limites x, y e z do cubo envolvente pode ser feita analisando os 8 pontos que correspondem aos vértices do cubo envolvente não rotacionado, expresso no sistema de coordenadas rotacionado;

2.1.1.2) Apenas as formas aditivas (put__) alteram eventuamente as dimensões da matriz;

2.2) Após dimensionada a matriz, cada forma é discretizada (esuclpida) na matriz;
