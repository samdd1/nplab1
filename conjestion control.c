// conjestion control


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUCKET_SIZE 10
#define RATE 1
#define INTERVAL 1

int main() {
    int bucket_size = BUCKET_SIZE;
    int rate = RATE;
    int interval = INTERVAL;
    int packets[BUCKET_SIZE];
    int packet_count = 0;

    // Initializing packets in the bucket
    for (int i = 0; i < bucket_size; i++) {
        packets[i] = 0;
    }

    // Sending packets to the network
    while (1) {
        sleep(interval);

        // Adding new packet to the bucket
        packets[packet_count++] = 1;
        printf("New packet added to the bucket.\n");

        // Checking if bucket is full
        if (packet_count == bucket_size) {
            printf("Bucket is full. Congestion control activated.\n");

            // Leaky bucket algorithm
            while (packet_count > 0) {
                printf("Packet sent to network.\n");
                packet_count--;
                sleep(rate);
            }
        }
    }

    return 0;
}
