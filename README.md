# LCD Clock as a Qt Widget

A lightweight desktop digital clock built with **Qt Widgets (C++23)**.
The app shows the current local time in a frameless, always-on-top LCD-style window and lets users customize the display color.

<img src="./images/app_view.jpg" alt="View of the application" width="30%" height="30%" />

---

## What the clock does

The application provides a compact, always-visible time widget for the desktop:

- Shows the current local time in `hh:mm` format.
- Blinks the separator (`:`) once per second (visual pulse effect).
- Runs in a **frameless** window with **transparent background** and **always-on-top** behavior.
- Persists user preferences and window geometry between runs.

---

## User-facing functionality (use cases)

### 1. Quick time glance while working
A user keeps the widget on top of other windows to see the current time without switching apps.

### 2. Positioning the clock freely
A user can drag the widget with the mouse and place it anywhere on the desktop.

### 3. Customizing color for readability/theme
A user opens the context menu and chooses **Preferences** to set a preferred clock color (White, Green, Red, Dark Blue, Black).

### 4. Persistent setup across restarts
A user closes and reopens the app and gets:
- the same window position/state,
- the previously selected color.

### 5. Fast exit
A user opens the context menu and selects **Exit**.

---

## Architecture check: Is MVC still a good fit?

Short answer: **Yes, the current architecture is still sensible for this project size.**

### Current mapping
- **Model**: `ClockSettingsModel`
  - stores and loads persistent settings (currently color) via `QSettings`.
- **View**: `MainWindow` + `main_window.ui`, and `PreferenceDialog`
  - render UI elements and collect user interaction.
- **Controller / Application logic**: `LcdClock`
  - updates time every second,
  - applies color changes to the display,
  - opens the preferences dialog and writes back to the model.

### Why this is appropriate
- Responsibilities are already separated clearly enough.
- Display logic is not mixed into persistence logic.
- UI classes stay mostly focused on interaction/layout.
- For a small widget app, this keeps complexity low and maintainability good.

### Optional improvements (if the project grows)
- Move dialog orchestration out of `LcdClock` into a dedicated UI controller if settings become more complex.
- Introduce a dedicated view wrapper for `QLCDNumber` if multiple clock views are needed.
- Extend `ClockSettingsModel` with validation (e.g., default fallbacks for unknown values).

---

## Project structure and file responsibilities

### Build and entry
- `CMakeLists.txt`  
  Build configuration (Qt discovery, target definition, source list, install rules).
- `main.cpp`  
  Application entry point; initializes `QApplication`, organization/app name, and shows `MainWindow`.

### Main window (View shell)
- `main_window.h` / `main_window.cpp`  
  Main frameless window, drag behavior, context menu, app close handling, and geometry/state persistence.
- `main_window.ui`  
  Qt Designer UI definition for the main window and embedded LCD widget.

### Clock logic (Controller)
- `lcd_clock.h` / `lcd_clock.cpp`  
  Core clock behavior: timer-driven display updates, blinking separator, applying selected color, opening preferences dialog.

### Settings (Model)
- `clock_settings_model.h` / `clock_settings_model.cpp`  
  Persistent user settings model (clock color), including `QSettings` load/save and change notification signal.

### Preferences dialog (View)
- `preference_dialog.h` / `preference_dialog.cpp`  
  Modal settings dialog with color selection and OK/Cancel handling.

### Utility
- `enum_index.h`  
  Small template helper for enum-to-index conversion (currently generic utility).

### Assets and metadata
- `images/app_view.jpg`  
  Screenshot of the running application.
- `images/ide_view.jpg`  
  IDE/project screenshot.
- `LICENSE`  
  MIT license.

---

## Build and run

### Requirements
- CMake >= 3.16
- C++23 compiler
- Qt Widgets (Qt5 or Qt6)

### Typical build steps
```bash
cmake -S . -B build
cmake --build build
./build/qt_widget_clock
```

> On multi-config generators (e.g., Visual Studio), run the executable from the selected configuration folder.

---

## License

This project is licensed under the terms of the [MIT License](https://opensource.org/licenses/MIT).
