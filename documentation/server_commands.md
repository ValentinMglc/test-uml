# Documentation of R-Type Server Commands

## Introduction

This documentation details the network commands available for clients to interact with the R-Type game server. It is based on the datasReceive structure that uses binary serialization for communication.

## Command Format

Commands are sent as serialized data structures. Each command encapsulates an identifier and a payload :

```
struct datasReceive {
    std::string id;
    std::string payload;
};
```

## Command List

Here are the available commands and their functionality :

### 100 - Creation of a New Lobby
- Description: Creates a new lobby on the server.
- Payload: No payload required.
- Server Response: Confirmation of the lobby creation (200).

### 101 - Adding a Client
- Description: Adds a client to an existing lobby.
- Payload: ID of the lobby to which the client is to be added.
- Server Response: Confirmation of adding the client to the lobby (200) / Lobby full (401).

### 102 - Start game
- Description: Make the player ready to start the game, start the game if all players are ready.
- Payload: No payload required.
- Server Response: Confirmation of the player's readiness (200) / Start the game (201).

<!-- ### 103 - Start game with AI
- Description: Start the game filling the lobby with AI.
- Payload: No payload required.
- Server Response: Start the game (201). -->

### 104 - Start solo game
- Description: Start the game with only one player.
- Payload: No payload required.
- Server Response: Start the game (201).

### 200 - Moving Players
- Description: Moves a player in the game.
- Payload: Direction of movement as an integer (1: up, 2: down, 3: left, 4: right).
- Server Response: Confirmation of the player's movement (200) / Unauthorized (401).

### 201 - Spawning a Projectile
- Description: Creates a projectile in the game.
- Payload: Information on the position and direction of the projectile.
- Server Response: Confirmation of the projectile creation (200).

## Serialization Format

Commands must be serialized using Boost.Serialization and sent as binary strings. Example of serialization :

```
datasReceive data;
data.id = "101";
data.payload = "LobbyID";
std::ostringstream archive_stream;
boost::archive::binary_oarchive archive(archive_stream);
archive << data;
// Envoyer archive_stream.str() au serveur
```

## Error Handling

Server-side errors are communicated via specific error messages. Ensure these errors are appropriately managed in the client.