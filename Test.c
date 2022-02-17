#include <stdio.h>

char students[4][10]  = 
    {
        "Jim",
        "Mike", 
        "Doug", 
        "Sam"
    };

int main() {
    for (int i = 0; i < 5; i++) {
        printf("%s", students[i]);
    }
}