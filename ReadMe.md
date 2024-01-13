# R-TYPE [EPITECH PROJECT] [DOCUMENTATION]

<a href="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" alt="SFML">
        <img src="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-C%2B%2B-ff69b4" alt="C++">
        <img src="https://img.shields.io/badge/MADE%20WITH-C%2B%2B-ff69b4" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-CONAN-blueviolet" alt="Conan">
        <img src="https://img.shields.io/badge/MADE%20WITH-CONAN-blueviolet" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" alt="Cmake">
        <img src="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" /></a>
	
## Installation

**Linux:**
```chmod +x install.sh
./install.sh
```

## Norme Commit

_Git is a fast, scalable, distributed revision control system with an unusually rich command set that provides both high-level operations and full access to internals._

In order to keep things organized, here is the commit style we should try to respect. Doing so will not only clarify the changes we made with each commit, but also increase our capacity to summarize those changes.

- Commits have to be in english.
 
- Each commit should start with a square bracket enclosed key to declare the reason of the commit. Those keys can be found among those :
  ### [ADD] -- if you add files, features, and so on
  ### [FIX] -- if you were working on a bug or any form of default that you corrected 
  ### [DEL] -- if you removed files, features, assets, and so on
  ### [UP] -- if you change something without adding any features or content

Each commit should then be followed by a single line (around 50 characters) explaining basics of the changes. For instance, you can have messages such as "[ADD] Collision system".

## About R-Type
R-Type is a classic video game, often considered as one of the pillars of the horizontal shoot 'em up genre. Initially released in the 1980s, R-Type has gained a reputation for its challenging gameplay and innovative designs.

### Game Features

- **Genre:** Horizontal shoot 'em up.

- **Gameplay:** Players pilot a spacecraft known as the R-9A "Arrowhead", fighting through a series of levels infested by a hostile alien race known as the Bydo.

- **Innovation:** R-Type is famous for its difficulty, complex level design, and the use of an attachable module known as the "Force". This module can absorb enemy shots, detach to attack, and be upgraded with different weapons.

### Impact and Legacy

- **Popularity:** R-Type became known for its detailed animation, advanced graphics for its time, and intense challenge.

- **Legacy:** It has inspired many games in the shoot 'em up genre and remains a classic admired by retro game fans.

- **Continuity:** The game has had several sequels and re-releases on various platforms, maintaining a devoted fan base.

In this R-TYPE project, we aim to recreate the original experience of R-Type while introducing modern gameplay elements and network technology, allowing players to relive the classic in a contemporary context.

## General Project Information

**Binary Name:** r-type_server, r-type_client

**Language:** C++

**Build Tool:** cmake (+ optional package manager)

## R-TYPE Server and Client
### Server
- Manages the game logic.

- Multithreaded and non-blocking.

- Robust against client disconnections or crashes.

### Client
- Displays the game and manages player inputs.
  
- Executes certain parts of the game logic locally under the authority of the server.

### Game Protocol
- Binary protocol for client/server.
  
- Mainly uses UDP, TCP justified if necessary.
  
- Detailed documentation required.

### Game Engine
- Focus on decoupling systems: graphics, networking, game logic.
  
- Recommendations to explore patterns like Entity-Component-System.

### Gameplay
- The game must be playable, with key elements such as horizontal scrolling, spaceships, enemies, and missiles.

## Contributors
This project was realized thanks to the dedicated contributions of the following collaborators:

- Sacha Velasco
  
- Anthony Dacremont
  
- Maxime Pianezzi
  
- Valentin Migliaccio

## FAQ (Frequently Asked Questions)
### Q1: How do I start the R-TYPE server?

***A:*** To start the server, run ./r-type_server after following the installation instructions.

### Q2: What are the prerequisites for running the R-TYPE client?

***A:*** The client requires a Linux-compatible system with dependencies specified in the installation file. Also, ensure that your graphical environment is properly configured.

### Q3: How can I contribute to the project?

***A:*** Contributions are always welcome! Please refer to our section on contribution and development for detailed guidelines.

### Q4: Is the game playable in multiplayer?

***A:*** Yes, the game is designed to be played over a network with multiple players. Ensure that the server is running and accessible to the clients.


