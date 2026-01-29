# Pediatric Breathing Rate Machine

## Overview

This project was developed by a team of six students for an occupational therapist who works with pediatric patients experiencing anxiety and irregular breathing patterns.

The goal was to design a device that guides children through controlled breathing using **visual LED cues** and **haptic (vibration) feedback** traced along the outline of a hand.

The final design consisted of:
- A laser-cut acrylic hand mounted on a box enclosure
- Addressable NeoPixel LEDs tracing the hand outline
- A vibration motor for haptic feedback
- An Arduino-powered control system
- User-adjustable knobs to control breathing rate, LED colors, and vibration settings

Due to the COVID-19 pandemic (Jan 2020 – May 2020), the project transitioned fully online and a physical prototype was never manufactured. However, a complete digital simulation of the electronics and behavior was developed using CAD tools, TinkerCAD, and Wokwi.

---

## My Role — Embedded Systems Programming (Arduino / C++)

I was responsible for designing and implementing the Arduino code that controls:

- The LED breathing animation mapped to the physical hand layout
- Alternating inhale/exhale timing logic
- Integration of vibration feedback synchronized with the LEDs
- Mapping the physical LED wiring path into a programmable index array for accurate animation
- Timing control for adjustable breathing rates

This required understanding how NeoPixels are addressed by **data chain order** rather than physical placement, and building a custom index mapping (`handPath[]`) to correctly trace the anatomical shape of the hand in software.

---

## How It Works

1. A 3-LED white countdown prepares the patient to begin
2. LEDs move in groups of 5 along the hand:
   - **Green + vibration** → Inhale
   - **Blue** → Exhale
3. The sequence repeats across the entire hand outline
4. The device finishes with a full white illumination of the hand

This creates a guided breathing experience using both visual and haptic biofeedback.

---

## Project Files

| File | Description |
|-----|-------------|
| `BRM-LED-VIB.ino` | Arduino C++ code controlling LEDs and vibration |
| `Instruction Manual.docx` | Full build, assembly, and usage guide |
| `Final box pieces.DXF` | CAD files for laser-cut enclosure |
| `hand dxf.DXF` | CAD file for acrylic hand layout |
| `Final Arduino.PNG` | Wiring layout reference |

**Required Library:** Adafruit NeoPixel

---

## Live Simulation

Wokwi Demo:  
https://wokwi.com/projects/453890159644208129

This simulation demonstrates the complete LED breathing sequence and vibration logic.

---

## Technical Resources Used

- Adafruit NeoPixel Library📚
  https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use

- Wokwi Arduino Simulator
- TinkerCAD Circuits
- AutoCAD / DXF for enclosure design

---

## Future Improvements

- [ ] Physical prototype build
- [ ] Adjustable dial for breathing rate
- [ ] Adjustable color selection
- [ ] Switch to enable/disable vibration feedback
