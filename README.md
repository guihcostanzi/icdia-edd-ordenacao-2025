# Relatório de Comparação de Algoritmos de Ordenação

## Introdução

O objetivo deste experimento foi comparar o desempenho de dois algoritmos de ordenação: **Bubble Sort** e **Quicksort**. Ambos foram aplicados para ordenar um conjunto de pratos (com nomes gerados aleatoriamente), classificados por prioridade e tempo de preparo.

Observação: Foi commitada uma versão com um número menor de pratos, mas para alterar a quantidade de pratos, basta alterar a variável de controle "n", que se localiza na main. Esta versão está limitada para fins de teste.

## Algoritmos Utilizados

### Bubble Sort

O **Bubble Sort** é um algoritmo simples que percorre repetidamente a lista, trocando elementos adjacentes quando estão fora de ordem. Sua complexidade no pior caso é **O(n²)**, tornando-o ineficiente para grandes conjuntos de dados.

### Quicksort

O **Quicksort** é um algoritmo de ordenação eficiente baseado na técnica de divisão e conquista. Sua complexidade média é **O(n log n)**, tornando-o adequado para grandes quantidades de dados.

## Escolha do Pivô no Quicksort

O pivô utilizado no Quicksort foi determinado pela **técnica da mediana de três**. Essa abordagem escolhe o pivô como a mediana entre o primeiro, o último e o elemento do meio do subarray. Isso melhora a performance ao evitar o pior caso em listas quase ordenadas, garantindo um particionamento mais equilibrado.

## Resultados de Execução

A medição do tempo de execução foi feita utilizando a biblioteca `chrono`, garantindo precisão em microssegundos.

| Algoritmo   | Tempo de Execução |                 |
| ----------- | ----------------- | --------------- |
| Bubble Sort | \~                | **muito maior** |
| Quicksort   | \~ **menor**      |                 |

Os resultados mostram que o **Quicksort** teve um desempenho significativamente melhor do que o **Bubble Sort**, o que já era esperado devido às diferenças de complexidade.

## Conclusão

O **Quicksort** demonstrou ser muito mais eficiente do que o **Bubble Sort**, sendo a escolha mais adequada para conjuntos de dados grandes. A estratégia da **mediana de três** para escolha do pivô garantiu um melhor balanceamento das partições, contribuindo para a eficiência do algoritmo.

