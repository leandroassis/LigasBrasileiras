# Especificações de uso

### 1. Compilação
Basta rodar o comando `make` na pasta raiz do projeto. Isso irá gerar o executável `ligas` na raiz do projeto.

### 2. Execução
Para executar o projeto basta rodar o executável `ligas`. É possível fornecer o número de times e o número de anos que o programa deve ter. Caso não seja fornecido nenhum parâmetro, o programa irá rodar com os valores padrão de 5 times e 8 anos.

```
./ligas <número de times> <número de anos>
```
O comando acima irá executar o programa com os parâmetros fornecidos.

### 3. Descrição do funcionamento

O programa cria, automaticamente, 3 ligas (Campeonato Brasileiro, Campeonato Carioca e Libertadores) e T times em cada (valor de T padrão ou recebido por linha de comando). 

A criação automática se dá pois o construtor da classe Liga inicializa um vetor com T times, além de dar nomes e o tamanho N do vetor de anos que cada time possui. O construtor da classe Ano gera um número aleatório para os GolsSofridos e GolsEfetuados.

Dessa forma, ao inicializar as 3 ligas, são gerados os T times para cada indice do vetor de ligas (na verdade são objetos dentro do objetos de ligas) e cada time tem N objetos de anos.



### 4. Estrutura das classes

As estruturas seguem um esquema semelhante a uma matriz tridimensional baseado em classes. A primeira dimensão da "matriz" é a classe Liga, a segunda é a classe Time e a terceira é a classe Ano. 

O programa não usa necessariamente uma matriz tridimensional. A estrutura é apenas uma analogia para facilitar o entendimento. Na realidade, o programa usa um vector de Ligas de tamanho 3 (um item para cada liga) e cada Liga possui um vector de Times de tamanho T (um item para cada time) e cada Time possui um vector de Anos de tamanho N (um item para cada ano), onde cada item ano possui os gols sofridos e efetuados pelo time naquele ano e liga.

Similarmente ao caso de uma matriz tridimensional, pode-se acessar o item (i, j, k) da "matriz" usando Ligas[i].Times[j].getGolsSofridosNoAno(k). Para parecer mais com o acesso em uma matriz tridimensional, poderia-se utilizar o operador de indexação sobrecarregado.

