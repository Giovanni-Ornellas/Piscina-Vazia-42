# Função `write` em C

A função `write` é usada em C para escrever dados em arquivos ou dispositivos. Ela pertence à biblioteca padrão do sistema Unix/Linux e oferece um controle de baixo nível para operações de entrada/saída.

### Sintaxe
```c
ssize_t write(int fd, const void *buf, size_t count);
```

- **`fd`**: Descritor de arquivo (file descriptor), que identifica onde você deseja escrever. Pode ser um arquivo ou um dispositivo como a saída padrão (`stdout`).
- **`buf`**: Ponteiro para o buffer que contém os dados a serem escritos.
- **`count`**: Número de bytes a serem escritos a partir do buffer.

### Retorno:
- O número de bytes que foram efetivamente escritos.
- Retorna `-1` em caso de erro e define `errno` com o código do erro.

---

# Exercícios

### Exercício 1: Escrevendo uma string no terminal
Escreva um programa que usa a função `write` para imprimir a frase `"Exercício 1: Hello World!\n"` no terminal.

**Dica**: Use o descritor de arquivo `1` para a saída padrão (stdout).

#### Gabarito:
```c
#include <unistd.h>
#include <string.h>

int main() {
    const char *text = "Exercício 1: Hello World!\n";
    write(1, text, strlen(text));
    return 0;
}
```

---

### Exercício 2: Salvando texto em um arquivo
Crie um programa que abre (ou cria) um arquivo chamado `exercicio2.txt` e escreve a frase `"Exercício 2: Escrevendo no arquivo!\n"` no arquivo usando a função `write`.

**Dica**: Use as funções `open` e `close` para abrir e fechar o arquivo.

#### Gabarito:
```c
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    const char *text = "Exercício 2: Escrevendo no arquivo!\n";
    
    fd = open("exercicio2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        return 1; // Falha ao abrir o arquivo
    }
    
    write(fd, text, strlen(text));
    close(fd);
    
    return 0;
}
```

---

### Exercício 3: Concatenando texto em um arquivo
Modifique o programa do **Exercício 2** para que ele **não sobrescreva** o conteúdo existente no arquivo, mas sim acrescente a frase `"Exercício 3: Adicionando mais texto ao arquivo!\n"` ao final.

**Dica**: Use a flag `O_APPEND` ao abrir o arquivo.

#### Gabarito:
```c
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    const char *text = "Exercício 3: Adicionando mais texto ao arquivo!\n";
    
    fd = open("exercicio2.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        return 1; // Falha ao abrir o arquivo
    }
    
    write(fd, text, strlen(text));
    close(fd);
    
    return 0;
}
```

---

### Exercício 4: Escrevendo múltiplas linhas
Escreva um programa que escreve três frases diferentes no terminal, uma de cada vez, usando três chamadas diferentes para `write`.

As frases são:
- `"Exercício 4: Primeira linha\n"`
- `"Exercício 4: Segunda linha\n"`
- `"Exercício 4: Terceira linha\n"`

#### Gabarito:
```c
#include <unistd.h>
#include <string.h>

int main() {
    const char *line1 = "Exercício 4: Primeira linha\n";
    const char *line2 = "Exercício 4: Segunda linha\n";
    const char *line3 = "Exercício 4: Terceira linha\n";

    write(1, line1, strlen(line1));
    write(1, line2, strlen(line2));
    write(1, line3, strlen(line3));

    return 0;
}
```

---

### Exercício 5: Manipulando erro no `write`
Escreva um programa que tenta escrever em um arquivo de somente leitura e trate o erro, exibindo a mensagem `"Erro: Falha ao escrever no arquivo\n"` no terminal.

**Dica**: Para provocar o erro, crie um arquivo de somente leitura e use `write`. Use a variável `errno` para verificar o erro.

#### Gabarito:
```c
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main() {
    int fd;
    const char *text = "Exercício 5: Tentando escrever em arquivo somente leitura\n";
    
    fd = open("somente_leitura.txt", O_WRONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    if (write(fd, text, strlen(text)) == -1) {
        write(1, "Erro: Falha ao escrever no arquivo\n", 36);
    }

    close(fd);
    
    return 0;
}
```

---

### Como executar os exercícios:

1. Crie e compile os programas com um compilador C, como o `gcc`. Por exemplo, para compilar o **Exercício 1**:
   ```bash
   gcc exercicio1.c -o exercicio1
   ```

2. Execute o arquivo compilado:
   ```bash
   ./exercicio1