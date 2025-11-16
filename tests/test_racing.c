#include "racing.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_racer_init() {
    Racer racer;
    racer_init(&racer, 42, "TestRacer");
    
    assert(racer.id == 42);
    assert(strcmp(racer.name, "TestRacer") == 0);
    assert(racer.position == 0);
    assert(racer.speed == 100);
    
    printf("test_racer_init: PASSED\n");
}

void test_racer_update() {
    Racer racer;
    racer_init(&racer, 1, "Racer1");
    
    int initial_pos = racer_get_position(&racer);
    racer_update(&racer);
    int new_pos = racer_get_position(&racer);
    
    assert(new_pos == initial_pos + 100);
    
    printf("test_racer_update: PASSED\n");
}

void test_racer_get_position() {
    Racer racer;
    racer_init(&racer, 1, "Racer1");
    
    assert(racer_get_position(&racer) == 0);
    racer.position = 500;
    assert(racer_get_position(&racer) == 500);
    
    printf("test_racer_get_position: PASSED\n");
}

int main() {
    printf("Running tests...\n");
    
    test_racer_init();
    test_racer_update();
    test_racer_get_position();
    
    printf("\nAll tests passed!\n");
    return 0;
}
