# Pong
a simple yet advanced version of the classic pong. controlled with real paddles.

## Setup

Clone the repository on your local system. Download the 0.93 version of openFrameworks ([XCode](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_osx_release.zip) , [Visual Studio](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_vs_release.zip), [Linux](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_linux64_release.tar.gz)). Unpack the files in your repository.

Use the project generator to create a project for your IDE (```[project folder]/projectGenerator```). Import the folder ```apps/Pong/pong```and create a project out of it. Open the project in your IDE and compile.

## Hotkeys
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

## Development

### Playmode Concept
The Game is a container that executes a specific *Ruleset* that defines the physics of the game and a specific *Rendermode* that defines the visual aspects.

#### Create a Playmode
..todo

#### Playmodes Todo

##### Rules and Renderers
- [ ] Deflector Beam
- [ ] Blockout Mode
- [x] Walls
- [x] Portals
- [ ] Shoot the ball Mode
- [ ] Anaglyph Gravity
- [x] Multiball 

##### Rules
- [x] Basic 
- [x] Double Speed 
- [x] Gravity Mode
- [ ] Sticky Mode
- [ ] Multiball Explosion with Healthbar
- [x] Huge Ball
- [x] Small Ball 
- [x] Small Paddle
- [x] Huge Paddle 
- [ ] crazy panel, panel reload
- [x] swerve ball

##### Renderers
- [x] Basic
- [x] Anaglyph
- [x] Animated Sprite Ball
- [x] GifBackground
- [x] Invisible Mode
- [ ] Tron
- [x] Round Ball
- [ ] LSD Mode
- [x] PSY Mode
- [ ] Sonar Mode
- [ ] Table Tennis
- [x] Tennis
- [ ] Pokeball

## Hardware

### Setup

#### Arduino Pins
|   |   |
|---|---|
| white  |  GND |
| brown  |  +5V |
| yellow  |  SCL , A5 |
| green  |  SDA , A4|	
