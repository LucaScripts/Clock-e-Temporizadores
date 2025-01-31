#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos GPIO correspondentes aos LEDs do semáforo
#define LED_VERDE 11   // LED Verde - Sinal de "Siga"
#define LED_AMARELO 12 // LED Amarelo - Sinal de "Atenção"
#define LED_VERMELHO 13 // LED Vermelho - Sinal de "Pare"

// Tempo de troca dos sinais do semáforo (em milissegundos)
#define INTERVALO_TROCA_SINAL 3000

// Função para configurar os pinos GPIO
void configurar_gpio() {
    // Inicializa os pinos dos LEDs
    gpio_init(LED_VERDE);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERMELHO);

    // Define os pinos como saída
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    // Inicializa o semáforo no sinal vermelho (estado inicial)
    gpio_put(LED_VERMELHO, 1);  // Liga o LED vermelho
    gpio_put(LED_AMARELO, 0);   // Apaga o LED amarelo
    gpio_put(LED_VERDE, 0);     // Apaga o LED verde
}

// Função callback do temporizador que controla a mudança de sinal do semáforo
bool atualizar_semaforo(struct repeating_timer *temporizador) {
    static int estado_semaforo = 1; // Começa no estado vermelho (1)

    // Alterna o estado do semáforo de forma cíclica: 1 → 2 → 3 → 1
    estado_semaforo = (estado_semaforo % 3) + 1;

    // Atualiza os LEDs de acordo com o estado do semáforo
    gpio_put(LED_VERDE, estado_semaforo == 3);  // Acende LED verde se estado == 3
    gpio_put(LED_AMARELO, estado_semaforo == 2); // Acende LED amarelo se estado == 2
    gpio_put(LED_VERMELHO, estado_semaforo == 1); // Acende LED vermelho se estado == 1

    // Exibe uma mensagem na saída serial indicando o estado do semáforo
    switch (estado_semaforo) {
        case 1:
            printf("🚦 PARE! O semáforo está VERMELHO.\n");
            break;
        case 2:
            printf("⚠️  ATENÇÃO! O semáforo está AMARELO.\n");
            break;
        case 3:
            printf("✅ SIGA! O semáforo está VERDE.\n");
            break;
    }

    return true; // Mantém o temporizador em execução
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    configurar_gpio(); // Configura os pinos GPIO dos LEDs

    // Configura um temporizador periódico para alternar os sinais do semáforo
    struct repeating_timer temporizador;
    add_repeating_timer_ms(INTERVALO_TROCA_SINAL, atualizar_semaforo, NULL, &temporizador);

    // Loop principal: imprime mensagem a cada 1 segundo
    while (true) {
        printf("🔵 Respeite a sinalização de trânsito!\n");
        sleep_ms(1000); // Aguarda 1 segundo antes de imprimir novamente
    }

    return 0; // O programa nunca chega aqui, pois o loop while é infinito
}
