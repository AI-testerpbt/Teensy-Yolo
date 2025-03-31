Purpose: Ethical disclosure of an AI + USB hardware-based bypass that simulates undetectable input in real-time using Teensy 4.1.
This project demonstrates a stealth input bypass using external screen detection and USB HID spoofing. It operates entirely outside the game process. You can encrypted the receiver.py to it harder to be detected (In theory).
Users can rename the Teensy device to trusted hardware like Logitech USB Input, Razer Gaming Mouse, or any other generic name.

The system architecture:
- Uses screen capture (OBS / capture card)
- Runs an AI detection model (e.g., YOLO) to identify targets visually
- Sends simple commands ("Move: x,y) to a Teensy 4.1 via a receiver script
- Teensy translates these into native mouse inputs using "Mouse.h"
- No COM port communication is used beyond receiving data — Teensy appears as a standard USB HID device (mouse/keyboard), with no overlays, no memory access, and no injected processes.

How It Works
AI detects target via screen capture from OBS
Main code run in another laptop sends input to "teensy_receiver.py"
Receiver writes command (e.g., "Move:x,y") to Teensy serial
Teensy acts based on that with that like human if have enough delay.
All interactions are external and hardware-based. The system mimics real user behavior.

Use responsibly in secure and isolated environments.

This was my first project and developed entirely from scratch without any prior coding experience. After one month of learning and researching, I brought this idea to life with the help of ChatGPT. Thank you for your interest in my work!
