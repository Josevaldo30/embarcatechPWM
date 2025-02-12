#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdint.h>
#include <stdbool.h>

#define SERVO_PIN 22
#define PWM_FREQ 50.0 // 50Hz para servomotor
#define DELAY_MS 10   // Atraso para suavizar o movimento
#define STEP_US 5      // Incremento do ciclo ativo
#define PWM_DIVISER 64.0f // Divisor de clock para estabilidade

// Função para configurar o PWM
void config_pwm(uint32_t slice, uint32_t channel, float duty_us, uint32_t wrap) {
    pwm_set_wrap(slice, wrap);
    pwm_set_chan_level(slice, channel, (uint32_t)((duty_us * wrap) / 20000));
    pwm_set_enabled(slice, true);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    
    uint32_t slice = pwm_gpio_to_slice_num(SERVO_PIN);
    uint32_t channel = pwm_gpio_to_channel(SERVO_PIN);
    uint32_t clock_freq = clock_get_hz(clk_sys);
    uint32_t wrap = (clock_freq / (PWM_DIVISER * PWM_FREQ)) - 1;
    
    // Configuração inicial do PWM
    pwm_set_clkdiv(slice, PWM_DIVISER);
    pwm_set_wrap(slice, wrap);
    pwm_set_enabled(slice, true);
    
    // Posicionar o servo em 180 graus
    config_pwm(slice, channel, 2400, wrap);
    sleep_ms(5000);
    
    // Posicionar o servo em 90 graus
    config_pwm(slice, channel, 1470, wrap);
    sleep_ms(5000);
    
    // Posicionar o servo em 0 graus
    config_pwm(slice, channel, 500, wrap);
    sleep_ms(5000);
    
    // Movimentação periódica suave entre 0 e 180 graus continuamente
    bool aumentando = true;
    uint32_t duty = 500;
    
    while (true) {
        pwm_set_chan_level(slice, channel, (uint32_t)((duty * wrap) / 20000));
        sleep_ms(DELAY_MS);
        
        if (aumentando) {
            duty += STEP_US;
            if (duty >= 2400) aumentando = false;
        } else {
            duty -= STEP_US;
            if (duty <= 500) aumentando = true;
        }
    }
}
