/*
Solution Plan:
1. Implement a menu-driven program to allow users to:
   - Convert Celsius to Fahrenheit.
   - Convert Fahrenheit to Celsius.
   - Exit the program.
2. Define separate functions for each type of conversion.
3. Use a loop to keep the program running until the user chooses to exit.
*/

#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Main function
int main() {
    int choice;
    float temperature, convertedTemperature;

    do {
        // Display the menu
        printf("\n--- Temperature Converter System ---\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("Temperature in Fahrenheit: %.2f\n", convertedTemperature);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("Temperature in Celsius: %.2f\n", convertedTemperature);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
