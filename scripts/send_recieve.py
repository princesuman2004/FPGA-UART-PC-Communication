import serial
import struct

# Set to match FPGA's current AXI UARTLite baud rate
COM_PORT = 'COM3'
BAUD_RATE = 9600  # Changed from 115200 to 9600

try:
    ser = serial.Serial(COM_PORT, baudrate=BAUD_RATE, timeout=1)
    print(f"Connected to {COM_PORT} at {BAUD_RATE} baud.\n")
except serial.SerialException as e:
    print(f"Could not open {COM_PORT}: {e}")
    exit(1)

# Get user input
a = int(input("Enter first 32-bit unsigned integer (A): "))
b = int(input("Enter second 32-bit unsigned integer (B): "))

# Pack A and B into 8 bytes (little-endian)
packet = struct.pack('<II', a, b)
ser.write(packet)
print(f"Sent A={a}, B={b} as {packet.hex()}")

# Read up to 8 bytes from FPGA response
response = ser.read(8)

# Show results
if len(response) == 0:
    print("No response received from FPGA.")
else:
    print(f"Received {len(response)} byte(s): {response.hex()}")
    if len(response) == 8:
        result = struct.unpack('<Q', response)[0]
        print(f"Result from FPGA: {a} × {b} = {result}")
    else:
        print("Incomplete response — maybe partial TX from FPGA or UART timing issue.")

ser.close()
