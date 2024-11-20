#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 10 // game field size

// Konvertiert Buchstaben-Koordinate in Array-Index (A->0, B->1, etc.)
int convert_letter_to_index(char letter) {
    return toupper(letter) - 'A';
}

// Konvertiert Zahl-String in Array-Index (1->0, 2->1, etc.)
int convert_number_to_index(const char* number) {
    if (strlen(number) == 2 && number[0] == '1' && number[1] == '0')
        return 9;
    return number[0] - '1';
}

// Bestimmt die Größe des Schiffs an der gegebenen Position
int get_ship_size(char field[SIZE][SIZE], int x, int y) {
    int size = 0;
    
    // Check if ship is horizontal by looking right or left
    if ((x < SIZE - 1 && (field[x+1][y] == '#' || field[x+1][y] == 'X')) ||
        (x > 0 && (field[x-1][y] == '#' || field[x-1][y] == 'X'))) {
        // Count from current position to right
        for (int i = x; i < SIZE && (field[i][y] == '#' || field[i][y] == 'X'); i++) {
            size++;
        }
        // Count from position to left
        for (int i = x - 1; i >= 0 && (field[i][y] == '#' || field[i][y] == 'X'); i--) {
            size++;
        }
    }
    // Vertical ship
    else {
        // Count from current position down
        for (int i = y; i < SIZE && (field[x][i] == '#' || field[x][i] == 'X'); i++) {
            size++;
        }
        // Count from current position up
        for (int i = y - 1; i >= 0 && (field[x][i] == '#' || field[x][i] == 'X'); i--) {
            size++;
        }
    }
    return size;
}

// Konvertiert Schiffsgröße in Schiffstyp-String
const char* ship_size_to_string(int size) {
    switch (size) {
        case 5: return "Schlachtschiff";
        case 4: return "Kreuzer";
        case 3: return "Zerstörer";
        case 2: return "U-Boot";
        default: return "Unbekannt";
    }
}

// Prüft ob ein Schiff an der Position komplett zerstört wurde
int ship_is_destroyed(char field[SIZE][SIZE], int x, int y) {
    int hits = 0;
    
    // Check if ship is horizontal by looking right or left
    if ((x < SIZE - 1 && (field[x+1][y] == '#' || field[x+1][y] == 'X')) ||
        (x > 0 && (field[x-1][y] == '#' || field[x-1][y] == 'X'))) {
        // Count hits from current position to right
        for (int i = x; i < SIZE && (field[i][y] == '#' || field[i][y] == 'X'); i++) {
            if (field[i][y] == 'X') hits++;
        }
        // Count hits from position to left
        for (int i = x - 1; i >= 0 && (field[i][y] == '#' || field[i][y] == 'X'); i--) {
            if (field[i][y] == 'X') hits++;
        }
    }
    // Vertical ship
    else {
        // Count hits from current position down
        for (int i = y; i < SIZE && (field[x][i] == '#' || field[x][i] == 'X'); i++) {
            if (field[x][i] == 'X') hits++;
        }
        // Count hits from current position up
        for (int i = y - 1; i >= 0 && (field[x][i] == '#' || field[x][i] == 'X'); i--) {
            if (field[x][i] == 'X') hits++;
        }
    }
    
    return hits == get_ship_size(field, x, y);
}

// Berechnet die Anzahl der verbleibenden Schiffsteile
int calc_remained_ship_parts(char field[SIZE][SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] == '#') count++;
        }
    }
    return count;
}

void init_field(char field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            field[i][j] = '.';
}

void print_field(char field[SIZE][SIZE]) {
    printf("  ABCDEFGHIJ\n");
    for (int i = 0; i < SIZE; i++) {
        if (i == 9)
            printf("%d", i + 1);
        else
            printf("%2d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", field[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void read_ship_positions_from_input(char field[SIZE][SIZE]) {
    char input[10];
    while (1) {
        scanf("%s", input);
        if (input[0] == 'e') break;
        
        char x1_str[2] = {input[0], '\0'};
        char y1_str[3] = {0};
        int dash_pos = 0;
        
        // Position des Bindestrichs finden
        for (int i = 1; i < strlen(input); i++) {
            if (input[i] == '-') {
                dash_pos = i;
                break;
            }
            y1_str[i-1] = input[i];
        }
        
        char x2_str[2] = {input[dash_pos+1], '\0'};
        char y2_str[3];
        strcpy(y2_str, input + dash_pos + 2);
        
        int x1 = convert_letter_to_index(x1_str[0]);
        int y1 = convert_number_to_index(y1_str);
        int x2 = convert_letter_to_index(x2_str[0]);
        int y2 = convert_number_to_index(y2_str);
        
        if (x1 == x2) {  // Vertikales Schiff
            for (int y = y1; y <= y2; y++) {
                field[x1][y] = '#';
            }
        } else {  // Horizontales Schiff
            for (int x = x1; x <= x2; x++) {
                field[x][y1] = '#';
            }
        }
    }
}

void play_game(char field[SIZE][SIZE]) {
    char input[10];
    int total_shots = 0;
    int hits = 0;
    int game_ended = 0;
    
    while (!game_ended) {
        scanf("%s", input);
        if (input[0] == 'x') {
            printf("\nDas Spiel wurde beendet.\n\n");
            break;
        }
        
        total_shots++;
        char x_str[2] = {input[0], '\0'};
        int x = convert_letter_to_index(x_str[0]);
        int y = convert_number_to_index(input + 1);
        
        printf("%s ", input);
        
        if (field[x][y] == '#') {
            field[x][y] = 'X';
            hits++;
            
            if (ship_is_destroyed(field, x, y)) {
                int size = get_ship_size(field, x, y);
                const char* ship_type = ship_size_to_string(size);
                printf("Getroffen! %s wurde versenkt!\n", ship_type);
            } else {
                printf("Getroffen!\n");
            }
        } else if (field[x][y] == '.') {
            field[x][y] = 'O';
            printf("Fehlschuss!\n");
        }

        if (calc_remained_ship_parts(field) == 0) {
            printf("\nAlle Schiffe wurden versenkt\n\n");
            game_ended = 1;
        }
    }
}

void evaluate_and_print_results(char field[SIZE][SIZE]) {
    print_field(field);
    
    int total_hits = 0;
    int total_shots = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] == 'X') total_hits++;
            if (field[i][j] == 'X' || field[i][j] == 'O') total_shots++;
        }
    }
    
    int hit_percentage = total_shots > 0 ? (total_hits * 100) / total_shots : 0;
    printf("Trefferquote: %d%%\n", hit_percentage);
}

int main(int argc, char *argv[]) {
    char field[SIZE][SIZE];
    init_field(field);
    read_ship_positions_from_input(field);
    print_field(field);
    play_game(field);
    evaluate_and_print_results(field);
    return 0;
}