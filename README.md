
# UART–PC Communication on ZCU104 via AXI UARTLite

This project enables communication between a **ZCU104 FPGA board** and a **PC** over UART using AXI UARTLite IP. The system multiplies two 32-bit integers sent from the PC, processes them on the FPGA, and returns a 64-bit result.

---

## 🔧 Project Overview

- **Board:** ZCU104 (Zynq UltraScale+ MPSoC)
- **Interface:** AXI UARTLite
- **PC Side:** Python script
- **Functionality:** Multiply two 32-bit unsigned integers and return the result
- **Data Encoding:** Little-endian (LSB first)

---

## 📁 Tools Used

| Tool        | Version              |
|-------------|----------------------|
| Vivado      | 2023.2 (or later)    |
| Vitis       | 2023.2 (or later)    |
| Python      | 3.8+                 |
| Hardware    | ZCU104 FPGA Board    |

---

## 🔌 UART Configuration

To correctly send and receive data via UART:

- **Baud Rate:** `9600`
- **Data Bits:** `8`
- **Parity:** `None`
- **Stop Bits:** `1`
- **Flow Control:** `None`
- **Terminal Settings:** Enable **Local Echo** if using a terminal emulator with echo off

---

## 📦 Project Structure

```

├── scripts/                  # Python script for serial communication
├── vivado project/           # Vivado design (ZCU104\_UART.xpr.zip)
├── vitis workspace/          # Vitis firmware workspace (ZCU104\_UART\_Vitis.ide.zip)
└── README.md                 # Project description and instructions

````

---

## 🖼️ Block Diagram

![image](https://github.com/user-attachments/assets/41b21503-878e-4212-bba2-0c2618f6626a)

### Key Components:

- `zynq_ultra_ps_e_0`: Zynq Processing System
- `axi_uartlite_0`: AXI UARTLite IP
- `axi_smc`: AXI SmartConnect
- `rst_ps8_0_100M`: Processor System Reset block

---

## 📤 Data Flow

1. **User inputs two integers** on PC (via Python).
2. **PC packs them into 8 bytes** and sends via UART.
3. **FPGA receives** the data, unpacks it, and computes the product.
4. **FPGA sends back** 8 bytes representing the 64-bit result.
5. **PC receives and displays** the final result.

---

## 🧪 Testing Example

| A (Input) | B (Input) | Result          |
|----------:|----------:|----------------:|
| 3         | 5         | 15              |
| 1234      | 4321      | 5322114         |
| 65536     | 65536     | 4294967296      |

---

## 📌 FPGA Constraints (XDC Mapping)

These constraints connect the AXI UARTLite signals to PMOD pins (ZCU104) for UART communication via USB-TTL.

```tcl
## UART TX and RX Pin Mapping
set_property PACKAGE_PIN G8 [get_ports uart2_pl_txd]
set_property PACKAGE_PIN G6 [get_ports uart2_pl_rxd]

## I/O Standard
set_property IOSTANDARD LVCMOS33 [get_ports uart2_pl_rxd]
set_property IOSTANDARD LVCMOS33 [get_ports uart2_pl_txd]
````

> 💡 **Note:** These map to **PMOD header JA** on ZCU104. Ensure the USB-TTL adapter’s TX and RX are connected crosswise (PC TX → FPGA RX, PC RX ← FPGA TX).

---

## 🚀 How to Run

1. Connect the **USB-TTL adapter** to the PMOD header (JA) on the ZCU104 board using the above pin mapping.
2. Power on the ZCU104 board and program the FPGA using Vivado with the provided bitstream.
3. On your PC, connect the USB-TTL adapter to a USB port.
4. Run the Python script located in `scripts/` folder:

   ```bash
   python uart_communication.py
   ```
5. Input two unsigned 32-bit integers when prompted.
6. The script will send these to FPGA, receive the 64-bit product, and print the result.

---

## 👨‍💻 Author

**Prince Suman**
B.Tech, IIT Indore
Interested in Computer Architecture, Digital Design & Embedded Systems.

---

## 📜 License

This project is released under the [MIT License](https://opensource.org/licenses/MIT).

---

