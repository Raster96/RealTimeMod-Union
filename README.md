# RealTimeMod-Union

RealTimeMod-Union is a Union plugin for Gothic II that synchronizes the in-game time with the system clock. Time in the game flows in real time (1 second in game = 1 second in real life).

## Features

- **Real-time synchronization**: Game time matches your system clock
- **Clock display**: Optional in-game clock display (configurable)
- **Multi-engine support**: Compatible with Gothic II Classic and Gothic II Night of the Raven

## Installation

1. Download the latest release from [Releases](https://github.com/Raster96/RealTimeMod-Union/releases/tag/v1.0.0)
2. Copy the compiled `RealTimeMod-Union.vdf` to your Gothic II\Data\Plugins folder
3. Make sure you have Union installed and properly configured
4. The plugin will be loaded automatically by Union

## Configuration

The plugin can be configured through the Gothic.ini file:

```ini
[RealTimeMod]
showClock=1  ; Set to 0 to disable the in-game clock display
```

## Building

### Prerequisites

- Visual Studio 2019 or later
- Union SDK with ZenGin headers
- Gothic II installation

### Build Steps

1. Clone this repository
2. Copy the ZenGin folder from Union SDK to the project directory
3. Open `RealTimeMod.sln` in Visual Studio
4. Select the appropriate configuration (G2 MT Release or G2A MT Release)
5. Build the solution

The compiled DLL will be output to the `Bin/` directory.

## How It Works

The plugin intercepts the game's time system and:
1. Scales the game time to match real-time flow
2. Periodically synchronizes with the system clock to prevent drift
3. Optionally displays the current time in the game interface

## Compatibility

- **Gothic II Classic**: Fully supported
- **Gothic II Night of the Raven**: Fully supported
- **Gothic I**: Not supported (different time system)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.