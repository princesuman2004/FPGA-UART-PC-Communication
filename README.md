
# UART–PC Communication on ZCU104 via AXI UARTLite

This project enables communication between a **ZCU104 FPGA board** and a **PC** over UART using the AXI UARTLite IP core. The system multiplies two 32-bit unsigned integers sent from the PC, computes the product on the FPGA, and returns a 64-bit result.

---

## 🔧 Project Overview

- **Board:** ZCU104 (Zynq UltraScale+ MPSoC)
- **Interface:** AXI UARTLite
- **PC Side:** Python script (via `pyserial`)
- **Functionality:** Multiply two 32-bit unsigned integers and return the result
- **Data Encoding:** Little-endian (LSB first)

---

## 🛠️ Tools Used

| Tool        | Version              |
|-------------|----------------------|
| Vivado      | 2023.2 (or later)    |
| Vitis       | 2023.2 (or later)    |
| Python      | 3.8+ with `pyserial` |
| Hardware    | ZCU104 FPGA Board    |

---

## 📁 Project Structure

```

├── scripts/                  # Python script for serial communication
│   └── send\_receive.py
├── vivado project/          # Vivado design (ZCU104\_UART.xpr.zip)
├── vitis workspace/         # Vitis firmware workspace (ZCU104\_UART\_Vitis.ide.zip)
└── README.md                # Project description and instructions

````

---

## 🖼️ Block Diagram

![Block Diagram](https://github.com/user-attachments/assets/41b21503-878e-4212-bba2-0c2618f6626a)

### Key Components:

- `zynq_ultra_ps_e_0`: Zynq Processing System
- `axi_uartlite_0`: AXI UARTLite IP
- `axi_smc`: AXI SmartConnect
- `rst_ps8_0_100M`: Processor System Reset block

---

## 📤 Data Flow

1. **User inputs two integers** on the PC.
2. **Python script packs and sends** them as 8 bytes over UART.
3. **FPGA receives and unpacks** the data.
4. **FPGA multiplies** the inputs and sends back a 64-bit result.
5. **PC script unpacks and displays** the result.

---

## ▶️ How to Run

### 1. Setup Hardware

- Connect ZCU104 to PC via USB-UART.
- Make sure Vivado & Vitis design is built and programmed to the board.

### 2. Python Environment Setup

Install Python and `pyserial`:

```bash
pip install pyserial
````

### 3. Run Python Script

From the `scripts/` folder, run:

```bash
python send_receive.py
```

* Enter two unsigned 32-bit integers when prompted.
* You'll receive the 64-bit result back from the FPGA.

> ⚠️ Make sure to set the correct COM port in the script (e.g., `COM3`) and baud rate `9600`.

---

## 🧪 Example Test Cases

| A (Input) | B (Input) |     Result |
| --------: | --------: | ---------: |
|         3 |         5 |         15 |
|      1234 |      4321 |    5322114 |
|     65536 |     65536 | 4294967296 |

---

## 🎥 Demonstration

[https://github.com/user-attachments/assets/3c770a49-dc15-4ba2-9bae-485a01e4d926](https://github.com/user-attachments/assets/3c770a49-dc15-4ba2-9bae-485a01e4d926)

---

## 🚀 Future Enhancements

* Add **UART Interrupts** for efficient I/O
* Enable **DMA-based UART** transfer
* Integrate **custom PL logic** for other ALU operations
* Build **GUI (Tkinter/PyQt5)** for user-friendly control

---

## 👨‍💻 Author

**Prince Suman**
B.Tech, IIT Indore
Enthusiast in Computer Architecture, Digital Design, and Embedded Systems.

---

## 📜 License

This project is released under the [MIT License](https://opensource.org/licenses/MIT).

