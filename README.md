# Princípios de Projeto SOLID em C++

Este repositório demonstra quatro princípios fundamentais do design orientado a objetos — os princípios **S.O.L.I.D.** — implementados em **C++**. Cada princípio é explicado com definição teórica, problema que resolve, e exemplos de código comentados.

## ✅ Princípios abordados

- [S — Single Responsibility Principle (SRP)](#-s--single-responsibility-principle-srp)
- [O — Open-Closed Principle (OCP)](#-o--open-closed-principle-ocp)
- [L — Liskov Substitution Principle (LSP)](#-l--liskov-substitution-principle-lsp)
- [I — Interface Segregation Principle (ISP)](#-i--interface-segregation-principle-isp)

---

## 📘 S — Single Responsibility Principle (SRP)

> **O que é:** Uma classe deve ter apenas uma razão para mudar, ou seja, **uma única responsabilidade**.

> **Para que serve:** Promove coesão, facilita testes, manutenção e evolução do código.

### 📂 Exemplo de Código
Veja o exemplo em [`srp.cpp`](src/srp.cpp)

### 💡 Problema Resolvido
Antes: uma única classe `Report` gerava e imprimia relatórios, violando o princípio.

Depois: dividimos em `ReportGenerator` e `ReportPrinter`, cada uma com uma responsabilidade.

### 📌 Explicação
Com a separação:
- Alterar a lógica de geração **não impacta** a lógica de impressão.
- Podemos reutilizar `ReportPrinter` para diferentes fontes de dados.

---

## 📘 O — Open-Closed Principle (OCP)

> **O que é:** Classes devem estar **abertas para extensão**, mas **fechadas para modificação**.

> **Para que serve:** Permite adicionar novos comportamentos sem alterar código já existente/testado.

### 📂 Exemplo de Código
Veja o exemplo em [`ocp.cpp`](src/ocp.cpp)

### 💡 Problema Resolvido
Antes: a função `totalArea()` usava `if`/`switch` para tratar tipos diferentes de forma geométrica.

Depois: usamos uma interface `Shape`, e cada forma (`Circle`, `Square`, etc.) implementa seu próprio método `area()`.

### 📌 Explicação
- A função `totalArea()` opera de forma genérica.
- Novas formas (ex: `Triangle`) podem ser adicionadas sem tocar no código existente.

---

## 📘 L — Liskov Substitution Principle (LSP)

> **O que é:** Subclasses devem ser substituíveis por suas superclasses **sem alterar o comportamento esperado**.

> **Para que serve:** Garante que o uso de herança preserve o contrato da classe base.

### 📂 Exemplo de Código
Veja o exemplo em [`lsp.cpp`](src/lsp.cpp)

### 💡 Problema Resolvido
Antes: `Square` herda de `Rectangle`, mas altera comportamento dos métodos `setWidth` e `setHeight`, gerando comportamentos inesperados.

Depois: sugerimos evitar herança direta ou usar composição.

### 📌 Explicação
- A função `printArea(Rectangle&)` espera certo comportamento.
- Substituir por `Square` que altera o contrato causa **erros silenciosos** e quebra o princípio.

---

## 📘 I — Interface Segregation Principle (ISP)

> **O que é:** Nenhuma classe deve ser forçada a implementar métodos que **não utiliza**.

> **Para que serve:** Reduz acoplamento, melhora reutilização e coesão das interfaces.

### 📂 Exemplo de Código
Veja o exemplo em [`isp.cpp`](src/isp.cpp)

### 💡 Problema Resolvido
Antes: `OldPrinter` era forçado a implementar `scan()` mesmo sem suportar digitalização.

Depois: dividimos em interfaces menores: `IPrinter` e `IScanner`.

### 📌 Explicação
- Cada classe implementa **apenas os métodos necessários**.
- Evita exceções artificiais e implementações vazias.

---

## 📎 Organização dos Arquivos
├── srp.cpp → Exemplo de Single Responsibility Principle
├── ocp.cpp → Exemplo de Open-Closed Principle
├── lsp.cpp → Exemplo de Liskov Substitution Principle
├── isp.cpp → Exemplo de Interface Segregation Principle


## 🛠 Como Executar os Exemplos

Se você tem o compilador `g++` instalado, basta compilar e executar com:

```bash
g++ -o exemplo src/srp.cpp
./exemplo
