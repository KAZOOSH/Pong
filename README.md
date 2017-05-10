# Pong
A simple yet advanced version of the classic pong. Controlled with real paddles.

Features:
- use real paddle controllers (todo tutorial for building them), mouse or any self made serial controller
- a lot of render and playmodes extend the classical Pong experience (PSY Mode, Gravity Mode)
- compatible with MacOS, Windows, Raspbian (or any system you may compile it for)

## Install from Binary

Use the [binary](https://github.com/KAZOOSH/Pong/releases) for your system and start Pong.

## Compile from source

Clone the repository on your local system. Download the 0.93 version of openFrameworks ([XCode](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_osx_release.zip) , [Visual Studio](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_vs_release.zip), [Linux](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_linux64_release.tar.gz)). Unpack the files in your repository.

Use the project generator to create a project for your IDE (```[project folder]/projectGenerator```). Import the folder ```apps/Pong/pong```and create a project out of it. Open the project in your IDE and compile.

## Settings

To control the game you have a bunch of hotkeys. For setting the playmodes you have to edit the corresponding xml (see below).

### Hotkeys
|   |   |
|---|---|
| show/hide Debug Information  | d |
| toggle PlayMode  | p  |
| toggle Fullscreen  | f  |
| save settings  |  s |
| load settings  |  a |
| toggle ModerationMode  | m  |
| toggle Warper  | w  |
| ball brightness velocity -+  | c,v  |
| min ball velocity -+  | i,o  |
| max ball velocity -+  | k,l  |
| paddle: pixel per LED -+ | LEFT,RIGHT  |
| paddle: paddle size -+  | -,+  |
| paddle: toggle debug mode  | #  |

### Settings playmodes
The playmodes you want to use can be set in ```data/playmodes.xml``` (MacOS ```[show bundle contents]/Resources/data/playmodes.xml```).

To activate a playmode use this scheme:

```xml
<playmode>name of the mode</playmode>
```

The following modes are currently supported:

```
Double Speed
Small Paddle
Big Paddle
Tiny Ball
Huge Ball
Gravity
Helium
Swerve
<!--> renderers <!-->
Anaglyph
Round Ball
PSY
Tennis
Trails
Movie
Invisible Ball
Goat Mode
Dalmatian
<!--> playmodes <!-->
Walls
Portals
Multiball
```



## Development

### Playmodes 
The Game is a container that executes a specific *Ruleset* that defines the physics of the game and a specific *Rendermode* that defines the visual aspects.

#### Create a Playmode
..todo

#### Playmode Ideas

##### Rules and Renderers
- Deflector Beam
- Blockout Mode
- Shoot the ball Mode
- Anaglyph Gravity

##### Rules
- Sticky Mode
- Multiball Explosion with Healthbar
- crazy panel, panel reload

##### Renderers
- Tron
- LSD Mode
- Sonar Mode
- Pokeball

## Hardware

### Setup

#### Arduino Pins
|   |   |
|---|---|
| white  |  GND |
| brown  |  +5V |
| yellow  |  SCL , A5 |
| green  |  SDA , A4|	
