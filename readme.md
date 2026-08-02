# 🐶 DeskDog

> **An open-source embedded systems project that explores software architecture, graphics, animation, and hardware abstraction by building an intelligent desktop companion.**

---

## 📖 Project Overview

DeskDog is an educational and engineering-focused embedded systems project that aims to build an expressive desktop companion while teaching professional firmware development practices.

The project begins with an **ESP32** and a **0.96" SSD1306 OLED display**, but it is intentionally designed to be **hardware-independent**. As the project evolves, the same software architecture should support different microcontrollers, displays, and peripherals with minimal changes to the application logic.

Rather than being just another ESP32 project, DeskDog is a long-term exploration of embedded software engineering, graphics programming, modular firmware architecture, and system design.

---

# 🎯 Mission

Build a portable embedded software platform that demonstrates professional firmware engineering while creating an interactive desktop companion capable of growing from a simple animated OLED pet into an intelligent assistant.

---

# 🌟 Vision

DeskDog is designed to evolve through multiple stages of development.

* 🐶 Animated pixel-art desktop companion
* 👀 Natural blinking and eye movement
* 😊 Emotion and behavior system
* 😴 Idle and sleep animations
* 🕒 Real-time clock with Wi-Fi synchronization
* 💻 Desktop companion integration
* 🔔 Computer notifications
* 🎤 Voice interaction (Future)
* 🤖 AI-powered conversations (Future)

---

# 🏛 Engineering Philosophy

DeskDog follows one fundamental engineering principle:

> **Changing hardware should require changing only the hardware-specific implementation—not the software architecture.**

The project emphasizes:

* Hardware Abstraction Layer (HAL)
* Layered Architecture
* Modular Design
* Separation of Responsibilities
* Object-Oriented Programming
* State Machines
* Event-Driven Programming
* Rendering Pipelines
* Clean Interfaces
* Maintainable Firmware

The goal is to write software that can evolve independently from the underlying hardware.

---

# 🧠 Learning Philosophy

DeskDog is also a learning project.

Every feature follows the same engineering workflow:

1. Understand the concept.
2. Learn why the concept exists.
3. Design the architecture.
4. Implement the solution.
5. Test the implementation.
6. Review and refactor when necessary.

The objective is not only to build a working device but also to understand the engineering principles behind every design decision.


---
# 🏗 High-Level Architecture

```text
Application
│
├── Dog
├── Clock
├── Notifications
└── Future AI
        │
        ▼
Behavior Engine
        │
        ▼
Animation Engine
        │
        ▼
Rendering Engine
        │
        ▼
Display Manager
        │
        ▼
Hardware Abstraction Layer (HAL)
        │
        ▼
ESP32 / STM32 / RP2040 / Raspberry Pi / Future Platforms
```

Every layer has a single responsibility and communicates only with the layer directly below it.

---

# 🚀 Development Roadmap

## Phase 1 — Foundation

* Project setup
* Development environment
* Display Manager
* Rendering Engine

## Phase 2 — Graphics

* Sprite Engine
* Bitmap rendering
* Pixel-art support

## Phase 3 — DeskDog

* Draw the first DeskDog
* Blink animation
* Eye movement
* Idle animation

## Phase 4 — Behavior

* State Machine
* Emotion System
* Sleep Mode
* Mood Engine

## Phase 5 — Connectivity

* Wi-Fi
* NTP Time Synchronization
* Desktop Communication
* Notifications

## Phase 6 — AI

* Conversational interactions
* Memory system
* Voice support
* Intelligent behavior

---

# 🔌 Current Hardware

* ESP32 DOIT DevKit V1
* 0.96" SSD1306 I²C OLED Display
* Breadboard
* Jumper wires
* USB Cable

---

# 🔮 Planned Hardware Support

The project architecture is designed to support multiple hardware platforms.

### Microcontrollers

* ESP32
* ESP32-S3
* STM32
* Raspberry Pi Pico W (RP2040)
* nRF52 Series

### Displays

* SSD1306 OLED
* SH1106 OLED
* ST7735 TFT
* ST7789 TFT
* Future Display Modules

### Additional Peripherals

* Speaker
* Microphone
* Touch Sensor
* Accelerometer
* RGB LEDs
* Battery Monitoring

Adding or replacing hardware should require changes primarily within the Hardware Abstraction Layer.

---

# 📂 Repository Structure

```text
DeskDog/
│
├── assets/          # Images, sprites, fonts, icons
├── docs/            # Engineering documentation
├── include/         # Header files
├── lib/             # External libraries
├── src/             # Source code
├── test/            # Unit tests
├── platformio.ini
└── README.md
```

---

# 📚 Documentation

The repository contains detailed documentation covering both engineering concepts and implementation.

Planned documentation includes:

* Project Vision
* Software Architecture
* Hardware Architecture
* Hardware Abstraction Layer
* Rendering Engine
* Animation System
* State Machine
* Development Workflow
* Project Roadmap

---

# 📜 Engineering Rules

DeskDog follows these engineering rules throughout development.

1. Application code never accesses hardware directly.
2. Hardware-specific code belongs only in the Hardware Abstraction Layer.
3. Each module should have a single responsibility.
4. Modules should communicate through well-defined interfaces.
5. Features should remain modular and reusable.
6. The software architecture should remain portable across hardware platforms.
7. Every architectural decision should have a documented engineering reason.

---

# 🤝 Contributing

Contributions, discussions, ideas, and improvements are always welcome.

Whether you're interested in embedded systems, firmware development, graphics programming, or software architecture, you're welcome to contribute.

---

# 📄 License

This project is currently under active development.

A suitable open-source license will be added before the first stable release.





