# 🏛️ Software Architecture

## Purpose

The purpose of the DeskDog software architecture is to create a firmware platform that is modular, maintainable, portable, and easy to extend.

Rather than designing the project around a specific microcontroller or display, DeskDog is designed around software responsibilities. Hardware is treated as a replaceable implementation detail.

This approach allows the application to evolve independently of the underlying electronics.

---

# Design Goals

The software architecture is designed to satisfy the following goals:

* Hardware independent
* Modular
* Portable
* Easy to maintain
* Easy to test
* Easy to extend
* Easy to understand

Every design decision should support one or more of these goals.

---

# Layered Architecture

DeskDog follows a layered architecture.

```text
Application
│
▼
Core Logic
│
▼
Graphics & Rendering
│
▼
System Services
│
▼
Hardware Abstraction Layer
│
▼
Hardware
```

Each layer communicates only with the layer directly below it.

This minimizes coupling and keeps responsibilities well defined.

---

# Responsibilities

## Application

Coordinates the entire system.

Responsible for:

* System startup
* Initialization
* Main execution loop

---

## Core Logic

Contains DeskDog's behavior.

Examples:

* Personality
* Emotion System
* State Machine
* Decision Making

This layer must never communicate directly with hardware.

---

## Graphics & Rendering

Responsible for converting application requests into visual output.

Examples:

* Renderer
* Animation Engine
* Sprite System
* Display Manager

This layer should not contain business logic.

---

## System Services

Provides shared functionality to the application.

Examples:

* Clock
* Wi-Fi
* Desktop Communication
* Storage
* Audio

Services provide capabilities but do not make application decisions.

---

## Hardware Abstraction Layer (HAL)

The only layer that communicates directly with hardware.

Responsibilities include:

* GPIO
* I²C
* SPI
* Timers
* Display Drivers
* Board-specific initialization

Replacing the microcontroller should primarily require changes in this layer.

---

# Dependency Direction

Dependencies always point downward.

```text
Application
        │
        ▼
Core
        │
        ▼
Graphics
        │
        ▼
Services
        │
        ▼
HAL
        │
        ▼
Hardware
```

Lower layers must never depend on higher layers.

---

# Architectural Principles

DeskDog follows these principles throughout development:

1. Every module has a single responsibility.
2. Application logic must remain hardware independent.
3. Hardware-specific code belongs only in the HAL.
4. Components communicate through well-defined interfaces.
5. The architecture should remain stable even if the hardware changes.
6. Design decisions should be documented before implementation whenever practical.

---

# Future Evolution

The current architecture is intentionally simple.

As DeskDog grows, new modules can be added without changing the overall structure.

Possible future additions include:

* Audio Engine
* AI Engine
* Networking Stack
* Plugin System
* Desktop Companion Framework

These should integrate naturally into the existing layered architecture without requiring major redesign.
