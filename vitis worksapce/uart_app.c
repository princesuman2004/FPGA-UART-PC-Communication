#include "xparameters.h"
#include "xuartlite.h"
#include "xil_printf.h"
#include <stdint.h>

// Use the correct device ID for your AXI UARTLite IP
#define UART_DEVICE_ID XPAR_AXI_UARTLITE_0_DEVICE_ID

XUartLite UartLite;

int main() {
    int status;
    uint8_t recv_buf[8];
    uint8_t send_buf[8];

    // Initialize UARTLite with the correct device ID
    status = XUartLite_Initialize(&UartLite, UART_DEVICE_ID);
    if (status != XST_SUCCESS) {
        xil_printf("UART init failed!\r\n");
        return XST_FAILURE;
    }

    xil_printf("ZCU104 UART READY\r\n");


    xil_printf("UART Multiplier Ready. Using baud rate: %d\r\n", XPAR_AXI_UARTLITE_0_BAUDRATE);

    while (1) {
        // Wait for 8 bytes (2 x 32-bit)
        int received = 0;
        while (received < 8) {
            int bytes = XUartLite_Recv(&UartLite, &recv_buf[received], 8 - received);
            if (bytes > 0) {
                received += bytes;
            }
        }

        // Parse A and B (little-endian format)
        uint32_t A = (uint32_t)recv_buf[0] |
                    ((uint32_t)recv_buf[1] << 8) |
                    ((uint32_t)recv_buf[2] << 16) |
                    ((uint32_t)recv_buf[3] << 24);

        uint32_t B = (uint32_t)recv_buf[4] |
                    ((uint32_t)recv_buf[5] << 8) |
                    ((uint32_t)recv_buf[6] << 16) |
                    ((uint32_t)recv_buf[7] << 24);

        // Multiply (ensuring 64-bit result)
        uint64_t result = (uint64_t)A * (uint64_t)B;

        // Pack result into send buffer (little-endian)
        for (int i = 0; i < 8; i++) {
            send_buf[i] = (uint8_t)((result >> (8 * i)) & 0xFF);
        }

        // Send result back
        int sent = 0;
        while (sent < 8) {
            int bytes = XUartLite_Send(&UartLite, &send_buf[sent], 8 - sent);
            if (bytes > 0) {
                sent += bytes;
            }
        }
    }

    return 0;
}
