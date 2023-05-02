//bytestuffing

#include <stdio.h>
#include <string.h>

int main() {
    int bytes_sent = 0;
    int frame_count = 0;
    char buffer[100];

    // loop to simulate sending frames
    while (1) {
        printf("Enter a frame to send (press q to quit): ");
        scanf("%s", buffer);

        if (strcmp(buffer, "q") == 0) {
            printf("Total bytes sent: %d\n", bytes_sent);
            break;
        }

        int frame_length = strlen(buffer);
        bytes_sent += frame_length;
        frame_count++;

        printf("Frame %d received (%d bytes): %s\n", frame_count, frame_length, buffer);
    }

    return 0;
}
