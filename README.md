
# UART–PC Communication on ZCU104 via AXI UARTLite

This project enables communication between a **ZCU104 FPGA board** and a **PC** over UART using AXI UARTLite IP. The system multiplies two 32-bit integers sent from the PC, processes them on the FPGA, and returns a 64-bit result.

---

## 🔧 Project Overview

- **Board:** ZCU104 (Zynq UltraScale+ MPSoC)
- **Interface:** AXI UARTLite
- **PC Side:** Python script or Tera Term
- **Functionality:** Multiply two 32-bit unsigned integers and return the result
- **Data Encoding:** Little-endian (LSB first)

---

## 📁 Tools Used

| Tool        | Version              |
|-------------|----------------------|
| Vivado      | 2023.2 (or later)    |
| Vitis       | 2023.2 (or later)    |
| Python      | 3.8+                 |
| Tera Term   | Latest Stable        |
| Hardware    | ZCU104 FPGA Board    |

---

## 🔌 UART Configuration (for Tera Term)

To correctly send and receive data via UART:

- **Baud Rate:** `9600`
- **Data Bits:** `8`
- **Parity:** `None`
- **Stop Bits:** `1`
- **Flow Control:** `None`
- **Terminal Settings:** Enable **Local Echo** (`Setup → Terminal → Local Echo`)

---

## 📦 Project Structure

```

├── scripts/                  # Python script for serial communication
├── vivado project/          # Vivado design (ZCU104_UART.xpr.zip)
├── vitis workspace/         # Vitis firmware workspace (ZCU104_UART_Vitis.ide.zip)
└── README.md                # Project description and instructions
```

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

1. **User inputs two integers** on PC (via Python or Tera Term).
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

## Demonstra

https://github.com/user-attachments/assets/3c770a49-dc15-4ba2-9bae-485a01e4d926



## 🚀 Enhancements (Future Scope)

- Add **UART Interrupts** for efficient I/O
- Enable **DMA-based UART** transfer
- Integrate **custom PL logic** for advanced operations
- Build **GUI (Python PyQt5/Tkinter)** for user-friendly control

---

## 👨‍💻 Author

**Prince Suman**  
B.Tech, IIT Indore  
Interested in Computer Architecture, Digital Design & Embedded Systems.

---

## 📜 License

This project is released under the [MIT License](https://opensource.org/licenses/MIT).

---
```

