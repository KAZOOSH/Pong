# Pong
a simple yet advanced version of the classic pong. controlled with real paddles.

## Setup

Clone the repository on your local system. Download the 0.93 version of openFrameworks ([XCode](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_osx_release.zip) , [Visual Studio](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_vs_release.zip), [Linux](http://openframeworks.cc/versions/v0.9.3/of_v0.9.3_linux64_release.tar.gz)). Unpack the files in your repository.

Use the project generator to create a project for your IDE (```[project folder]/projectGenerator```). Import the folder ```apps/Pong/pong```and create a project out of it. Open the project in your IDE and compile.

##Development

###Playmode Concept
The Game is a container that executes a specific *Ruleset* that defines the physics of the game and a specific *Rendermode* that defines the visual aspects.

####Create a Playmode
..todo

####Playmodes Todo

#####Rules and Renderers
- [ ] Deflector Beam
- [ ] Blockout Mode
- [x] Walls
- [ ] Portals
- [ ] Shoot the ball Mode
- [ ] Anaglyph Gravity

#####Rules
- [x] Basic 
- [x] Multiball 
- [x] Double Speed 
- [ ] Gravity Mode
- [ ] Sticky Mode
- [ ] Multiball Explosion with Healthbar
- [x] Ball size 
- [x] Paddle size 
- [ ] crazy panel, panel reload

#####Renderers
- [x] Basic
- [x] Anaglyph
- [ ] Funny Background (or video)
- [ ] Tron
- [x] Round Ball
- [ ] LSD Mode
- [ ] Sonar Mode
- [ ] Table Tennis
- [ ] Womens Tennis
- [ ] Pokeball