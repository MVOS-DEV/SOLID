// Antes: classe com dupla responsabilidade (gera e imprime relatório)
class Report {
    public:
        void generate() {
            // Lógica para gerar os dados do relatório
        }
        void print() {
            // Lógica para imprimir o relatório
        }
    };
    
    // Depois: responsabilidades separadas em classes distintas
    class ReportGenerator {
    public:
        void generate() {
            // Lógica para gerar os dados do relatório
        }
    };
    
    class ReportPrinter {
    public:
        void print() {
            // Lógica para imprimir o relatório
        }
    };
    