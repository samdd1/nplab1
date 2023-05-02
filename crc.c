//CRC 

#include <stdio.h>
#include <string.h>

// Function to perform CRC division
void performCRC(char data[], char divisor[], char result[]) {
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);

    // Append zeroes to data to match divisor length
    for (int i = 0; i < divisorLen - 1; i++) {
        data[dataLen + i] = '0';
    }
    data[dataLen + divisorLen - 1] = '\0';

    // Perform division
    for (int i = 0; i < dataLen; i++) {
        if (data[i] == '1') {
            for (int j = 0; j < divisorLen; j++) {
                data[i+j] = data[i+j] == divisor[j] ? '0' : '1';
            }
        }
    }

    // Copy remainder to result
    strncpy(result, data + dataLen, divisorLen - 1);
    result[divisorLen - 1] = '\0';
}

int main() {
    char data[100], divisor[100], result[100];

    // Prompt user to enter data and divisor
    printf("Enter data: ");
    scanf("%s", data);
    printf("Enter divisor: ");
    scanf("%s", divisor);

    // Perform CRC division
    performCRC(data, divisor, result);

    // Check if remainder is zero (i.e., no error)
    if (strcmp(result, "0") == 0) {
        printf("CRC Checksum: %s\n", result);
        printf("No error detected.\n");
    }
    else {
        printf("CRC Checksum: %s\n", result);
        printf("Error detected.\n");
    }

    return 0;
}
