/**
 * BR SmartGuia - Firmware
 * 
 * Autor: Gabriel Martins Ribeiro
 * Engenheiro Eletrônico - FCTE - UnB
 * 
 * Descrição: Este firmware controla os módulos do BR SmartGuia, incluindo
 * sensores, display OLED, matriz de LEDs e buzzers para assistência a 
 * pessoas com deficiência visual.
 * 
 * Data: 02/2025
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/binary_info.h"
#include "ssd1306.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "ws2818b.pio.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"

//declaracoes
#define LED_COUNT 25
#define LED_PIN 7         //matriz de LED
#define BUTTON_A_PIN 5    // Pino do Botão A
#define BUTTON_B_PIN 6    // Pino do Botão B

bool led_on = false;            // Estado da matriz de LEDs
const uint I2C_SDA_PIN = 14;    //display oled
const uint I2C_SCL_PIN = 15;    // Pino do clock (SCL) do barramento I2C

#define BUZZER_PIN_1 21  // Pino do primeiro buzzer
#define BUZZER_PIN_2 10  // Pino do segundo buzzer

#define TRIGGER_PIN 4   //sensor ultrassonico (trigger)
#define ECHO_PIN 9      //sensor ultrassonico (echo)

#define BUZZER_PIN 10   //buzzer B -bitdoglab

// Frequências das notas
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// Função para verificar o estado do botão com debounce
bool read_button(uint button_pin) {
    bool state = gpio_get(button_pin);
    sleep_ms(50); // Debounce delay
    return state == 0; // Retorna true se o botão estiver pressionado (pull-up)
}

// Estrutura para representar um pixel RGB
struct pixel_t {
    uint8_t G, R, B; // Valores de cor
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Alias para clareza

// Buffer de pixels que formam a matriz
npLED_t leds[LED_COUNT];
PIO np_pio;
uint sm;

// Inicializa a máquina PIO para controle da matriz de LEDs.
void npInit(uint pin) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0) {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);
    npClear();
}

// Atribui uma cor RGB a um LED com ajuste de brilho.
void npSetLEDWithBrightness(const uint index, const uint8_t r, const uint8_t g, const uint8_t b, float brightness) {
    // Limita o fator de brilho entre 0.0 e 1.0
    if (brightness < 0.0) brightness = 0.0;
    if (brightness > 1.0) brightness = 1.0;

    // Aplica o fator de brilho
    leds[index].R = (uint8_t)(r * brightness);
    leds[index].G = (uint8_t)(g * brightness);
    leds[index].B = (uint8_t)(b * brightness);
}

// Limpa o buffer de pixels.
void npClear() {
    for (uint i = 0; i < LED_COUNT; ++i)
        npSetLEDWithBrightness(i, 0, 0, 0, 1.0);
}

// Escreve os dados do buffer nos LEDs.
void npWrite() {
    for (uint i = 0; i < LED_COUNT; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

// Converte a posição da matriz para uma posição do vetor.
int getIndex(int x, int y) {
    if (y % 2 == 0) {
        return 24 - (y * 5 + x); // Linha par (esquerda para direita).
    } else {
        return 24 - (y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
    }
}

void setup() {
    stdio_init_all(); // Inicializa a comunicação serial

    gpio_init(BUTTON_A_PIN); // Inicializa o pino do Botão A
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN); // Define o pino do Botão A como entrada
    gpio_pull_up(BUTTON_A_PIN); // Ativa o pull-up interno

    gpio_init(BUTTON_B_PIN); // Inicializa o pino do Botão B
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN); // Define o pino do Botão B como entrada
    gpio_pull_up(BUTTON_B_PIN); // Ativa o pull-up interno
}

void loop() {
    // Verifica se o Botão A foi pressionado
    if (read_button(BUTTON_A_PIN)) { // Botão pressionado (pull-up)
        led_on = true; // Liga a matriz de LEDs
    }

    // Verifica se o Botão B está pressionado
    if (read_button(BUTTON_B_PIN)) { // Botão pressionado (pull-up)
        led_on = false; // Desliga a matriz de LEDs
    }
    
    // Atualiza a matriz de LEDs com base no estado
    if (led_on) {
        // Definindo a matriz de cores
        int matriz[5][5][3] = {
            {{15, 49, 10}, {15, 49, 10}, {15, 49, 10}, {15, 49, 10}, {15, 49, 10}},
            {{15, 49, 10}, {15, 49, 10}, {216, 241, 18}, {15, 49, 10}, {15, 49, 10}},
            {{15, 49, 10}, {216, 241, 18}, {18, 54, 241}, {216, 241, 18}, {15, 49, 10}},
            {{15, 49, 10}, {15, 49, 10}, {216, 241, 18}, {15, 49, 10}, {15, 49, 10}},
            {{15, 49, 10}, {15, 49, 10}, {15, 49, 10}, {15, 49, 10}, {15, 49, 10}}
        };

        float brightness = 0.05; // Definindo o brilho para 5%

        // Atualiza a matriz de LEDs com a intensidade de brilho desejada
        for (int linha = 0; linha < 5; linha++) {
            for (int coluna = 0; coluna < 5; coluna++) {
                int posicao = getIndex(coluna, linha); // Converte a posição da matriz para a posição do vetor
                npSetLEDWithBrightness(posicao, matriz[linha][coluna][0], matriz[linha][coluna][1], matriz[linha][coluna][2], brightness);
            }
        }
    } else {
        // Limpa a matriz de LEDs quando desligada
        npClear();
    }
    
        npWrite(); // Escreve os dados nos LEDs
    }

// começar musica (melodia e duração)
int melody[] = {
  

  // Asa branca - Luiz Gonzaga (https://musescore.com/user/190926/scores/181370)

  NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4, 
  NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4,

  NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
  NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,

  NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
  NOTE_G4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,

  NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
  NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
  NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,

  NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
  NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
  NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
  NOTE_G4,-2, REST,4

};

// Função para tocar uma nota
void play_tone(int frequency, int duration, int buzzer_pin) {
    if (frequency > 0) {
        // Configura o PWM
        gpio_set_function(buzzer_pin, GPIO_FUNC_PWM);
        uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);
        pwm_set_wrap(slice_num, 125000000 / frequency); // Ajusta o wrap para a frequência
        pwm_set_chan_level(slice_num, PWM_CHAN_A, 2600); // 100% de duty cycle
        pwm_set_enabled(slice_num, true);
        sleep_ms(duration);
        pwm_set_enabled(slice_num, false); // Desliga o PWM
    } else {
        sleep_ms(duration); // Pausa se for REST
    }
}

// Função para medir a distância
float ultrasonnic() {
    uint32_t timepassed = 0;

    // Enviar pulso de trigger
    gpio_put(TRIGGER_PIN, 0);
    sleep_us(2);
    gpio_put(TRIGGER_PIN, 1);
    sleep_us(10);
    gpio_put(TRIGGER_PIN, 0);

    // Esperar pelo pulso de echo
    while (gpio_get(ECHO_PIN) == 0);
    uint32_t signaloff = time_us_32();

    while (gpio_get(ECHO_PIN) == 1);
    uint32_t signalon = time_us_32();

    timepassed = signalon - signaloff;

    // Calcular a distância em cm
    float distance_cm = (timepassed * 0.0343) / 2; // Velocidade do som: 0.0343 cm/us
    return distance_cm;
}

// Função para tocar uma nota
void playTone(int frequency, int duration) {
    if (frequency > 0) {
        // Gera um sinal PWM para a frequência desejada
        gpio_put(BUZZER_PIN, 1);
        sleep_us(duration / 2);
        gpio_put(BUZZER_PIN, 0);
        sleep_us(duration / 2);
    } else {
        sleep_us(duration);
    }
}

// Função para tocar alarme
void playAlarm() {
    // Notas e durações do alarme
    int melody[] = {
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
        NOTE_B4, NOTE_B4, NOTE_B4, NOTE_E5,
    };

    int noteDurations[] = {
        300, 300, 300, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
    };

    // Toca a melodia
    for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
        playTone(melody[thisNote], noteDurations[thisNote]);
    }
}

//Main
int main() {

    // Inicializar GPIO I2C
    i2c_init(i2c1, 400 * 1000); // 400 kHz
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);

// Inicializar o display OLED
SSD1306_init();

// Inicializar área de renderização
struct render_area frame_area = {
    .start_col = 0,
    .end_col = SSD1306_WIDTH - 1,
    .start_page = 0,
    .end_page = SSD1306_NUM_PAGES - 1
};

calc_render_area_buflen(&frame_area);

    // Limpar o buffer do display
    uint8_t buf[SSD1306_BUF_LEN];
    memset(buf, 0, SSD1306_BUF_LEN);
    render(buf, &frame_area);

    memset(buf, 0, SSD1306_BUF_LEN);

    char *text[]={
        "Wellcome to    ",
        "BR SmartGuia! "};

        int y = 0;
        for (uint i = 0; i < count_of(text); i++)
        {
            WriteString(buf,5,y,text[i]);
            y += 8;
        }
        render(buf,&frame_area);

////comecar tocar luiz Gonzaga
gpio_init(BUZZER_PIN_1); // Inicializa o pino do primeiro buzzer
gpio_set_dir(BUZZER_PIN_1, GPIO_OUT); // Define o pino como saída
gpio_init(BUZZER_PIN_2); // Inicializa o pino do segundo buzzer
gpio_set_dir(BUZZER_PIN_2, GPIO_OUT); // Define o pino como saída

int wholenote = (60000 * 4) / 190; // Duração de uma nota inteira em ms (120 BPM)

for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote += 2) {
    int note = melody[thisNote];
    int duration = melody[thisNote + 1];

    int note_duration = (duration > 0) ? (wholenote / duration) : (wholenote / -duration * 1.5);
    
    // Toca a nota em ambos os buzzers ao mesmo tempo
    play_tone(note, note_duration * 0.9, BUZZER_PIN_1); // Toca no primeiro buzzer
    play_tone(note, note_duration * 0.9, BUZZER_PIN_2); // Toca no segundo buzzer
    
    sleep_ms(note_duration * 0.1); // Pausa de 10%
}

npInit(LED_PIN); // Inicializa a matriz de LEDs
npClear(); // Limpa a matriz
setup(); // Configura os pinos e inicializa
loop(); // Executa o loop principal

stdio_init_all();
gpio_init(TRIGGER_PIN);
gpio_set_dir(TRIGGER_PIN, GPIO_OUT);
gpio_init(ECHO_PIN);
gpio_set_dir(ECHO_PIN, GPIO_IN);

// Inicializar GPIO I2C
i2c_init(i2c1, 400 * 1000); // 400 kHz
gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
gpio_pull_up(I2C_SDA_PIN);
gpio_pull_up(I2C_SCL_PIN);

//inicializa GPIO Buzzer alarme
gpio_init(BUZZER_PIN);
gpio_set_dir(BUZZER_PIN, GPIO_OUT);


// Inicializar o display OLED
SSD1306_init();

    calc_render_area_buflen(&frame_area);

    // Limpar o buffer do display
    //uint8_t buf[SSD1306_BUF_LEN];
    memset(buf, 0, SSD1306_BUF_LEN);
    render(buf, &frame_area);

    while (true) {

        // Limpar o buffer
        memset(buf, 0, SSD1306_BUF_LEN);

        // Medir a distância
        float distance_cm = ultrasonnic();


        //inicio loop distancia-alarme (exibir a distância no display)
        char distance_text[20];
        snprintf(distance_text, sizeof(distance_text), "Distance: %.f cm", distance_cm);
        WriteString(buf, 5, 0, distance_text);

       
        //Calcula o tempo de espera baseado na distancia
        int sleepTime = 1000; // Tempo padrão de espera em milissegundos
  
        //fim loop distancia-alarme
        render(buf, &frame_area);

        // Verifica se a distância é menor que 15cm (10 cm ficou muito perto, considerando que o carrinho aponta p cima)
        if (distance_cm < 15) {
            playAlarm(); // Toca o alarme se a distância for menor que 10 cm
        } else {
            gpio_put(BUZZER_PIN, 0); // Desliga o buzzer se a distância for maior ou igual a 10 cm
        }

        loop(); // Executa o loop principal da matriz de LEDS

        sleep_ms(100);
    }

    return 0;
}