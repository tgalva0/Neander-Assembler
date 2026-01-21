# Montador Neander (Neander Assembler)

Este projeto é um **Montador (Assembler)** desenvolvido em C para a arquitetura do computador hipotético **Neander**. O programa lê um arquivo de texto (`.txt`) contendo instruções em Assembly e gera um arquivo binário (`.mem`) compatível com o simulador Neander.

## 📋 Funcionalidades

- **Leitura de Arquivos:** Lê arquivos `.txt` contendo código Assembly.
- **Conversão Automática:** Traduz mnemônicos (ex: `LDA`, `ADD`) e endereços hexadecimais para o formato binário do Neander.
- **Geração de Binário:** Cria automaticamente o arquivo `prog1.mem` com o cabeçalho correto (`.NDR`) para execução direta no simulador.
- **Flexibilidade:** Aceita instruções em letras maiúsculas ou minúsculas (Case Insensitive).

## 🛠️ Requisitos de Compilação

⚠️ **Atenção:** Este código foi projetado para ser compilado utilizando o **Dev-C++**.
O uso de outras IDEs ou compiladores (como GCC puro no Linux) pode gerar erros devido ao uso da biblioteca `<conio.h>` e funções específicas como `fflush(stdin)`.

## 🚀 Como Usar

1. **Compile o código** `assembler.c` (ou o nome que você escolheu) usando o Dev-C++.
2. **Crie um arquivo `.txt`** (ex: `codigo.txt`) na **mesma pasta** onde está o executável (`.exe`) gerado.
3. Escreva seu código Assembly neste arquivo (veja as regras de formatação abaixo).
4. **Execute o programa**.
5. Quando solicitado, digite o nome do arquivo com a extensão (ex: `codigo.txt`).
6. O programa irá gerar um arquivo chamado **`prog1.mem`**.
7. Abra o simulador Neander e carregue o arquivo `prog1.mem`.

## 📝 Regras de Formatação do Código (Syntax)

Para garantir que o montador funcione corretamente, siga estas regras estritas ao escrever seu arquivo `.txt`:

1. **Apenas Instruções:** O arquivo não deve conter números de linha ou comentários complexos na mesma linha de instrução.
2. **Endereços em Hexadecimal:** Todos os endereços de memória devem ser escritos em formato hexadecimal (ex: `80`, `F0`).
3. **Formato:** Instrução seguida (se necessário) pelo endereço.

### Exemplo de Arquivo de Entrada (`exemplo.txt`):

```assembly
lda 80
NOT
ADD 81
STA 83
Hlt
```

## 📚 Instruções Suportadas

O montador reconhece os seguintes mnemônicos:

| Mnemônico | Código (Decimal) | Descrição |
| :--- | :--- | :--- |
| **NOP** | 0 | Nenhuma Operação |
| **STA** | 16 | Armazena acumulador na memória |
| **LDA** | 32 | Carrega memória no acumulador |
| **ADD** | 48 | Soma memória ao acumulador |
| **OR** | 64 | OU lógico |
| **AND** | 80 | E lógico |
| **NOT** | 96 | Negação (Inverte bits do acumulador) |
| **JMP** | 128 | Desvio incondicional |
| **JN** | 144 | Desvio se negativo |
| **JZ** | 160 | Desvio se zero |
| **HLT** | 240 | Para a execução (Halt) |

## ⚠️ Solução de Problemas Comuns

- **Erro "Arquivo não encontrado":** Certifique-se de que o arquivo `.txt` está na mesma pasta do `.exe` e que você digitou a extensão corretamente (ex: digite `teste.txt` e não apenas `teste`).
- **Comportamento estranho no simulador:** Verifique se os endereços no seu código assembly estão em Hexadecimal e se não há caracteres inválidos no arquivo de texto.

---
*Projeto desenvolvido para fins educacionais.*
