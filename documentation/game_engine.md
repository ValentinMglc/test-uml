# Documentation of R-Type Game Engine Classes

## Introduction

This documentation provides an overview of the key classes and interfaces in the R-Type game engine. It covers interfaces for scenes, objects, and entities, as well as important classes for managing elements and scenes.

### 1. Scene Interfaces
#### 1.1. IScene Interface

The IScene interface defines methods for managing scenes in the game engine.

#### Methods:

```
initScene(): Initializes the scene.
displayScene(sf::RenderWindow &_window): Displays the scene in the specified window.
deleteElements(): Deletes elements from the scene.
manageEvent(sf::RenderWindow &_window): Manages events in the window.
updateScene(std::vector<std::string> _mapPlayer, std::vector<std::string> _mapObject, std::vector<std::string> _mapBullet, int _id): Updates the scene with the specified information.
...
```
### 1.2. IObjet Interface

The IObjet interface defines methods for managing objects in the game engine.

#### Methods:

```
getType(): Returns the type of the object.
getSprite(): Returns the sprite of the object.
getText(): Returns the text of the object.
setText(char new_char): Modifies the text of the object.
...
```
## 2. Important Classes
### 2.1. ManageElement Class

The ManageElement class is responsible for managing elements in the game engine.

#### Methods:

```
createObjet<T>(Args &&... args): Creates an object of type T.
createEntity<T>(Args &&... args): Creates an entity of type T.
createBullets<T>(Args &&... args): Creates bullets of type T.
createObstacles<T>(Args &&... args): Creates obstacles of type T.
displayObjets(sf::RenderWindow &_window): Displays objects in the specified window.
displayEntities(sf::RenderWindow &_window): Displays entities in the specified window.
deleteObjets(): Deletes objects.
```

### 2.2. ManageScene Class

The ManageScene class manages different scenes in the game.

#### Methods:

```
initialize(): Initializes the scene.
nextScene(): Switches to the next scene.
prevScene(): Switches to the previous scene.
initializeWindow(): Initializes the game window.
initializeMusic(): Initializes music.
renderScene(): Renders the current scene.
closeWindow(): Closes the game window.
...
```

## 3. Scene Interfaces
### 3.1. IScene Interface

The IScene interface defines methods for managing scenes in the game engine.

#### Methods:

```
initScene(): Initializes the scene.
displayScene(sf::RenderWindow &_window): Displays the scene in the specified window.
deleteElements(): Deletes elements from the scene.
manageEvent(sf::RenderWindow &_window): Manages events in the window.
updateScene(std::vector<std::string> _mapPlayer, std::vector<std::string> _mapObject, std::vector<std::string> _mapBullet, int _id): Updates the scene with the specified information.
...
```

### 3.2. IObjet Interface
The IObjet interface defines methods for managing objects in the game engine.

#### Methods:

```
getType(): Returns the type of the object.
getSprite(): Returns the sprite of the object.
getText(): Returns the text of the object.
setText(char new_char): Modifies the text of the object.
...
```