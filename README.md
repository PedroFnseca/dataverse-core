# Dataverse Core - Estruturas de Dados em C

Este repositório contém implementações de estruturas de dados fundamentais em linguagem C. As estruturas de dados são componentes essenciais na programação, permitindo o armazenamento e organização eficiente de dados na memória do computador.

## 🎯 Importância das Estruturas de Dados

As estruturas de dados são fundamentais para:

- Organização eficiente de dados
- Otimização de performance em algoritmos
- Melhor utilização de memória
- Resolução de problemas complexos de forma elegante
- Base para desenvolvimento de software robusto

## 📚 Estruturas Implementadas

### Estruturas Lineares

- [Array](./array) - Estrutura básica de armazenamento sequencial
- [Lista Ligada Linear](./lista_ligada_linear) - Elementos conectados por ponteiros de forma linear
- [Lista Ligada Circular](./lista_ligada_circular) - Lista ligada onde o último elemento aponta para o primeiro
- [Pilha](./pilha) - Estrutura LIFO (Last In, First Out)
- [Fila](./fila) - Estrutura FIFO (First In, First Out)
- [Matriz](./matriz) - Estrutura bidimensional de dados

### Estruturas Hierárquicas

- [Árvore Binária de Busca (ABB)](./arvore_ABB) - Árvore binária ordenada
- [Árvore AVL](./arvore_AVL) - Árvore binária de busca balanceada

### Estruturas de Acesso Direto

- [Hash](./hash) - Tabela hash para acesso direto aos dados

## 🛠️ Como Compilar

Este projeto inclui um script de compilação para Windows. Para compilar uma estrutura:

1. Na raiz do projeto, execute o comando:

```bash
compiler.bat nome_da_pasta
```

Por exemplo:

```bash
compiler.bat array      # Compila a implementação de Array
compiler.bat pilha     # Compila a implementação de Pilha
compiler.bat fila      # Compila a implementação de Fila
```

O executável será gerado na pasta `bin`

## 📖 Documentação

Cada estrutura de dados possui seu próprio README com:

- Explicação teórica
- Complexidade das operações
- Exemplos de uso
- Documentação do código

Para mais detalhes sobre o formato da documentação, consulte o [template](./docs/template.md).

## 🤝 Contribuição

Sinta-se à vontade para contribuir com:

- Novas estruturas de dados
- Melhorias nas implementações existentes
- Correções de bugs
- Documentação
- Exemplos de uso

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.
