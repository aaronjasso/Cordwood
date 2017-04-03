# Cordwood
An Arduino library for LED animations on the Boldport Club's Cordwood Puzzle

![Cordwood with Tap and The Cuttle](https://raw.githubusercontent.com/aaronjasso/Cordwood/master/extras/IMAG0219.jpg)
See it in action at https://www.youtube.com/watch?v=W2H-fwwVL6s

### Introduction
This library is intended for use with [The Cordwood Puzzle](http://www.boldport.com/products/cordwood-puzzle-second-edition/) from [The Boldport Club](http://www.boldport.club/). Optionally, [The Cuttle](https://twitter.com/Atmel/status/766334685073006592?s=09) may be used in place of an Arduino Uno. In the Tap example, another Boldport project [The Tap](http://www.boldport.com/products/the-tap/) may be used for input.

Functionally, the Cordwood Puzzle is an arrangement of six LEDs that are all lit when the board is powered. A six-pin header allows each LED to be turned off individually when its corresponding control pin is pulled low. This library utilizes the control pins to create some rudimentary animations with the LEDs.

Note: I'm new to github and this is my first library. Comments and pull requests are welcome!

### Object
The Cordwood object is constructed using six arguments. They are the Arduino pins hooked up to the Cordwood's six-pin header and are input in the following order: LeftTop, LeftMiddle, LeftBottom, RightBottom, RightMiddle, RightTop. Place the constructor before the `void setup()` section.

Example:
```
Cordwood cw(4, 5, 7, 8, 12, 10);
```

If you hold the assembled Cordwood puzzle such that the board with the six-pin header is furthest from you and the header is pointing down, the pins will be in order from left to right.

### Methods
Currently, three animations are supported. Each has a single argument for the speed of the animation. Accepted inputs are the integers 1 - 5.
* `chase (speed)`
  -A single lit LED moves around in a circle
* `wheel (speed)`
  -A pair of opposite lit LEDs move around in a circle
* `bounce (speed)`
  -LEDs on both sides appear to bounce up and down

Lastly, the `allOff()` and `allOn()` functions are provided to darken or illuminate all the LEDs at once.

See the example files for more information. Happy coding!


